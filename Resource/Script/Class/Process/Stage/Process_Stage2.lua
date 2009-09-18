function Process:_UpdateStage2()
	local timer = data.dt.timer;
	
	if timer == 1 then
		self:_UpdateStage2BallAcc();
	end
		
	local movebarx = 0;
	if hge.Input_GetDIKey(self.keyLeft) then
		movebarx = movebarx - data.dt.stage2_barspeed;
	end
	if hge.Input_GetDIKey(self.keyRight) then
		movebarx = movebarx + data.dt.stage2_barspeed;
	end
	data.dt.stage2_barx = data.dt.stage2_barx + movebarx;
	local halfbarlength = data.dt.stage2_barlength / 2;
	if data.dt.stage2_barx > data.dt.stage2_x + data.dt.stage2_w - halfbarlength then
		data.dt.stage2_barx = data.dt.stage2_x + data.dt.stage2_w - halfbarlength;
	elseif data.dt.stage2_barx < data.dt.stage2_x + data.dt.stage2_leftedge + halfbarlength then
		data.dt.stage2_barx = data.dt.stage2_x + data.dt.stage2_leftedge + halfbarlength;
	end
	spim.sprites.games.spstage2_bartop.x = data.dt.stage2_barx;
	spim.sprites.games.spstage2_barbottom.x = data.dt.stage2_barx;
	
	local lastangle = data.dt.stage2_ballangle;
	local nowangle = lastangle;
	lastangle = self:_RegularStage2Angle(lastangle);
	local bounceedge = data.dt.stage2_edge + data.dt.stage2_ballr;
	local xdiff = data.dt.stage2_ballx - data.dt.stage2_barx;
	local absxdiff = math.abs(xdiff);
	local trange = halfbarlength + data.dt.stage2_ballr;
		
	if data.dt.stage2_ballx < data.dt.stage2_x + data.dt.stage2_leftedge + trange or data.dt.stage2_ballx > data.dt.stage2_x + data.dt.stage2_w - trange then
		nowangle = 180 - nowangle;
		nowangle = self:_RegularStage2Angle(nowangle);
		if nowangle <= 0 and nowangle > -45 then
			nowangle = -45;
		elseif nowangle > 0 and nowangle < 45 then
			nowangle = 45;
		elseif nowangle > 135 then
			nowangle = 135;
		elseif nowangle < -135 then
			nowangle = -135;
		end
	end
	
	nowangle = self:_RegularStage2Angle(nowangle);
	
	if absxdiff < trange then
		if (data.dt.stage2_bally < data.dt.stage2_y + bounceedge and data.dt.stage2_bally >= data.dt.stage2_barytop and nowangle < 0) or
			(data.dt.stage2_bally > data.dt.stage2_y + data.dt.stage2_h - bounceedge and data.dt.stage2_bally <= data.dt.stage2_barybottom and nowangle > 0) then
			if nowangle > 0 then
				nowangle = hge.Random_Int(-135, -45);
			else
				nowangle = hge.Random_Int(45, 135);
			end
		end
	end
	
	if lastangle ~= nowangle then
		data.dt.stage2_ballangle = nowangle;
		self:_UpdateStage2BallAcc();
	end
		
	
	data.dt.stage2_ballx = data.dt.stage2_ballx + data.dt.stage2_ballxacc;
	data.dt.stage2_bally = data.dt.stage2_bally + data.dt.stage2_ballyacc;
	effm:Update(effm.effects.games.effstage2_ball, nil, data.dt.stage2_ballx, data.dt.stage2_bally);
			
	if data.dt.stage2_bally < data.dt.stage2_y or data.dt.stage2_bally > data.dt.stage2_y + data.dt.stage2_h then
		return true;
	end
	
	if timer > 60 and (data.dt.stage2_bally < data.dt.stage2_edge * 2 + data.dt.stage2_y or data.dt.stage2_bally > data.dt.stage2_edge * -2 + data.dt.stage2_y + data.dt.stage2_h) and timer % 8 < 4 then
		spim.sprites.games.spstage2.color = global.ARGB(M_STAGE_FLASHALPHA, M_STAGECOLOR_2);
	else
		spim.sprites.games.spstage2.color = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_2);
	end
		
	return false;
end

function Process:_RegularStage2Angle(angle)
	while angle > 180 do
		angle = angle - 360;
	end
	while angle <= -180 do
		angle = angle + 360;
	end
	return angle;
end

function Process:_UpdateStage2BallAcc()
	local trad = math.rad(data.dt.stage2_ballangle);
	data.dt.stage2_ballxacc = math.cos(trad) * data.dt.stage2_ballspeed;
	data.dt.stage2_ballyacc = math.sin(trad) * data.dt.stage2_ballspeed;
end

function Process:_InitStage2()
	data.dt.stage2_ballangle = hge.Random_Int(-135, -45);
	data.dt.stage2_ballspeed = 1;
	data.dt.stage2_barspeed = 5;
	data.dt.stage2_edge = 16;
	data.dt.stage2_leftedge = data.dt.stage5_x + data.dt.stage5_w - data.dt.stage2_x;
	data.dt.stage2_barx = data.dt.stage2_cx + data.dt.stage2_leftedge / 2;
	data.dt.stage2_barytop = data.dt.stage2_y + data.dt.stage2_edge;
	data.dt.stage2_barybottom = data.dt.stage2_y + data.dt.stage2_h - data.dt.stage2_edge;
	data.dt.stage2_barlength = 45;
	spim.sprites.games.spstage2_bartop = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage2_barx, data.dt.stage2_barytop, 0, data.dt.stage2_barlength, 4);
	spim.sprites.games.spstage2_barbottom = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage2_barx, data.dt.stage2_barybottom, 0, data.dt.stage2_barlength, 4);
	spim.sprites.games.spstage2_barleft = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage2_x + data.dt.stage2_leftedge + data.dt.stage2_edge, data.dt.stage2_cy, 0, 4, data.dt.stage2_h - data.dt.stage2_edge * 2);
	spim.sprites.games.spstage2_barright = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage2_x + data.dt.stage2_w - data.dt.stage2_edge, data.dt.stage2_cy, 0, 4, data.dt.stage2_h - data.dt.stage2_edge * 2);
		
	if effm.effects.games == nil then
		effm.effects.games = {};
	end
	data.dt.stage2_ballr = 4;
	data.dt.stage2_ballx = data.dt.stage2_barx;
	data.dt.stage2_bally = data.dt.stage2_y + data.dt.stage2_h - data.dt.stage2_edge - data.dt.stage2_ballr;
	effm.effects.games.effstage2_ball = effm:Push(true, EFF_BALL,
		data.dt.stage2_ballx, data.dt.stage2_bally);
end

function Process:_RenderStart_Stage2()
	
	local arrange = HGETEXT_CENTER;
	local tx = data.dt.stage2_cx + data.dt.stage2_leftedge / 2;
	local ty = data.dt.stage1_cy;
	local txoffset = 45;
	hgeFont.printf(self.gamefont, tx - txoffset, ty, arrange, "Left");
	hgeFont.printf(self.gamefont, tx + txoffset, ty, arrange, "Right");
	
	local games = spim.sprites.games;
	if games == nil then
		return;
	end
	spim:RenderItem(games.spstage2_bartop);
	spim:RenderItem(games.spstage2_barbottom);
	spim:RenderItem(games.spstage2_barleft);
	spim:RenderItem(games.spstage2_barright);
		
	games = effm.effects.games;
	if games == nil then
		return;
	end
	effm:RenderItem(games.effstage2_ball);
end