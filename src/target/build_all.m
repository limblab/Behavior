% calls mex on all c files
% $Id$

% define dependencies
T = {...
   {'ball_drop.dlm', 'mastercon_bd.mexw32', 'Byte2Bits.mexw32'}, ...
   {'bump_choice.dlm', 'mastercon_bc.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
   {'bump_follow.dlm', 'mastercon_bf.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
   {'bump_stim.dlm', 'mastercon_bs.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
   {'center_out.dlm', 'mastercon_co.mexw32', 'serPos.mexw32','Byte2Bits.mexw32'}, ...
   {'forced_choice.dlm', 'mastercon_fc.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
   {'multi_gadget.dlm', 'mastercon_mg.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'} ...
   {'random_walk.dlm', 'mastercon_rw.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
   {'visual_search.dlm', 'mastercon_vs.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
   {'wrist_flexion.dlm', 'mastercon_wf.mexw32', 'Byte2Bits.mexw32'} ...
   {'two_alternative.dlm', 'mastercon_2afc.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}
};
% T = {'uncertainty.dlm', 'mastercon_un.mex32w','serPos.mex32w','Byte2Bits.mex32w'};
%     {'center_out_iso.dlm', 'mastercon_co.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
%  {'center_out.dlm', 'mastercon_co.mexw32', 'serPos.mexw32','Byte2Bits.mexw32'}, ...

% update the version numbers in words.h
perl('update_version.pl');

try
    close_system('limblab', 0);
catch
end

% build the project
try
    build(T, 'all', true);
    copyfile('*.dlm', '../../bin', 'f');
catch
    err = lasterror;
    disp(' ');
    disp('----------------------------------------------------');
    disp(err.message);
    disp('----------------------------------------------------');
end

% cleanup
try 
    delete('words.h');
    movefile('_words.h', 'words.h', 'f');
catch
end
