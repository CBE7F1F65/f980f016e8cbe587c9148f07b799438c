#include "../Header/Main.h"

#include "../Header/DataFactory.h"
#include "../Header/FileFactory.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	LuaStateOwner state;

	int iret = state->DoFile("C:/test.lua");
	LuaFunction<float> MyAdd = state->GetGlobal("Add");
	int mytest = state->GetGlobal("health").GetInteger();
	float myret = MyAdd(3.14f,5.25f);

	printf("%d\t%f\n", mytest, myret);


	int n = datafactory.NewByteData();
	int m = datafactory.NewByteData(100);
	datafactory.SetByteData(n, 10, 76);
	datafactory.CopyByteData(n, m);
	int l = datafactory.GetByteData(m, 10, 0);

	string filename = "c:/test.table";
	string format = "dddbbbbbffbbddBS";
//	string otherfilename = "c:/test2.table";
	DWORD handle = filefactory.OpenTableFile(filename, format);
//	DWORD set = filefactory._FindTableFile(handle);
//	filefactory.tablefiledata.SetStringData(set, 0, otherfilename, true);
//	filefactory.tablefiledata.SetStringData(set, 50, otherfilename, true);
	filefactory.CloseTableFile(handle);

	return 0;
}