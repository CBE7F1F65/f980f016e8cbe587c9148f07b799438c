function Process:ProcessInit()
	time = time + 1
	if time == 1 then
--		self:ProcessPreInitial();
		return PGO;
	end
	
	time = 0;
	self.state = STATE_TITLE;
	return PTURN;
end