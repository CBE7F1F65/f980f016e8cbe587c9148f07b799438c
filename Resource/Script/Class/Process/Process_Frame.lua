function Process:Frame()
	
	if hge.Input_GetKeyState(HGEK_ALT) and hge.Input_GetKeyState(HGEK_ENTER) then
		mp.screenmode = not mp.screenmode;
		hge.System_SetState(HGE_WINDOWED, not mp.screenmode);
		hge.System_SetState(HGE_HIDEMOUSE, mp.screenmode);
	end
	
	self:GetInput();
	
	local retval = PTITLE;
	if self.state == STATE_START then
		retval = self:ProcessStart();
	elseif self.state == STATE_TITLE then
		retval = self:ProcessTitle();
	elseif self.state == STATE_INIT then
		retval = self:ProcessInit();
	end
	
	
	if retval == PTITLE then
		time = 0;
		self.state = STATE_TITLE;
		retval = PTURN;
	end
	
	if retval == PTURN then
		return PTURN;
	end
	
	if retval == PQUIT then
		return PQUIT;
	end
	
	return PGO;
end