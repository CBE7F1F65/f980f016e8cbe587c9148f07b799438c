function Process:_UpdateStage4()
	
	local timer = data.dt.timer;
	
	if hge.Input_GetDIKey(self.keyUp, DIKEY_DOWN) then
		if data.dt.stage4_playerypos > 0 then
			data.dt.stage4_playerypos = data.dt.stage4_playerypos - 1;
		end
	end
	if hge.Input_GetDIKey(self.keyDown, DIKEY_DOWN) then
		if data.dt.stage4_playerypos < 4 then
			data.dt.stage4_playerypos = data.dt.stage4_playerypos + 1;
		end
	end
	spim.sprites.games.spstage4_player.y = self:_GetStage4Y(data.dt.stage4_playerypos);
	
	data.dt.stage4_alarm = false;
	data.dt.stage4_ballx1, data.dt.stage4_ballypos1, failed = self:_MoveStage4Ball(data.dt.stage4_ballx1, data.dt.stage4_ballypos1, effm.effects.games.effstage4_ball1);
	if failed then
		return true;
	end
	data.dt.stage4_ballx2, data.dt.stage4_ballypos2, failed = self:_MoveStage4Ball(data.dt.stage4_ballx2, data.dt.stage4_ballypos2, effm.effects.games.effstage4_ball2);
	if failed then
		return true;
	end
	data.dt.stage4_ballx3, data.dt.stage4_ballypos3, failed = self:_MoveStage4Ball(data.dt.stage4_ballx3, data.dt.stage4_ballypos3, effm.effects.games.effstage4_ball3);
	if failed then
		return true;
	end
	data.dt.stage4_ballx4, data.dt.stage4_ballypos4, failed = self:_MoveStage4Ball(data.dt.stage4_ballx4, data.dt.stage4_ballypos4, effm.effects.games.effstage4_ball4);
	if failed then
		return true;
	end
	data.dt.stage4_ballx5, data.dt.stage4_ballypos5, failed = self:_MoveStage4Ball(data.dt.stage4_ballx5, data.dt.stage4_ballypos5, effm.effects.games.effstage4_ball5);
	if failed then
		return true;
	end
	data.dt.stage4_ballx6, data.dt.stage4_ballypos6, failed = self:_MoveStage4Ball(data.dt.stage4_ballx6, data.dt.stage4_ballypos6, effm.effects.games.effstage4_ball6);
	if failed then
		return true;
	end	
	
	if data.dt.stage4_alarm and timer % 8 < 4 then
		spim.sprites.games.spstage4.color = global.ARGB(M_STAGE_FLASHALPHA, M_STAGECOLOR_4);
	else
		spim.sprites.games.spstage4.color = global.ARGB(M_STAGE_NORMALALPHA, M_STAGECOLOR_4);
	end
	
	if failed then
		return true;
	end
	return false;
end

function Process:_MoveStage4Ball(x, ypos, effectitem)
	x = x - data.dt.stage4_ballspeed;
	local able;
	if x < data.dt.stage4_x + data.dt.stage4_edge then
		x = data.dt.stage4_newballx;
		ypos = hge.Random_Int(0, 4);
		able = false;
	end
	if not effectitem.able and x < data.dt.stage4_x + data.dt.stage4_w - data.dt.stage4_edge then
		able = true;
	end
	local failed = false;
	if ypos == data.dt.stage4_playerypos then
		local xdiff = x - data.dt.stage4_stringx;
		if xdiff > 0 then
			if xdiff < data.dt.stage4_ballspeed * M_ALARMTIME then
				data.dt.stage4_alarm = true;
				if xdiff < data.dt.stage4_ballr then
					failed = true;
				end
			end
		end
	end
	effm:Update(effectitem, able, x, self:_GetStage4Y(ypos));
	return x, ypos, failed;
end

function Process:_GetStage4Y(ypos)
	return data.dt.stage4_yfirst + ypos * data.dt.stage4_yoffset
end

