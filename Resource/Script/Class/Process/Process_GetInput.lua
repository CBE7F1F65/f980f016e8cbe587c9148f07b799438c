function Process:GetInput()
	if hge.Input_GetDIJoy(JOY_LEFT) then
		hge.Input_SetDIKey(self.keyLeft);
	end
	if hge.Input_GetDIJoy(JOY_RIGHT) then
		hge.Input_SetDIKey(self.keyRight);
	end
	if hge.Input_GetDIJoy(JOY_UP) then
		hge.Input_SetDIKey(self.keyUp);
	end
	if hge.Input_GetDIJoy(JOY_DOWN) then
		hge.Input_SetDIKey(self.keyDown);
	end
	
	if hge.Input_GetDIJoy(self.joyPause) then
		hge.Input_SetDIKey(self.keyPause);
	end
end