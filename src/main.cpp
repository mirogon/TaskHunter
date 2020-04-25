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
	TaskHunter th = TaskHunter();

	th.HandleArgv(argc, argv);	

	return 0;
}
