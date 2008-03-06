% calls mex on all c files
% be careful, dependencies are not working yet

tic;
disp('Build Started')

% s-functions
cfiles = { ...
    'Byte2Bits',    ...
    'serPos',       ...
    'mastercon_bs', ...
    'mastercon_co', ...
    'mastercon_fc', ...
    'mastercon_rw'  ...
};

% RTW models
rtwfiles = {         ...
    'bump_stim',     ...
    'center_out',    ...
    'forced_choice', ...
    'random_walk'    ...
};

% build s-functions
for i = 1:length(cfiles)
    build = 0;
    
    filename = strcat(cfiles(i), '.c');
    filename = filename{1};
    filedate = dir(filename);
    filedate = filedate.datenum;
    
    compname = strcat(cfiles(i), '.mexw32');
    compname = compname{1};
    compdate = dir(compname);
    if (~isempty(compdate))
        compdate = compdate.datenum;
        if (filedate > compdate)
            build = 1;
        end 
    else 
        build = 1;
    end
    
    if (build)
        disp(['building: ' filename]);
        mex(filename);
    else
        disp(['skipped:  ' filename]);
    end
end

% build models
for i = 1:length(rtwfiles)
    build = 0;
    
    filename = strcat(rtwfiles(i), '.mdl');
    filename = filename{1};
    filedate = dir(filename);
    filedate = filedate.datenum;
    
    compname = strcat(rtwfiles(i), '.dlm');
    compname = compname{1};
    compdate = dir(compname);
    if (~isempty(compdate))
        compdate = compdate.datenum;
        if (filedate > compdate)
            build = 1;
        end 
    else 
        build = 1;
    end
    
    if (build)
        disp(['building: ' filename]);
        filename = rtwfiles(i);
        filename = filename{1};
        rtwbuild(filename);
    else
        disp(['skipped:  ' filename]);
    end
end

toc;

