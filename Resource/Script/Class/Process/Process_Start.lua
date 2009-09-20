function Process:ProcessStart()

	time = time + 1;
	if time == 1 then
		music:MusicChange(MUS_02);
		self:_StartPrep();
	end
	if time > 60 then
		data.dt.timer = data.dt.timer + 1;
		local bret;
		if data.dt.havestage1 then
			bret = self:_UpdateStage1();
			if debug_ignore_1 then
				bret = false;
			end
			if bret then
				se:Push(SE_GAME_GAMEOVER, data.dt.stage1_cx);
			end
		end
		if not bret and data.dt.havestage2 then
			bret = self:_UpdateStage2();
			if debug_ignore_2 then
				bret = false;
			end
			if bret then
				se:Push(SE_GAME_GAMEOVER, data.dt.stage2_cx);
			end
		end
		if not bret and data.dt.havestage3 then
			bret = self:_UpdateStage3();
			if debug_ignore_3 then
				bret = false;
			end
			if bret then
				se:Push(SE_GAME_GAMEOVER, data.dt.stage3_cx);
			end
		end
		if not bret and data.dt.havestage4 then
			bret = self:_UpdateStage4();
			if debug_ignore_4 then
				bret = false;
			end
			if bret then
				se:Push(SE_GAME_GAMEOVER, data.dt.stage4_cx);
			end
		end
		if not bret and data.dt.havestage5 then
			bret = self:_UpdateStage5();
			if debug_ignore_5 then
				bret = false;
			end
			if bret then
				se:Push(SE_GAME_GAMEOVER, data.dt.stage5_cx);
			end
		end
		
		if debug_suicidekey > 0 then
			if hge.Input_GetDIKey(debug_suicidekey, DIKEY_DOWN) then
				bret = true;
			end
		end
		
		if bret then
			self.state = STATE_OVER;
			time = 0;
			return PTURN;
		else
			data:UpdateScore(M_SCOREPERTIME, time);
		end
	end
	
	return PGO;
end

