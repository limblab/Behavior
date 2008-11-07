% calls mex on all c files

% $Id$

T = {...
    {'random_walk.dlm', 'mastercon_rw.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'center_out.dlm', 'mastercon_co.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'uncertainty.dlm', 'mastercon_uc.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'forced_choice.dlm', 'mastercon_fc.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'bump_stim.dlm', 'mastercon_bs.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'multi_gadget.dlm', 'mastercon_mg.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'}, ...
    {'wrist_flexion.dlm', 'mastercon_wf.mexw32', 'serPos.mexw32', 'Byte2Bits.mexw32'} ...
};

build(T, 'all', true);

