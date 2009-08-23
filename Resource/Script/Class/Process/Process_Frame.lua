function Process:Frame(self)
	
	if hge.Input_GetKeyState(HGEK_ALT) and hge.Input_GetKeyState(HGEK_ENTER) then
		mp.screenmode = not mp.screenmode;
		hge.System_SetState(HGE_WINDOWED, not mp.screenmode);
		hge.System_SetState(HGE_HIDEMOUSE, mp.screenmode);
	end
	
	mp:GetInput(mp);
		
	time = time + 1;
	
	if time == 1 then

		font = hgeFont.NewFont("font.fnt");
		snd = hge.Effect_Load("menu.wav");
		hge.Effect_Play(snd);
		quad	=	{
							v	=	{
										{x=1, y=0, z=0, col=0, tx=0, ty=0},
										{x=2, y=0, z=0, col=0, tx=0, ty=0},
										{x=3, y=0, z=0, col=0, tx=0, ty=0},
										{x=4, y=0, z=0, col=0, tx=0, ty=0}
									},
							tex = 0,
							blend = 0,
						};
		quad.tex = hge.Texture_Load("particles.png");
		eff = hgeES.NewES("EffectSystem_038.effect", quad.tex);
		hgeES.Fire(eff);
		for i=1,MAXEFF do
			effs[i] = hgeES.NewES(eff);
			hgeES.Fire(effs[i]);
		end
		quad.blend = BLEND_DEFAULT;
		
		local _col = global.ARGB(0xff, 0xffa000);
		for i=1, 4 do
			quad.v[i].col = _col;
		end
		
		quad.v[1].tx=96.0/128.0; quad.v[1].ty=64.0/128.0;
		quad.v[2].tx=128.0/128.0; quad.v[2].ty=64.0/128.0;
		quad.v[3].tx=128.0/128.0; quad.v[3].ty=96.0/128.0;
		quad.v[4].tx=96.0/128.0; quad.v[4].ty=96.0/128.0;

	end

	local dt = hge.Timer_GetDelta();

	if hge.Input_GetDIKey(mp.keyLeft) then
		dx=dx-speed*dt;
	end
	if hge.Input_GetDIKey(mp.keyRight) then
		dx=dx+speed*dt;
	end
	if hge.Input_GetDIKey(mp.keyUp) then
		dy=dy-speed*dt;
	end
	if hge.Input_GetDIKey(mp.keyDown) then
		dy=dy+speed*dt;
	end

	dx = dx * friction;
	dy = dy * friction;
	x = x + dx;
	y = y + dy;
	if x > 784 then
		x = 784 - (x-784);
		dx = -dx;
		boom();
	end
	if x < 16 then
		x = 16 + (16-x);
		dx = -dx;
		boom();
	end
	if y > 584 then
		y = 584 - (y-584);
		dy = -dy;
		boom();
	end
	if y < 16 then
		y = 16 + (16-y);
		dy = -dy;
		boom();
	end

	quad.v[1].x=x-16; quad.v[1].y=y-16;
	quad.v[2].x=x+16; quad.v[2].y=y-16;
	quad.v[3].x=x+16; quad.v[3].y=y+16;
	quad.v[4].x=x-16; quad.v[4].y=y+16;
	
	hgeES.MoveTo(eff, x, y);
	hgeES.Update(eff);
	for i=1,MAXEFF do
		local randx = hge.Random_Int(-50, 50);
		local randy = hge.Random_Int(-50, 50);
		hgeES.MoveTo(effs[i], x+randx, y+randy);
		hgeES.Update(effs[i]);
	end
	
	fps = hge.Timer_GetFPS(35);
	
	return false;
end