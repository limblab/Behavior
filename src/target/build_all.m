% calls mex on all c files
% $Id$

% define dependencies
T = {...
%    {'ball_drop.dlm', 'mastercon_bd.mexw64', 'Byte2Bits.mexw64'}, ...
%    {'bump_choice.dlm', 'mastercon_bc.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%    {'center_out.dlm', 'mastercon_co.mexw64', 'serPos.mexw64','Byte2Bits.mexw64'}, ...
%     {'center_out_mult_bumps.dlm', 'mastercon_co_mult_bumps.mexw64', 'serPos.mexw64','Byte2Bits.mexw64'}, ...

%    {'forced_choice.dlm', 'mastercon_fc2.mexw64', 'serPos.mexw64','Byte2Bits.mexw64'}...
    {'twoAFC.dlm','mastercon_2afc_stim.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
%    {'multi_gadget.dlm', 'mastercon_mg.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%    {'visual_search.dlm', 'mastercon_vs.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%    {'wrist_flexion.dlm', 'mastercon_wf.mexw64', 'Byte2Bits.mexw64'}, ...
%    {'uncertainty1d.dlm', 'mastercon_un1d.mexw64','serPos.mexw64','Byte2Bits.mexw64'}, ...
%    {'random_walk.dlm', 'mastercon_rw.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%    {'psychophysics.dlm', 'mastercon_3bc.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%     {'attention.dlm', 'mastercon_attention.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'}, ...
%   {'unstable.dlm',git 'mastercon_unstable.mexw64', 'serPos.mexw64', 'Byte2Bits.mexw64'},...
%    {'uncertaintytarget1d.dlm', 'mastercon_untarget1d.mexw64','serPos.mexw64','Byte2Bits.mexw64'}, ...
%    {'uncertaintytarget2d.dlm', 'mastercon_untarget2d.mexw64','serPos.mexw64','Byte2Bits.mexw64'}, ...
%   {'uncisek.dlm', 'mastercon_uncisek.mexw64','serPos.mexw64','Byte2Bits.mexw64'}, ...
 %    {'defend_center.dlm', 'mastercon_defend_ctr.mexw64','serPos.mexw64','Byte2Bits.mexw64'}, ...
%       {'receptor_stim.dlm', 'mastercon_receptor_stim.mexw64','serPos.mexw64','Byte2Bits.mexw64', 'ich5.mexw64'} ...
% {'ring_bump.namic_center_out.dlm', 'mastercon_dynamic_center_out.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
% {'unstable_reach.dlm', 'mastercon_unstable_reach.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
%{'resist_perturbations.dlm', 'mastercon_resist_perturbations.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
%      {'cuecomb.dlm', 'mastercon_cuecomb.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
%     {'ring_reporting.dlm','mastercon_ring_reporting.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
% {'COsabes.dlm','mastercon_cosabes.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
%  {'center_out_3D.dlm', 'mastercon_co_3D.mexw64', 'Byte2Bits.mexw64'}...
% {'OutOutReach.dlm','mastercon_outout.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
% {'TwoSpaceRT.dlm','mastercon_twospaceRT.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
% {'COsabes.dlm','mastercon_cosabes.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
% {'CO_bump.dlm','mastercon_CO_bump.mexw64','serPos.mexw64','Byte2Bits.mexw64'}...
% {'center_out_3D.dlm', 'mastercon_co_3D.mexw64', 'Byte2Bits.mexw64'}
%  {'RandomTarget3D.dlm', 'mastercon_RT3D.mexw64', 'Byte2Bits.mexw64'}
%  {'CenterOutCenter3D.dlm', 'mastercon_COC3D.mexw64', 'Byte2Bits.mexw64'}
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