function Process:_InitStage4()
	data.dt.stage4_edge = 16;
	data.dt.stage4_alarm = false;
	data.dt.stage4_topedge = data.dt.stage5_y + data.dt.stage5_h - data.dt.stage4_y;
	data.dt.stage4_ballspeed = 1.5;
	local racetime = (data.dt.stage4_w - data.dt.stage4_edge * 2) / data.dt.stage4_ballspeed;
	
	data.dt.stage4_stringx = data.dt.stage4_w / 3 + data.dt.stage4_x;
	local updownedge = 4;
	local lineyfirst = data.dt.stage4_y + data.dt.stage4_topedge + updownedge;
	local yoffset = (data.dt.stage4_h - data.dt.stage4_topedge - updownedge * 2) / 5;
	data.dt.stage4_yoffset = yoffset;
	data.dt.stage4_yfirst = lineyfirst + data.dt.stage4_yoffset / 2;
	data.dt.stage4_playerypos = 2;
	local ycenter = self:_GetStage4Y(data.dt.stage4_playerypos)
	
	spim.sprites.games.spstage4_string = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage4_stringx, ycenter, 0, 4, data.dt.stage4_h - data.dt.stage4_topedge);
	spim.sprites.games.spstage4_player = spim:Push(true, SI_BLANK_SQUARE,
		data.dt.stage4_stringx, ycenter, 0, 1, 1, global.ARGB(0xFF, 0x00FFFF));
		
	spim.sprites.games.spstage4_line1 = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage4_cx, lineyfirst, 0, data.dt.stage4_w - data.dt.stage4_edge * 2, 1);
	spim.sprites.games.spstage4_line2 = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage4_cx, lineyfirst + yoffset, 0, data.dt.stage4_w - data.dt.stage4_edge * 2, 1);
	spim.sprites.games.spstage4_line3 = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage4_cx, lineyfirst + yoffset * 2, 0, data.dt.stage4_w - data.dt.stage4_edge * 2, 1);
	spim.sprites.games.spstage4_line4 = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage4_cx, lineyfirst + yoffset * 3, 0, data.dt.stage4_w - data.dt.stage4_edge * 2, 1);
	spim.sprites.games.spstage4_line5 = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage4_cx, lineyfirst + yoffset * 4, 0, data.dt.stage4_w - data.dt.stage4_edge * 2, 1);
	spim.sprites.games.spstage4_line6 = spim:Push(true, SI_BLANK_POINT,
		data.dt.stage4_cx, lineyfirst + yoffset * 5, 0, data.dt.stage4_w - data.dt.stage4_edge * 2, 1);
	
	if effm.effects.games == nil then
		effm.effects.games = {};
	end
	data.dt.stage4_ballr = 4;
	local xoffset = data.dt.stage4_ballspeed * racetime / 3;
	local firstballx = data.dt.stage4_x + data.dt.stage4_w + xoffset;
	data.dt.stage4_newballx = firstballx + xoffset * 2;
	data.dt.stage4_ballx1 = firstballx;
	data.dt.stage4_ballx2 = firstballx + xoffset;
	data.dt.stage4_ballx3 = firstballx + xoffset * 2;
	data.dt.stage4_ballx4 = firstballx + xoffset * 3;
	data.dt.stage4_ballx5 = firstballx + xoffset * 4;
	data.dt.stage4_ballx6 = firstballx + xoffset * 5;
	data.dt.stage4_ballypos1 = hge.Random_Int(0, 4);
	data.dt.stage4_bally1 = self:_GetStage4Y(data.dt.stage4_ballypos1);
	data.dt.stage4_ballypos2 = hge.Random_Int(0, 4);
	data.dt.stage4_bally2 = self:_GetStage4Y(data.dt.stage4_ballypos2);
	data.dt.stage4_ballypos3 = hge.Random_Int(0, 4);
	data.dt.stage4_bally3 = self:_GetStage4Y(data.dt.stage4_ballypos3);
	data.dt.stage4_ballypos4 = hge.Random_Int(0, 4);
	data.dt.stage4_bally4 = self:_GetStage4Y(data.dt.stage4_ballypos4);
	data.dt.stage4_ballypos5 = hge.Random_Int(0, 4);
	data.dt.stage4_bally5 = self:_GetStage4Y(data.dt.stage4_ballypos5);
	data.dt.stage4_ballypos6 = hge.Random_Int(0, 4);
	data.dt.stage4_bally6 = self:_GetStage4Y(data.dt.stage4_ballypos6);
	effm.effects.games.effstage4_ball1 = effm:Push(false, EFF_BALL,
		data.dt.stage4_ballx1, data.dt.stage4_bally1);
	effm.effects.games.effstage4_ball2 = effm:Push(false, EFF_BALL,
		data.dt.stage4_ballx2, data.dt.stage4_bally2);
	effm.effects.games.effstage4_ball3 = effm:Push(false, EFF_BALL,
		data.dt.stage4_ballx3, data.dt.stage4_bally3);
	effm.effects.games.effstage4_ball4 = effm:Push(false, EFF_BALL,
		data.dt.stage4_ballx4, data.dt.stage4_bally4);
	effm.effects.games.effstage4_ball5 = effm:Push(false, EFF_BALL,
		data.dt.stage4_ballx5, data.dt.stage4_bally5);
	effm.effects.games.effstage4_ball6 = effm:Push(false, EFF_BALL,
		data.dt.stage4_ballx6, data.dt.stage4_bally6);
end

function Process:_RenderStart_Stage4()
	
	local arrange = HGETEXT_CENTER;
	local tx = data.dt.stage4_w * 2 / 3 + data.dt.stage4_x;
	local ty = data.dt.stage4_yfirst + data.dt.stage4_yoffset * 0.5;
	local tyoffset = data.dt.stage4_yoffset * 2;
	hgeFont.printf(self.gamefont, tx, ty, arrange, "Up");
	hgeFont.printf(self.gamefont, tx, ty + tyoffset, arrange, "Down");
	
	local games = spim.sprites.games;
	if games == nil then
		return;
	end
	spim:RenderItem(games.spstage4_string);
	spim:RenderItem(games.spstage4_player);
	spim:RenderItem(games.spstage4_line1);
	spim:RenderItem(games.spstage4_line2);
	spim:RenderItem(games.spstage4_line3);
	spim:RenderItem(games.spstage4_line4);
	spim:RenderItem(games.spstage4_line5);
	spim:RenderItem(games.spstage4_line6);
	
	games = effm.effects.games;
	if games == nil then
		return;
	end
	
	effm:RenderItem(games.effstage4_ball1);
	effm:RenderItem(games.effstage4_ball2);
	effm:RenderItem(games.effstage4_ball3);
	effm:RenderItem(games.effstage4_ball4);
	effm:RenderItem(games.effstage4_ball5);
	effm:RenderItem(games.effstage4_ball6);
end