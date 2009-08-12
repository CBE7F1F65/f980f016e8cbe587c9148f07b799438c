#include "vld.h"

#include "../Header/Main.h"
#include "../Header/Process.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	mp.ClientInitial();

/*
	LuaStateOwner state;

	int iret = state->DoFile("C:/test.lua");
	LuaFunction<bool> MyAdd = state->GetGlobal("Add");
	int mytest = state->GetGlobal("health").GetInteger();
	float myret = MyAdd(3.14f,5.25f);

	string filename = "c:/test.table";
	string format = "ddddddddffddddDS";
	string otherfilename = "c:/test2.table";
	DWORD handle = filefactory.OpenTableFile(filename, format);
	DWORD set = filefactory.FindTableFile(handle);
	filefactory.SetTableFileName(set, otherfilename);
	filefactory.SetStringTableFile(set, 38, 16, otherfilename);
	filefactory.CloseTableFile(handle);
*/

	//
	mp.Release();

	return 0;
}