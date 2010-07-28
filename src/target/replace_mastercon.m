function replace_mastercon(target, model_branch, mastercon_xx, param_list)
% Takes the target ('modelBranch_xx.dlm'), the model branch ('model.mdl'),
% and the mastercon c-file ('mastercon_xx.c') as input. Replaces the
% mastercon file as well as the associated parameters in the .mdl and saves
% the new .mdl ('modelBranch_xx.mdl') as an intermediate file before
% compiling it with 'rtwbuild'.


bhvr_code  = ' XX'; %initialize
sfun       = 'Behavior'; %s-function block name

model_name = remove_extension(model_branch);
sblock     = strcat( model_name, '/', sfun, bhvr_code ); %outputs 'model_name/Behavior XX' where 'model_name' is 'robot', etc.

bhvr_code  = param_list(end-2:end); %2-letter behavior code and preceding space is stored in the param_list listed in 'Matmakefile'
param_list = param_list(1:end-3); %don't actually want the behavior code in the parameters list at build time

block_name = strcat( sfun, bhvr_code ); %name of the new s-block
bhvr_code  = lower(strtrim( bhvr_code )); %remove leading space from code, make lowercase
new_name   = strcat(model_name,'_',bhvr_code,'.mdl'); %intermediate .mdl file: 'model_xx.mdl', which is what is built into the target .dlm

%first make sure we're going to make a model that matches the intended
%target
if regexp( remove_extension(new_name), remove_extension(target) )

    open_system(model_branch);
    handle = get_param(sblock,'Handle');
    set_param(handle, 'FunctionName', mastercon_xx);
    set_param(handle, 'Parameters', param_list);
    set_param(handle, 'Name', block_name);
    save_system(model_branch, new_name); %'Save As...'
    close_system(new_name);
    %Do we also need a 'close_system(model_name)'? I'm guessing that will no
    %longer be an open window with the above save-as, so we shouldn't
   
else
    sprintf('Filename "%s" does not match target name "%s"', new_name, target)
    return;
end



%% Internal Function

%Outputs the input filename minus the extension
function nom_sans_fin = remove_extension(filename)

    %assumes there should be a maximum of one period in 'filename'
    if (regexp(filename,'\.'))
        dot = regexp(filename,'\.');
        if (length(dot) > 1)
            sprintf('Warning: model name "%s" in incorrect format',filename)
            return;
            %are there better ways of handling this? pretend the last dot
            %precedes the extension? or the first dot? whichever way is
            %better, this shouldn't be an issue (all file names in use come
            %from 'Matmakefile')
        end
        nom_sans_fin = filename(1:dot-1);
    else
        nom_sans_fin = filename; %simply returns input if no periods are found
    end


    
    
    
