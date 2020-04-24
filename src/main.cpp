#include "taskhunter.h"

int main(int argc, char** argv)
{
	TaskHunter th = TaskHunter();

	th.HandleArgv(argc, argv);	

	return 0;
}
