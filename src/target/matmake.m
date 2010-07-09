function [ result ] = matmake(varargin)
%MATMAKE Summary of this function goes here
%   Detailed explanation goes here

%% Argument parsing and setup

if (nargin == 0)
    state = read_matmakefile('Matmakefile');
    target = state.rules(1).target;
elseif (nargin == 1)
    target = varargin{1};
    state = read_matmakefile('Matmakefile');
elseif (nargin == 2)
    target = varargin{1};
    state = read_matmakefile(varargin{2});
else
    error 'matmake: Wrong number of input arguments';
end

%% Make the target
result = make(target, state);
switch (result)
    case -1
        error('matmake: No rule found for target %s', target);
    case 0
        disp(sprintf('Nothing to be done for target %s', target));
    case 1
        disp(sprintf('Target %s successfully built', target));
end
end %function

%% Private functions %%

function success = make(target, state)
    % see if we have a rule to make the target
    target_rules = find_matching_rules(target, state);
    if (isempty(target_rules))
        % We don't know how to make it; ensure it exists:
        file = dir(target);
        if (isempty(file))
            success = false;
        else
            success = true;
        end
        return;
    end
    
    if(length(target_rules) == 1)
        target_rule = target_rules;
    else
        % TODO: coalesce multiple rules; ensure only one non-implicit command
        % set and merge deps.
        error('matmake: Multiple rules for one target not yet supported'); %TODO
    end
    
    newest_dependent_timestamp = 0;
    for i=1:length(target_rule.deps)
        % Recursively make all the dependents
        status = make(target_rule.deps{i}, state);
        if (~status)
            error('matmake: No rule to build %s as required by %s', target_rule.deps{i}, target);
        end
        
        % Ensure the dependent exists and check its timestamp
        file = dir(target_rule.deps{i});
        if (isempty(file))
            error('matmake: File %s not found as required by %s', target_rule.deps{i}, target);
        end
        newest_dependent_timestamp = max(newest_dependent_timestamp, file.datenum);
    end
    
    target_timestamp = -1;
    file = dir(target);
    if (~isempty(file))
        target_timestamp = file.datenum;
    end
    
    
    if (target_timestamp < newest_dependent_timestamp)
        for i = 1:length(target_rule.commands)
            disp(target_rule.commands{i});
            eval(target_rule.commands{i});
        end
    end
    
    success = true;
end

function state = read_matmakefile(path)
    fid = fopen(path);
    
    % Parse all variables
    state.vars = struct();
    line = fgetl(fid);
    while (ischar(line))
        line = strip_comments(line);
        
        % Check for an immediate := assignment
        variable = regexp(line, '^\s*([A-Za-z]\w*)\s*:=\s*(.*)\s*$', 'tokens', 'once');
        if (length(variable) == 2)
            fldnm = variable(1); % not allowed to do variable(1){1} !?
            state.vars.(fldnm{1}) = expand_vars(variable(2), state.vars);
        end
        line = fgetl(fid);
    end
    frewind(fid);
    
    % Parse all rules
    state.rules = [];
    line = fgetl(fid);
    while (ischar(line))
        line = strip_comments(line);
        
        % Check for a : that's missing the =
        rule = regexp(line, '^\s*(\S+)\s*:(?!=)(.*)$', 'tokens', 'once');
        if (length(rule) >= 1)
            loc = length(state.rules)+1;
            state.rules(loc).target = expand_vars(rule(1), state.vars);
            state.rules(loc).deps = strread(expand_vars(rule(2), state.vars),'%s');
            
            % And check the next line for a rule
            line = fgetl(fid);
            state.rules(loc).commands = {};
            while (ischar(line) && ~isempty(regexp(line, '^(\t|\s\s\s\s)', 'once')))
                cmdloc = length(state.rules(loc).commands)+1;
                state.rules(loc).commands{cmdloc} = strtrim(line);
                line = fgetl(fid);
            end
        else
            line = fgetl(fid);
        end
    end
    
    % cleanup
    fclose(fid);
end

function out = strip_comments(str)
    loc = strfind(str, '#');
    if(loc)
        out = str(1:loc(1)-1);
    else
        out = str;
    end
end

function out = expand_vars(value, vars)
    if (iscell(value))
        value = value{1};
    end
    
    [startIndex, endIndex, tokIndex, matchStr, tokenStr, exprNames, splitStr] = regexp(value, '\$[{(]([A-Za-z]\w*)[})]'); % TODO: Disallow ${ASDF)

    if (startIndex)
        out = '';
        for i=1:length(startIndex)
            if (isfield(vars,tokenStr{i}))
                fldnm = tokenStr{i};
                replStr = vars.(fldnm{1});
            else
                replStr = '';
            end
            out = strcat(out, splitStr{i}, replStr);
        end
        out = strcat(out, splitStr{i+1});
    else
        out = value;
    end
end

function out = expand_auto_vars(cmds, ruleset, pattern)
    all_deps = strcat(ruleset.deps, {' '});
    all_deps = all_deps{:};
    
    unique_deps = str_unique(ruleset.deps);
    cmds = regexprep(cmds, '(\$@|\$\{@\}|\$\(@\))', ruleset.target);
    cmds = regexprep(cmds, '(\$<|\$\{<\}|\$\(<\))', ruleset.deps{1});
    cmds = regexprep(cmds, '(\$^|\$\{^\}|\$\(^\))', unique_deps);
    cmds = regexprep(cmds, '(\$+|\$\{+\}|\$\(+\))', all_deps);
    cmds = regexprep(cmds, '(\$*|\$\{*\}|\$\(*\))', pattern);
    
    out = cmds;
end

function out = str_unique(cell_arry)
    out = char(cell_arry) + 0;
    out = cellstr(char(unique(out, 'rows')));
end

function out = find_matching_rules(target, state)
    out = [];
    target = strtrim(target);
    for i=1:length(state.rules)
        regex = regexptranslate('escape', state.rules(i).target);
        regex = strcat('^', regex, '$');
        is_implicit = false;
        matched = false;
        pattern = [];
        if (strfind(regex, '%'))
            is_implicit = true;
            regex = strrep(regex, '%', '(\S+)');
            result = regexp(target, regex, 'tokens', 'once');
            if (~isempty(result))
                matched = true;
                pattern = result{1};
            end
        else
            matched = regexp(target, regex, 'once');
        end
        if (matched)
            loc = length(out) + 1;
            out(loc).implicit = is_implicit;                               %#ok<AGROW>
            out(loc).target = strrep(state.rules(i).target, '%', pattern); %#ok<AGROW>
            out(loc).deps = strrep(state.rules(i).deps, '%', pattern);     %#ok<AGROW>
            out(loc).commands = expand_auto_vars(state.rules(i).commands, out(loc), pattern); %#ok<AGROW>
        end
    end
end

