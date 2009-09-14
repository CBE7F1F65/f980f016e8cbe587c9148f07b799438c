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
end

function Process:_UpdateStage1()
	local timer = data.dt.timer;
	
	if timer == 1 then
		self:_InitStage1();
		self:_ResetStage1();
	end
	
	local bloose = false;
	if hge.Input_GetDIKey(self.keyA, DIKEY_DOWN) then
		if data.dt.stage1_rand ~= 1 then
			bloose = true;
		else
			self:_ResetStage1();
		end
	end
	if hge.Input_GetDIKey(self.keyS, DIKEY_DOWN) then
		if data.dt.stage1_rand ~= 2 then
			bloose = true;
		else
			self:_ResetStage1();
		end
	end
	if hge.Input_GetDIKey(self.keyD, DIKEY_DOWN) then
		if data.dt.stage1_rand ~= 3 then
			bloose = true;
		else
			self:_ResetStage1();
		end
	end
	if bloose then
		return true;
	end
	
	return false;
end

function Process:_InitStage1()
	spim.sprites.games.spstage1_V = spim:Push(SILAYER_GAMESPRITE, false, SI_OBJ_V, 
		data.dt.stage1_cx, data.dt.stage1_cy, 0);
	spim.sprites.games.spstage1_O = spim:Push(SILAYER_GAMESPRITE, false, SI_OBJ_O, 
		data.dt.stage1_cx, data.dt.stage1_cy, 0);
	spim.sprites.games.spstage1_W = spim:Push(SILAYER_GAMESPRITE, false, SI_OBJ_W, 
		data.dt.stage1_cx, data.dt.stage1_cy, 0);
end