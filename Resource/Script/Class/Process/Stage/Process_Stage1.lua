function Process:_ResetStage1()
	local randval = hge.Random_Int(1, 3);
	local games = spim.sprites.games;
	games.spstage1_V.able = false;
	games.spstage1_O.able = false;
	games.spstage1_W.able = false;
	data.dt.stage1_rand = randval;
	local tox = data.dt.stage1_cx;
	local toy = data.dt.stage1_cy;
	
	if randval == 1 then
		games.spstage1_V.able = true;
	elseif randval == 2 then
		games.spstage1_O.able = true;
	elseif randval == 3 then
		games.spstage1_W.able = true;
	end
	data.dt.stage1_npop = data.dt.stage1_npop + data.dt.stage1_npopadd;
	if data.dt.stage1_npop > data.dt.stage1_npopmax then
		data.dt.stage1_npop = data.dt.stage1_npopmax;
	end
end

function Process:_UpdateStage1()
	local timer = data.dt.timer;
	
	if timer == 1 then
		self:_ResetStage1();
	end
	
	local bloose = false;
	local breset = false;
	if hge.Input_GetDIKey(self.keyA, DIKEY_DOWN) then
		if data.dt.stage1_rand ~= 3 then
			bloose = true;
		else
			breset = true;
		end
	end
	if hge.Input_GetDIKey(self.keyS, DIKEY_DOWN) then
		if data.dt.stage1_rand ~= 1 then
			bloose = true;
		else
			breset = true;
		end
	end
	if hge.Input_GetDIKey(self.keyD, DIKEY_DOWN) then
		if data.dt.stage1_rand ~= 2 then
			bloose = true;
		else
			breset = true;
		end
	end
	if bloose then
		return true;
	end
	if breset then
		self:_ResetStage1();
	end
	
	data.dt.stage1_npop = data.dt.stage1_npop - data.dt.stage1_npopminus;
	if data.dt.stage1_npop < 0 then
		return true;
	end
	if data.dt.stage1_npop < data.dt.stage1_npopmax / 3 and timer % 8 < 4 then
		spim.sprites.games.spstage1_slot.color = global.ARGB(0xff, 0xffff00);
		spim.sprites.games.spstage1.color = global.ARGB(0xff, 0xFF0000);
	else
		spim.sprites.games.spstage1_slot.color = global.ARGB(0xff, 0x7fffff);
		spim.sprites.games.spstage1.color = global.ARGB(0x80, 0xFF0000);
	end
	spim.sprites.games.spstage1_slot.vscale = data.dt.stage1_npop;
	
	return false;
end

function Process:_InitStage1()
	spim.sprites.games.spstage1_V = spim:Push(false, SI_OBJ_V, 
		data.dt.stage1_cx, data.dt.stage1_cy, 0, 3);
	spim.sprites.games.spstage1_O = spim:Push(false, SI_OBJ_O, 
		data.dt.stage1_cx, data.dt.stage1_cy, 0, 3);
	spim.sprites.games.spstage1_W = spim:Push(false, SI_OBJ_W, 
		data.dt.stage1_cx, data.dt.stage1_cy, 0, 3);
		
	data.dt.stage1_npopmax = data.dt.stage5_y - data.dt.stage1_y - 8;
	data.dt.stage1_npop = data.dt.stage1_npopmax;
	data.dt.stage1_npopminus = data.dt.stage1_npopmax / 300;
	data.dt.stage1_npopadd = data.dt.stage1_npopmax / 3 * 2;
	spim.sprites.games.spstage1_slot = spim:Push(true, SI_BLANK_POINT, 
		data.dt.stage1_w + data.dt.stage1_x - 5, data.dt.stage1_y + 4, 0, 8, data.dt.stage1_npop);
	hgeSprite.SetHotSpot(spim.sprites.games.spstage1_slot.sprite, 0.5, 0);
	
end

function Process:_RenderStart_Stage1()
	local games = spim.sprites.games;
	spim:RenderItem(games.spstage1_V);
	spim:RenderItem(games.spstage1_O);
	spim:RenderItem(games.spstage1_W);
	local tx = data.dt.stage1_w / 4 + data.dt.stage1_x;
	local ty = data.dt.stage1_h / 5 + data.dt.stage1_y;
	local txoffset = data.dt.stage1_w / 4;
	spim:RenderItemAs(games.spstage1_V, tx, ty, 0, 1);
	tx = tx + txoffset;
	spim:RenderItemAs(games.spstage1_O, tx, ty, 0, 1);
	tx = tx + txoffset;
	spim:RenderItemAs(games.spstage1_W, tx, ty, 0, 1);
	
	spim:RenderItem(spim.sprites.games.spstage1_slot);
	
	local arrange = HGETEXT_CENTER;
	ty = data.dt.stage1_y;
	hgeFont.printf(data.dt.font, tx - txoffset * 2, ty, arrange, "A");
	hgeFont.printf(data.dt.font, tx - txoffset, ty, arrange, "S");
	hgeFont.printf(data.dt.font, tx, ty, arrange, "D");
end