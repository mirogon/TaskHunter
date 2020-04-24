#include "taskhunter.h"

TaskHunter::TaskHunter():

	mSerializer{PATH_SERIALIZATION }

{
	mTasks = std::vector<Task>();
	SerializeInTasks();
}

// taskhunter main_command main_command_parameter options
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
		
		if (pArgc > 2)
		{
			if (argvStrings[1] == "add")
			{
				Task newTask = Task(mTasks.size(), pArgv[2]);
				AddTask(newTask);
				PrintTasks();
			}

			else if (argvStrings[1] == "delete")
			{
				int id = std::stoi(pArgv[2]);
				
				if (id >= 0)
				{
					DeleteTask(id);
				}
			}

			else if (argvStrings[1] == "modify")
			{

			}
		}
	}
}

void TaskHunter::AddTask(Task pNewTask)
{
	mTasks.push_back(pNewTask);
	SerializeOutTasks();
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
	SerializeOutTasks();
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

		std::cout << mTasks.at(i).GetTaskDescription() << std::endl;
	}
}

std::vector<Task> TaskHunter::GetTasks()
{
	return mTasks;
}

void TaskHunter::SerializeInTasks()
{
	if ( m1::filesize(PATH_SERIALIZATION.c_str()) <= sizeof(Task) )
	{
		return;
	}

	m1::raw_serializer rsi = m1::raw_serializer(PATH_SERIALIZATION);

	uint16_t numTasks;
	rsi.serialize_in(numTasks);
	std::cout << "Serialize in numTasks: " << numTasks << std::endl;

	mTasks.clear();
	mTasks.shrink_to_fit();

	Task cache = Task(0, "", "");

	for (int i = 0; i < numTasks; ++i)
	{
		rsi.serialize_in(cache);
		mTasks.push_back(cache);
	}
}

void TaskHunter::SerializeOutTasks()
{
	m1::raw_serializer rso = m1::raw_serializer(PATH_SERIALIZATION, true, false);

	uint16_t numTasks;
	numTasks = mTasks.size();
	std::cout << "Serialize out numTasks: " << numTasks << std::endl;

	mSerializer.serialize_out(numTasks);

	for (int i = 0; i < mTasks.size(); ++i)
	{
		mSerializer.serialize_out(mTasks.at(i));
	}
}