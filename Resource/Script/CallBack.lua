snd=0;
x=0;
y=0;
dx=0;
dy=0;
friction=0.98
speed=90;
quad={};
fps=0;
font=0;
MAXEFF=0;
eff=0;
effs={};

function boom()
	local pan = (x-400)/4;
	local pitch = (dx*dx+dy*dy)*0.0005+0.2;
	hge.Effect_Play(snd, 100, pan, pitch);
end

function hgeFrameFunc()
	if hge.Input_GetDIKey(DIK_BACK) then
		luastate.DoFile("Init.lua");
		SystemInitial();
	end
	if time == 0 then

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
		quad.blend = 4;
		
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

	if hge.Input_GetDIKey(DIK_ESCAPE) then
		return true;
	end
	if hge.Input_GetDIKey(DIK_LEFT) then
		dx=dx-speed*dt;
	end
	if hge.Input_GetDIKey(DIK_RIGHT) then
		dx=dx+speed*dt;
	end
	if hge.Input_GetDIKey(DIK_UP) then
		dy=dy-speed*dt;
	end
	if hge.Input_GetDIKey(DIK_DOWN) then
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

	time = time + 1;
	
	fps = hge.Timer_GetFPS(35);
	
	return false;
end

function hgeRenderFunc()
	hge.Gfx_BeginScene();

	hge.Gfx_Clear(0);

	if time > 0 then
		hge.Gfx_RenderQuad(quad);
		hgeES.Render(eff);
		for i=1,MAXEFF do
			hgeES.Render(effs[i]);
		end
		hgeFont.printf(font,16,16,0,fps);
	end

	hge.Gfx_EndScene();
	return false;
end

function hgeFocusLostFunc()
	return true;
end

function hgeFocusGainFunc()
	return true;
end

function hgeGfxRestoreFunc()
	return true;
end

function hgeExitFunc()
	return true;
end