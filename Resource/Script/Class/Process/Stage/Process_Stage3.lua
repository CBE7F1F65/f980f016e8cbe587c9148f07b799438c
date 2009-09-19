function Process:_ResetStage3()
	local randval = hge.Random_Int(1, 3);
	data.dt.stage3_rand = randval;
	se:Stop(SE_GAME_DOWN);
	se:Stop(SE_GAME_FLAT);
	se:Stop(SE_GAME_UP);
	if randval == 1 then
		se:Push(SE_GAME_DOWN);
	elseif randval == 2 then
		se:Push(SE_GAME_FLAT);
	elseif randval == 3 then
		se:Push(SE_GAME_UP);
	end
	data.dt.stage3_npop = data.dt.stage3_npop + data.dt.stage3_npopadd;
	if data.dt.stage3_npop > data.dt.stage3_npopmax then
		data.dt.stage3_npop = data.dt.stage3_npopmax;
	end
end

function Process:_UpdateStage3()
	
	local timer = data.dt.timer;
	
	if timer == 1 then
		self:_ResetStage3();
	end
	
	local bloose = false;
	local breset = false;
	if hge.Input_GetDIKey(self.keyZ, DIKEY_DOWN) then
		if data.dt.stage3_rand ~= 1 then
			bloose = true;
		else
			breset = true;
		end
	end
	if hge.Input_GetDIKey(self.keyX, DIKEY_DOWN) then
		if data.dt.stage3_rand ~= 2 then
			bloose = true;
		else
			breset = true;
		end
	end
	if hge.Input_GetDIKey(self.keyC, DIKEY_DOWN) then
		if data.dt.stage3_rand ~= 3 then
			bloose = true;
		else
			breset = true;
		end
	end
	if bloose then
		return true;
	end
	if breset then
		self:_ResetStage3();
	end
	
	data.dt.stage3_npop = data.dt.stage3_npop - data.dt.stage3_npopminus;
	if data.dt.stage3_npop < 0 then
		return true;
	end
	if data.dt.stage3_npop < M_ALARMTIME * data.dt.stage3_npopminus and timer % 8 < 4 then
		spim.sprites.games.spstage3_slot.color = global.ARGB(0xff, 0xffff00);
		spim.sprites.games.spstage3.color = global.ARGB(M_STAGE_FLASHALPHA, M_STAGECOLOR_3);
	else
		spim.sprites.games.spstage3_slot.color = global.ARGB(0xff, 0x7fffff);
		spim.sprites.games.spstage3.color = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_3);
	end
	spim.sprites.games.spstage3_slot.vscale = data.dt.stage3_npop;
	
	return false;
end

function Process:_InitStage3()
	data.dt.stage3_npopmax = data.dt.stage3_y + data.dt.stage3_h - (data.dt.stage5_y + data.dt.stage5_h) - 8;
	data.dt.stage3_npop = data.dt.stage3_npopmax;
	data.dt.stage3_npopminus = data.dt.stage3_npopmax / 300;
	data.dt.stage3_npopadd = data.dt.stage3_npopmax / 3 * 2;
	spim.sprites.games.spstage3_slot = spim:Push(true, SI_BLANK_POINT, 
		data.dt.stage3_w + data.dt.stage3_x - 5, data.dt.stage5_y + data.dt.stage5_h + 4, 0, 8, data.dt.stage3_npop);
	hgeSprite.SetHotSpot(spim.sprites.games.spstage3_slot.sprite, 0.5, 0);
end

function Process:_RenderStart_Stage3()
	local games = spim.sprites.games;
	if games == nil then
		return;
	end
	spim:RenderItem(spim.sprites.games.spstage3_slot);
	
	local arrange = HGETEXT_CENTER;
	local tx = data.dt.stage3_cx;
	local ty = data.dt.stage3_cy;
	local txoffset = 90;
	local tyoffset = 30;
	hgeFont.printf(self.gamefont, tx, ty - tyoffset, arrange, "Listen...")
	hgeFont.printf(self.gamefont, tx - txoffset, ty, arrange, "Z");
	hgeFont.printf(self.gamefont, tx, ty, arrange, "X");
	hgeFont.printf(self.gamefont, tx + txoffset, ty, arrange, "C");
	hgeFont.printf(self.gamefont, tx - txoffset, ty + tyoffset, arrange, "Down");
	hgeFont.printf(self.gamefont, tx, ty + tyoffset, arrange, "Flat");
	hgeFont.printf(self.gamefont, tx + txoffset, ty + tyoffset, arrange, "Up");
end