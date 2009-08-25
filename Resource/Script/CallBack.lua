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
	if hge.Input_GetDIKey(DIK_BACK, DIKEY_DOWN) then
		luastate.Reload();
		return false;
	end
	if hge.Input_GetDIKey(mp.keyEscape) then
		return true;
	end
	if hge.Input_GetDIKey(mp.keyCapture, DIKEY_DOWN) then
		mp:SnapShot();
	end
	if mp:Frame() == PQUIT then
		return true;
	end
	return false;
end

function hgeRenderFunc()
	hge.Gfx_BeginScene();
	hge.Gfx_Clear(0);
	
	mp:Render();

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
	mp:Release();
	return true;
end