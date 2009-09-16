function Process:GetInput()
	
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
	
	if data.dt.replaying then
		if luastate.And(data.dt.rpydata[time], M_BITTEST_12) > 0 then
			data.dt.replaying = false;
			data.dt.rpydata = {};
			return PTITLE;
		end
		hge.Input_SetDIKey(self.keyLeft, luastate.And(data.dt.rpydata[time], M_BITTEST_1) > 0);
		hge.Input_SetDIKey(self.keyRight, luastate.And(data.dt.rpydata[time], M_BITTEST_2) > 0);
		hge.Input_SetDIKey(self.keyUp, luastate.And(data.dt.rpydata[time], M_BITTEST_3) > 0);
		hge.Input_SetDIKey(self.keyDown, luastate.And(data.dt.rpydata[time], M_BITTEST_4) > 0);
		hge.Input_SetDIKey(self.keyA, luastate.And(data.dt.rpydata[time], M_BITTEST_5) > 0);
		hge.Input_SetDIKey(self.keyS, luastate.And(data.dt.rpydata[time], M_BITTEST_6) > 0);
		hge.Input_SetDIKey(self.keyD, luastate.And(data.dt.rpydata[time], M_BITTEST_7) > 0);
		hge.Input_SetDIKey(self.keyZ, luastate.And(data.dt.rpydata[time], M_BITTEST_8) > 0);
		hge.Input_SetDIKey(self.keyX, luastate.And(data.dt.rpydata[time], M_BITTEST_9) > 0);
		hge.Input_SetDIKey(self.keyC, luastate.And(data.dt.rpydata[time], M_BITTEST_10) > 0);
		hge.Input_SetDIKey(self.keySpace, luastate.And(data.dt.rpydata[time], M_BITTEST_11) > 0);
		data.dt.replayfps = luastate.RShift(data.dt.rpydata, 12) / 200;
		return;
	end
	
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
	
	if data.dt.active then
		local nowinput = 0;
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyLeft), 0));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyRight), 1));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyUp), 2));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyDown), 3));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyA), 4));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyS), 5));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyD), 6));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyZ), 7));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyX), 8));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keyC), 9));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Input_GetDIKey(self.keySpace), 10));
		nowinput = luastate.Or(nowinput, luastate.LShift(hge.Timer_GetFPS() * 200, 12));
		data.dt.rpydata[time] = nowinput;
	end
end