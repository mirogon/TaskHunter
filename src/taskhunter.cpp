#include "taskhunter.h"

TaskHunter::TaskHunter()
{
	mTasks = std::vector<Task>();
}

void TaskHunter::HandleArgv(int pArgc, char** pArgv)
{
	std::cout << "ARGC: " << pArgc << std::endl;

	std::vector<std::string> argvStrings;
	for (int i = 0; i < pArgc-1; ++i)
	{
		argvStrings.push_back(pArgv[i]);
	}

	if(pArgc <= 1)
	{
		PrintTasks();
	}

	else if (pArgc > 1)
	{
		if(argvStrings[1] == "add")
		{
			if (pArgc > 2)
			{
				Task newTask = Task(0, pArgv[2]);
				AddTask(newTask);
				PrintTasks();
			}
		}
		else
		{
			std::cout << "ARGV[1]" << pArgv[1] << std::endl;
		}
	}

}

void TaskHunter::AddTask(Task pNewTask)
{
	mTasks.push_back(pNewTask);
}

void TaskHunter::DeleteTask(uint32_t pTaskID)
{
	for(int i = 0; i < mTasks.size();++i)
	{
		if(mTasks.at(i).GetTaskID() == pTaskID)
		{
			mTasks.erase(mTasks.begin() + i);
		}
	}
}

void TaskHunter::PrintTasks()
{
	std::cout<<"ID  |  Category  |  Description"<<std::endl;

	short numExtraSpaces = 0;

	for(int i = 0; i <mTasks.size();++i)
	{
		uint32_t id = mTasks.at(i).GetTaskID();

		std::cout << id;


		//Calc extra spaces
		numExtraSpaces = 6;
		if (id > 1)
		{
			numExtraSpaces = 6;
		}
		if (id > 10)
		{
			numExtraSpaces = 5;
		}
		if (id > 100)
		{
			numExtraSpaces = 4;
		}
		if (id > 1000)
		{
			numExtraSpaces = 3;
		}

		//Cout extra spaces
		for (int i = 0; i < numExtraSpaces; ++i)
		{
			std::cout << " ";
		}

		std::cout << mTasks.at(i).GetTaskCategory();

		//Calc extra spaces
		numExtraSpaces = 13 - mTasks.at(i).GetTaskCategory().size();
		if (numExtraSpaces < 0)
		{
			numExtraSpaces = 0;
		}
		//Cout extra spaces
		for (int i = 0; i < numExtraSpaces; ++i)
		{
			std::cout << " ";
		}

		std::cout << mTasks.at(i).GetTaskDescription();

	}
}

std::vector<Task> TaskHunter::GetTasks()
{
	return mTasks;
}
