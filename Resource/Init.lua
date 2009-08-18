luaFileTable	=	{
									"Script/Const.lua",
									"Script/Global.lua",
									"Script/CallBack.lua"
								}
								
function luaDoFiles()
	local tablelength = luastate.GetTableCount(luaFileTable);
	for i=1, tablelength do
		local iret = luastate.DoFile(luaFileTable[i]);
		if iret ~= 0 then
			return false;
		end
	end
	return true;
end

function SystemInitial()
	if luaDoFiles() == false then
		return false;
	end
	
	if hge.System_GetState(HGE_LOGFILE) == "" then
		hge.System_SetState(HGE_LOGFILE, "LuaEngine.log");
	end
	hge.System_SetState(HGE_HIDEMOUSE, false);
	hge.System_SetState(HGE_DONTSUSPEND, true);
	hge.System_SetState(HGE_SHOWSPLASH, false);

	time = 0;
	return true;
end