function Process:_UpdateStage5()
	
	local timer = data.dt.timer;
	
	local w = spim.sprites.games.spstage5_square.hscale;
	
	local alarm = false;
	if w + M_ALARMTIME * data.dt.stage5_increacespeed > data.dt.stage5_w or w - M_ALARMTIME * data.dt.stage5_decreacespeed < 0 then
		alarm = true;
		if w > data.dt.stage5_w or w < 0 then
			return true;
		end
	end
		
	if alarm and time % 8 < 4 then
		spim.sprites.games.spstage5.color = global.ARGB(M_STAGE_FLASHALPHA, M_STAGECOLOR_5);
	else
		spim.sprites.games.spstage5.color = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_5);
	end
	
	if debug_cheat_5 then
		if not alarm then
			hge.Input_SetDIKey(self.keySpace);
		end
	end
	
	if hge.Input_GetDIKey(self.keySpace) then
		w = w + data.dt.stage5_increacespeed;
	else
		w = w - data.dt.stage5_decreacespeed;
	end
	
	spim.sprites.games.spstage5_square.hscale = w;
	spim.sprites.games.spstage5_square.vscale = w * data.dt.stage5_hperw;
	
	local bAddScore = false;
	if hge.Input_GetDIKey(self.keySpace, DIKEY_UP) then
		data.dt.stage5_decreacespeed = hge.Random_Float(data.dt.stage5_decreacespeedmin, data.dt.stage5_decreacespeedmax);
		bAddScore = true;
	end
	
	if bAddScore then
		data:UpdateScore(4);
	end
	
	return false;
end

function Process:_InitStage5()
	data.dt.stage5_increacespeed = 1;
	data.dt.stage5_decreacespeedmin = 0.4;
	data.dt.stage5_decreacespeedmax = 1.2;
	data.dt.stage5_decreacespeed = hge.Random_Float(data.dt.stage5_decreacespeedmin, data.dt.stage5_decreacespeedmax);
	local startw = data.dt.stage5_w / 2;
	data.dt.stage5_hperw = data.dt.stage5_h / data.dt.stage5_w;
	spim.sprites.games.spstage5_square = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage5_cx, data.dt.stage5_cy, 0, startw, startw * data.dt.stage5_hperw, global.ARGB(0xC0, 0xffffff));
end

function Process:_RenderStart_Stage5()
	local arrange = HGETEXT_CENTER;
	local tx = data.dt.stage5_cx;
	local ty = data.dt.stage5_y + data.dt.stage5_h / 4;
	hgeFont.printf(self.gamefont, tx, ty, arrange, "Space Bar");
	
	local games = spim.sprites.games;
	if games == nil then
		return;
	end
	spim:RenderItem(games.spstage5_square);
end