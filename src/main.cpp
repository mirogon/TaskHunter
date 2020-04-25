#include "taskhunter.h"

int main(int argc, char** argv)
{

	/*PATH_BINARY = argv[0];
	
	for (int i = PATH_BINARY.size() -1 ; i > 0; --i)
	{
		if (PATH_BINARY.at(i) == '/')
		{
			break;
		}
		else
		{
			PATH_BINARY.pop_back();
			PATH_BINARY.shrink_to_fit();
		}
	}

	PATH_BINARY += "TaskHunter.m1data";
	*/

	//Get %APPDATA% path
	CHAR rpath[MAX_PATH];

	HRESULT result = SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_DEFAULT, rpath);
	
	if (result != S_OK)
	{
		std::cout << "Error: " << result << std::endl;
		exit(-1);
	}

	std::cout << rpath << std::endl;
	
	//Cast to string and add filename
	PATH_SERIALIZATION = rpath;

	PATH_SERIALIZATION += "\taskhunter.m1data";

	TaskHunter th = TaskHunter();

	th.HandleArgv(argc, argv);	

	return 0;
}
