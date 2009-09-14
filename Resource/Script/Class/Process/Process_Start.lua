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
		end
		if not bret and data.dt.havestage2 then
			self:_UpdateStage2();
		end
		if not bret and data.dt.havestage3 then
			self:_UpdateStage3();
		end
		if not bret and data.dt.havestage4 then
			self:_UpdateStage4();
		end
		if not bret and data.dt.havestage5 then
			self:_UpdateStage5();
		end
		
		if bret then
			self.state = STATE_OVER;
			time = 0;
			return PTURN;
		end
	end
	
	return PGO;
end

function Process:_StartPrep()
	spim:Clear();
	data.d.seed = hge.Random_Seed();
	data.d.nowdifflv = sel.saved[SELSAVE_DIFFICULT];
	local bit1 = hge.Random_Int(0, 4);
	local bit2;
	repeat
		bit2 = hge.Random_Int(0, 4);
	until bit2 ~= bit1;
	if data.d.nowdifflv == 4 then
		data.d.stage = 0x1F;
	else
		data.d.stage = luastate.LShift(1, bit1);
		if data.d.nowdifflv == 3 then
			data.d.stage = luastate.Xor(data.d.stage, 0x1F);
		else
			data.d.stage = data.d.stage + luastate.LShift(1, bit2);
			if data.d.nowdifflv == 2 then
				data.d.stage = luastate.Xor(data.d.stage, 0x1F);
			end
		end
	end
	
	data.dt.stage1_x = M_CLIENT_LEFT;
	data.dt.stage1_y = M_CLIENT_TOP;
	data.dt.stage1_w = M_CLIENT_WIDTH / 2;
	data.dt.stage1_h = M_CLIENT_HEIGHT / 2;
	data.dt.stage1_cx = data.dt.stage1_w / 2 + data.dt.stage1_x;
	data.dt.stage1_cy = data.dt.stage1_h / 2 + data.dt.stage1_y;
	spim.sprites.games = {};
	spim.sprites.games.spstage1 = spim:Push(
		SILAYER_GAMEGROUND, true,
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
		SILAYER_GAMEGROUND, true,
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
		SILAYER_GAMEGROUND, true,
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
		SILAYER_GAMEGROUND, true,
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
		SILAYER_GAMEGROUND, true,
		SI_BLANK_POINT,
		data.dt.stage5_cx, data.dt.stage5_cy, 0,
		data.dt.stage5_w, data.dt.stage5_h
	);
	
	local tcol;
	data.dt.havestage1 = luastate.And(data.d.stage, luastate.LShift(1, 4)) > 0;
	if data.dt.havestage1 then
		tcol = global.ARGB(0x3f, 0xFF0000);
	else
		tcol = global.ARGB(0x20, 0xFF0000);
	end
	spim.sprites.games.spstage1.color = tcol;
	data.dt.havestage2 = luastate.And(data.d.stage, luastate.LShift(1, 3)) > 0;
	if data.dt.havestage2 then
		tcol = global.ARGB(0xff, 0x00FF00);
	else
		tcol = global.ARGB(0x20, 0x00FF00);
	end
	spim.sprites.games.spstage2.color = tcol;
	data.dt.havestage3 = luastate.And(data.d.stage, luastate.LShift(1, 2)) > 0;
	if data.dt.havestage3 then
		tcol = global.ARGB(0xff, 0x0000FF);
	else
		tcol = global.ARGB(0x20, 0x0000FF);
	end
	spim.sprites.games.spstage3.color = tcol;
	data.dt.havestage4 = luastate.And(data.d.stage, luastate.LShift(1, 1)) > 0;
	if data.dt.havestage4 then
		tcol = global.ARGB(0xff, 0xFFFF00);
	else
		tcol = global.ARGB(0x20, 0xFFFF00);
	end
	spim.sprites.games.spstage4.color = tcol;
	data.dt.havestage5 = luastate.And(data.d.stage, luastate.LShift(1, 0)) > 0;
	if data.dt.havestage5 then
		tcol = global.ARGB(0xff, 0x00FFFF);
	else
		tcol = global.ARGB(0x20, 0x0000FF);
	end
	spim.sprites.games.spstage5.color = tcol;
	
	data.dt.timer = 0;
end