function Process:_StartPrep()
	self:SetActive(true);
	spim:Clear();
	effm:Clear();
	local active, replaying = self:CheckActive();
	local name, difficult, stage, seed;
	if replaying then
		name, difficult, stage, seed = data:GetReplayHeader();
		hge.Random_Seed(seed);
		self.nowdifflv = difficult;
	else
		seed = hge.Random_Seed();
		self.nowdifflv = sel.saved[SELSAVE_DIFFICULT];
	end
	local bit1 = hge.Random_Int(0, 4);
	local bit2;
	repeat
		bit2 = hge.Random_Int(0, 4);
	until bit2 ~= bit1;
	if self.nowdifflv == 4 then
		stage = 0x1F;
	else
		stage = luastate.LShift(1, bit1);
		if self.nowdifflv == 3 then
			stage = luastate.Xor(stage, 0x1F);
		else
			stage = stage + luastate.LShift(1, bit2);
			if self.nowdifflv == 2 then
				stage = luastate.Xor(stage, 0x1F);
			end
		end
	end
	
	if not replaying then
		data:PushReplayHeader(export:GetUsername(), self.nowdifflv, stage, seed);
	end
	
	data.dt.stage1_x = M_CLIENT_LEFT;
	data.dt.stage1_y = M_CLIENT_TOP;
	data.dt.stage1_w = M_CLIENT_WIDTH / 2;
	data.dt.stage1_h = M_CLIENT_HEIGHT / 2;
	data.dt.stage1_cx = data.dt.stage1_w / 2 + data.dt.stage1_x;
	data.dt.stage1_cy = data.dt.stage1_h / 2 + data.dt.stage1_y;
	spim.sprites.games = {};
	spim.sprites.games.spstage1 = spim:Push(
		true,
		SI_BLANK_POINT,
		data.dt.stage1_cx, data.dt.stage1_cy, 0,
		data.dt.stage1_w, data.dt.stage1_h
	);
	data.dt.stage2_x = M_CLIENT_LEFT + M_CLIENT_WIDTH / 2;
	data.dt.stage2_y = M_CLIENT_TOP;
	data.dt.stage2_w = M_CLIENT_WIDTH / 2;
	data.dt.stage2_h = M_CLIENT_HEIGHT / 2;
	data.dt.stage2_cx = data.dt.stage2_w / 2 + data.dt.stage2_x;
	data.dt.stage2_cy = data.dt.stage2_h / 2 + data.dt.stage2_y;
	spim.sprites.games.spstage2 = spim:Push(
		true,
		SI_BLANK_POINT,
		data.dt.stage2_cx, data.dt.stage2_cy, 0,
		data.dt.stage2_w, data.dt.stage2_h
	);
	data.dt.stage3_x = M_CLIENT_LEFT;
	data.dt.stage3_y = M_CLIENT_TOP + M_CLIENT_HEIGHT / 2;
	data.dt.stage3_w = M_CLIENT_WIDTH / 2;
	data.dt.stage3_h = M_CLIENT_HEIGHT / 2;
	data.dt.stage3_cx = data.dt.stage3_w / 2 + data.dt.stage3_x;
	data.dt.stage3_cy = data.dt.stage3_h / 2 + data.dt.stage3_y;
	spim.sprites.games.spstage3 = spim:Push(
		true,
		SI_BLANK_POINT,
		data.dt.stage3_cx, data.dt.stage3_cy, 0,
		data.dt.stage3_w, data.dt.stage3_h
	);
	data.dt.stage4_x = M_CLIENT_LEFT + M_CLIENT_WIDTH / 2;
	data.dt.stage4_y = M_CLIENT_TOP + M_CLIENT_HEIGHT / 2;
	data.dt.stage4_w = M_CLIENT_WIDTH / 2;
	data.dt.stage4_h = M_CLIENT_HEIGHT / 2;
	data.dt.stage4_cx = data.dt.stage4_w / 2 + data.dt.stage4_x;
	data.dt.stage4_cy = data.dt.stage4_h / 2 + data.dt.stage4_y;
	spim.sprites.games.spstage4 = spim:Push(
		true,
		SI_BLANK_POINT,
		data.dt.stage4_cx, data.dt.stage4_cy, 0,
		data.dt.stage4_w, data.dt.stage4_h
	);
	data.dt.stage5_x = M_CLIENT_LEFT + M_CLIENT_WIDTH / 3;
	data.dt.stage5_y = M_CLIENT_TOP + M_CLIENT_HEIGHT / 3;
	data.dt.stage5_w = M_CLIENT_WIDTH / 3;
	data.dt.stage5_h = M_CLIENT_HEIGHT / 3;
	data.dt.stage5_cx = data.dt.stage5_w / 2 + data.dt.stage5_x;
	data.dt.stage5_cy = data.dt.stage5_h / 2 + data.dt.stage5_y;
	spim.sprites.games.spstage5 = spim:Push(
		true,
		SI_BLANK_POINT,
		data.dt.stage5_cx, data.dt.stage5_cy, 0,
		data.dt.stage5_w, data.dt.stage5_h
	);
	spim.sprites.games.spstage5_bg = spim:Push(
		true,
		SI_BLANK_POINT,
		data.dt.stage5_cx, data.dt.stage5_cy, 0,
		data.dt.stage5_w, data.dt.stage5_h, global.ARGB(0xff, 0)
	);
	
	local tcol;
	data.dt.havestage1 = luastate.And(stage, luastate.LShift(1, 4)) > 0;
	if data.dt.havestage1 then
		tcol = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_1);
	else
		tcol = global.ARGB(M_STAGE_NONACTIVEALPHA, M_STAGECOLOR_1);
	end
	spim.sprites.games.spstage1.color = tcol;
	data.dt.havestage2 = luastate.And(stage, luastate.LShift(1, 3)) > 0;
	if data.dt.havestage2 then
		tcol = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_2);
	else
		tcol = global.ARGB(M_STAGE_NONACTIVEALPHA, M_STAGECOLOR_2);
	end
	spim.sprites.games.spstage2.color = tcol;
	data.dt.havestage3 = luastate.And(stage, luastate.LShift(1, 2)) > 0;
	if data.dt.havestage3 then
		tcol = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_3);
	else
		tcol = global.ARGB(M_STAGE_NONACTIVEALPHA, M_STAGECOLOR_3);
	end
	spim.sprites.games.spstage3.color = tcol;
	data.dt.havestage4 = luastate.And(stage, luastate.LShift(1, 1)) > 0;
	if data.dt.havestage4 then
		tcol = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_4);
	else
		tcol = global.ARGB(M_STAGE_NONACTIVEALPHA, M_STAGECOLOR_4);
	end
	spim.sprites.games.spstage4.color = tcol;
	data.dt.havestage5 = luastate.And(stage, luastate.LShift(1, 0)) > 0;
	if data.dt.havestage5 then
		tcol = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_5);
	else
		tcol = global.ARGB(M_STAGE_NONACTIVEALPHA, M_STAGECOLOR_5);
	end
	spim.sprites.games.spstage5.color = tcol;
	
	data.dt.timer = 0;
	if data.dt.havestage1 then
		self:_InitStage1();
	end
	if data.dt.havestage2 then
		self:_InitStage2();
	end
	if data.dt.havestage3 then
		self:_InitStage3();
	end
	if data.dt.havestage4 then
		self:_InitStage4();
	end
	if data.dt.havestage5 then
		self:_InitStage5();
	end
end

function Process:_RenderStart()
	if spim.sprites.games ~= nil then
		spim:RenderItem(spim.sprites.games.spstage1);
		spim:RenderItem(spim.sprites.games.spstage2);
		spim:RenderItem(spim.sprites.games.spstage3);
		spim:RenderItem(spim.sprites.games.spstage4);
		spim:RenderItem(spim.sprites.games.spstage5_bg);
		spim:RenderItem(spim.sprites.games.spstage5);
	end
	if data.dt.havestage1 then
		self:_RenderStart_Stage1();
	end
	if data.dt.havestage2 then
		self:_RenderStart_Stage2();
	end
	if data.dt.havestage3 then
		self:_RenderStart_Stage3();
	end
	if data.dt.havestage4 then
		self:_RenderStart_Stage4();
	end
	if data.dt.havestage5 then
		self:_RenderStart_Stage5();
	end
end