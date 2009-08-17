#include "../Header/Process.h"

#ifdef __NOTUSELUA

int time=0;
HEFFECT snd=0;
float x=0;
float y=0;
float dx=0;
float dy=0;
float friction=0.98f;
float speed=90;
hgeQuad quad;
float fps=0;
hgeFont * font=0;
#define MAXEFF 40
hgeEffectSystem * eff=0;
hgeEffectSystem * effs[MAXEFF]={0};

void boom(HGE * hge)
{
	float pan = (x-400)/4;
	float pitch = (dx*dx+dy*dy)*0.0005f+0.2f;
	hge->Effect_PlayEx(snd, 100, pan, pitch);
}

bool Process::FrameFuncSelf()
{
	if (hge->Input_GetDIKey(DIK_BACK))
	{
		time = 0;
	}
	if (time == 0)
	{
		hge->System_SetState(HGE_LOGFILE, "LuaEngineSelf.log");
		hge->System_SetState(HGE_HIDEMOUSE, false);

		font = new hgeFont("font.fnt");
		fontList.push_back(font);
		snd = hge->Effect_Load("menu.wav");

		quad.tex = hge->Texture_Load("particles.png");
		eff = new hgeEffectSystem("EffectSystem_038.effect", quad.tex);
		esList.push_back(eff);
		eff->Fire();
		for (int i=0; i<MAXEFF; i++)
		{
			effs[i] = new hgeEffectSystem(*eff);
			esList.push_back(effs[i]);
			effs[i]->Fire();
		}
		quad.blend = 4;
		for (int i=0; i<4; i++)
		{
			quad.v[i].col = 0xffffa000;
		}	
		quad.v[0].tx=96.0f/128.0f; quad.v[0].ty=64.0f/128.0f;
		quad.v[1].tx=128.0f/128.0f; quad.v[1].ty=64.0f/128.0f;
		quad.v[2].tx=128.0f/128.0f; quad.v[2].ty=96.0f/128.0f;
		quad.v[3].tx=96.0f/128.0f; quad.v[3].ty=96.0f/128.0f;
	}
	float dt = hge->Timer_GetDelta();
	if (hge->Input_GetDIKey(DIK_ESCAPE))
	{
		return true;
	}
	if (hge->Input_GetDIKey(DIK_LEFT))
		dx=dx-speed*dt;
	if (hge->Input_GetDIKey(DIK_RIGHT))
		dx=dx+speed*dt;
	if (hge->Input_GetDIKey(DIK_UP))
		dy=dy-speed*dt;
	if (hge->Input_GetDIKey(DIK_DOWN))
		dy=dy+speed*dt;

	dx = dx * friction;
	dy = dy * friction;
	x = x + dx;
	y = y + dy;
	if (x > 784)
	{
		x = 784 - (x-784);
		dx = -dx;
		boom(hge);
	}
	if (x < 16)
	{
		x = 16 + (16-x);
		dx = -dx;
		boom(hge);
	}
	if (y > 584)
	{
		y = 584 - (y-584);
		dy = -dy;
		boom(hge);
	}
	if (y < 16)
	{
		y = 16 + (16-y);
		dy = -dy;
		boom(hge);
	}

	quad.v[0].x=x-16; quad.v[0].y=y-16;
	quad.v[1].x=x+16; quad.v[1].y=y-16;
	quad.v[2].x=x+16; quad.v[2].y=y+16;
	quad.v[3].x=x-16; quad.v[3].y=y+16;

	eff->MoveTo(x, y);
	eff->Update();
	for (int i=0; i<MAXEFF; i++)
	{
		int randx = hge->Random_Int(-50, 50);
		int randy = hge->Random_Int(-50, 50);
		effs[i]->MoveTo(x+randx, y+randy);
		effs[i]->Update();
	}

	time = time + 1;

	fps = hge->Timer_GetFPS(35);
	return false;
}

bool Process::RenderFuncSelf()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);

	if (time > 0)
	{
		hge->Gfx_RenderQuad(&quad);
		eff->Render();
		for (int i=0; i<MAXEFF; i++)
		{
			effs[i]->Render();
		}
		font->printf(16,16,0,"%f",fps);
	}
	hge->Gfx_EndScene();
	return false;
}

bool Process::FocusLostFuncSelf()
{
	return false;
}

bool Process::FocusGainFuncSelf()
{
	return false;
}

bool Process::GfxRestoreFuncSelf()
{
	return false;
}

bool Process::ExitFuncSelf()
{
	return true;
}

#endif