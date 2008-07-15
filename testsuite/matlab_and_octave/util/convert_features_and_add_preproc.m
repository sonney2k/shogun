function y = convert_features_and_add_preproc()
	global order;
	global gap;
	global reverse;
	global feature_type;

	if isempty(order)
		y=1;
		return
	end

	if strcmp(feature_type, 'Ulong')==1
		type='ULONG';
	elseif strcmp(feature_type, 'Word')==1
		type='WORD';
	else
		y=1;
		return
	end

	sg('add_preproc', strcat('SORT', type, 'STRING'));
	sg('convert', 'TRAIN', 'STRING', 'CHAR', 'STRING', type,
		order, order-1, gap, reverse);
	sg('attach_preproc', 'TRAIN');

	sg('convert', 'TEST', 'STRING', 'CHAR', 'STRING', type,
		order, order-1, gap, reverse);
	sg('attach_preproc', 'TEST');