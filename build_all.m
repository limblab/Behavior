% calls mex on all c files
% $Id$

% define dependencies
T = {...
    {'center_out.dlm', 'mastercon_co.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'random_walk.dlm', 'mastercon_rw.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'ball_drop.dlm', 'mastercon_bd.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'forced_choice.dlm', 'mastercon_fc.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'bump_stim.dlm', 'mastercon_bs.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'multi_gadget.dlm', 'mastercon_mg.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'wrist_flexion.dlm', 'mastercon_wf.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'} ...
};

% update the version numbers in words.h
perl('update_version.pl');

% build the project
try
    build(T, 'all', true);
catch
end

% cleanup
try 
    delete('words.h');
    movefile('_words.h', 'words.h', 'f');
catch
end
