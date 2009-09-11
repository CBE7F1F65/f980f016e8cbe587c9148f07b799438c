function Process:ProcessStart()
	
	time = time + 1;
	if time == 1 then
		music:MusicChange(MUS_02);
	end
	
	return PGO;
end