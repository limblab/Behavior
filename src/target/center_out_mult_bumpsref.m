function sys=center_out_mult_bumpsref
sys = [];
sys.child = [];
sys.NumDataTypes = 5; 
sys.DataTypes = [];
temp.EnumNames='';
temp.EnumValues = [];
temp.Name = '';
sys.DataTypes = repmat(temp,1,5);
sys.DataTypes(1).Name = 'real_T';
sys.DataTypes(2).Name = 'boolean_T';
sys.DataTypes(3).Name = 'uint8_T';
sys.DataTypes(4).Name = 'real32_T';
sys.DataTypes(5).Name = 'int32_T';
