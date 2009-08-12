function SystemInitial()
	hge.System_SetState(hgeConst.HGE_LOGFILE, "LuaEngine.log");
	hge.System_SetState(hgeConst.HGE_HIDEMOUSE, false);
	return true;
end
function hgeFrameFunc()
	return false;
end
function hgeRenderFunc()
	return false;
end
function hgeFocusLostFunc()
	return false;
end
function hgeFocusGainFunc()
	return false;
end
function hgeGfxRestoreFunc()
	return false;
end
function hgeExitFunc()
	return true;
end