
luastate = 	{
							DoFile	=	LuaFn_LuaState_DoFile;
						}
						
luastate.DoFile("Script/Const.lua");

hge	=	{
				System_SetState = LuaFn_hge_System_SetState;
			}
			
luastate.DoFile("Script/CallBack.lua");