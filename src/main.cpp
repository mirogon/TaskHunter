#include "taskhunter.h"

int main(int argc, char** argv)
{

	PATH_BINARY = argv[0];
	
	for (auto i = PATH_BINARY.end() - 1; i != PATH_BINARY.begin(); --i)
	{
		if (*i == '/')
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

	TaskHunter th = TaskHunter();

	th.HandleArgv(argc, argv);	

	return 0;
}
