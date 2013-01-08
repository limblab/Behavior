% calls mex on all c files
% $Id$

% define dependencies
T = {...
%   {'ball_drop.dlm', 'mastercon_bd.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'bump_choice.dlm', 'mastercon_bc.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'center_out.dlm', 'mastercon_co.mexw64', 'serPos.mexw64','Byte2Bits.mexw64'}, ...
%   {'forced_choice.dlm', 'mastercon_fc.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'multi_gadget.dlm', 'mastercon_mg.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'visual_search.dlm', 'mastercon_vs.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'wrist_flexion.dlm', 'mastercon_wf.mexw64', 'Byte2Bits.mexw64'}, ...
  {'uncertainty1d.dlm', 'mastercon_un1d.mexw64','serPos.mexw64','Byte2Bits.mexw64'}, ...
%   {'random_walk.dlm', 'mastercon_rw.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'psychophysics.dlm', 'mastercon_3bc.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'attention.dlm', 'mastercon_attention.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'unstable.dlm', 'mastercon_unstable.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}...
  {'uncertaintytarget1d.dlm', 'mastercon_untarget1d.mexw64','serPos.mexw64','Byte2Bits.mexw64'}, ...

};

% update the version numbers in words.h
perl('update_version.pl');

try
    close_system('limblab', 0);
catch
end

% build the project
%try
    build(T, 'all', true);
    copyfile('*.dlm', '../../bin', 'f');
% catch
%     err = lasterror;
%     disp(' ');
%     disp('----------------------------------------------------');
%     disp(err.message);
%     disp('----------------------------------------------------');
% end
% 
% cleanup
try 
    delete('words.h');
    movefile('_words.h', 'words.h', 'f');
catch
end
