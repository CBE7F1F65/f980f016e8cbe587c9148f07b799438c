function Process:ProcessStart()
	
	time = time + 1;
	
	if time == 1 then

		font = hgeFont.NewFont("font.fnt");
		snd = hge.Effect_Load("menu.wav");
		hge.Effect_Play(snd);
		quad = hge.struct.hgeQuad();
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
			quad.v[i].z	=	0;
		end
		
		quad.v[1].tx=96.0/128.0; quad.v[1].ty=64.0/128.0;
		quad.v[2].tx=128.0/128.0; quad.v[2].ty=64.0/128.0;
		quad.v[3].tx=128.0/128.0; quad.v[3].ty=96.0/128.0;
		quad.v[4].tx=96.0/128.0; quad.v[4].ty=96.0/128.0;
		
		spitem = spim:NewSprite(SI_BATTLE_1);

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
	local edge = 16
	local redge = M_CLIENT_RIGHT - edge;
	if x > redge then
		x = redge - (x-redge);
		dx = -dx;
		boom();
	end
	local ledge = edge;
	if x < ledge then
		x = ledge + (ledge-x);
		dx = -dx;
		boom();
	end
	local bedge = M_CLIENT_BOTTOM - edge;
	if y > bedge then
		y = bedge - (y-bedge);
		dy = -dy;
		boom();
	end
	local tedge = edge;
	if y < tedge then
		y = tedge + (tedge-y);
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
	
	return PGO;
end