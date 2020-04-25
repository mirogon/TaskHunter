#include "taskhunter.h"

int main(int argc, char** argv)
{
	//Get %APPDATA% path
	CHAR rpath[MAX_PATH];

	HRESULT result = SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_DEFAULT, rpath);
	
	if (result != S_OK)
	{
		std::cout << "Error: " << result << std::endl;
		exit(-1);
	}
	
	//Cast to string and add filename
	PATH_SERIALIZATION = rpath;
	PATH_SERIALIZATION += "\\taskhunter.m1data";

	//Start TaskHunter
	TaskHunter th = TaskHunter();
	th.HandleArgv(argc, argv);	

	return 0;
}
