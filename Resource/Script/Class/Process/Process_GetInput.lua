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
	
	if hge.Input_GetDIJoy(self.joyA) then
		hge.Input_SetDIKey(self.keyA);
	end
	if hge.Input_GetDIJoy(self.joyS) then
		hge.Input_SetDIKey(self.keyS);
	end
	if hge.Input_GetDIJoy(self.joyD) then
		hge.Input_SetDIKey(self.keyD);
	end
	if hge.Input_GetDIJoy(self.joyZ) then
		hge.Input_SetDIKey(self.keyZ);
	end
	if hge.Input_GetDIJoy(self.joyX) then
		hge.Input_SetDIKey(self.keyX);
	end
	if hge.Input_GetDIJoy(self.joyC) then
		hge.Input_SetDIKey(self.keyC);
	end
	if hge.Input_GetDIJoy(self.joySpace) then
		hge.Input_SetDIKey(self.keySpace);
	end
	if hge.Input_GetDIJoy(self.joyPause) then
		hge.Input_SetDIKey(self.keyPause);
	end
	if hge.Input_GetDIJoy(self.joyEnter) then
		hge.Input_SetDIKey(self.keyEnter);
	end
	if hge.Input_GetDIJoy(self.joyCancel) then
		hge.Input_SetDIKey(self.keyCancel);
	end
end