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
	//std::cout << "ARGC: " << pArgc << std::endl;

	std::vector<std::string> argvStrings;
	for (int i = 0; i < pArgc; ++i)
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
				Task newTask{ static_cast<uint32_t>(mTasks.size()), pArgv[2]};
				if (pArgc > 3)
				{
					newTask = Task(static_cast<uint32_t>(mTasks.size()), pArgv[2], pArgv[3]);
				}
			
				AddTask(newTask);
				std::cout << "Added new Task" << std::endl;;
				PrintTasks();
			}

			else if (argvStrings[1] == "delete")
			{
				int id = std::stoi(pArgv[2]);
				
				if (id >= 0)
				{
					DeleteTask(id);
					std::cout << "Deleted Task with ID: " << id << std::endl;
					PrintTasks();
				}
			}

			else if (argvStrings[1] == "list")
			{
				PrintTasksFiltered(argvStrings[2]);
			}


			else if (argvStrings[1] == "activate")
			{
				int id = std::stoi(pArgv[2]);
				ActivateTask(id);
			}
			
		}
		else
		{
			if (argvStrings[1] == "list")
			{
				PrintTasks();
			}

			else if (argvStrings[1] == "active" || argvStrings[1] == "activated")
			{
				PrintActiveTasks();
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

	bool startDecrementing = false;

	for(int i = 0; i < mTasks.size();++i)
	{
		if(mTasks.at(i).GetTaskID() == pTaskID)
		{
			mTasks.erase(mTasks.begin() + i);
			mTasks.shrink_to_fit();
			startDecrementing = true;
		}

		if (startDecrementing && mTasks.size() > 1 && i < mTasks.size())
		{
			mTasks.at(i).SetTaskID(mTasks.at(i).GetTaskID() - 1);
		}
	}

	SerializeOutTasks();
}

void TaskHunter::ActivateTask(uint32_t pTaskID)
{
	for (int i = 0; i < mTasks.size(); ++i)
	{
		if (pTaskID == mTasks.at(i).GetTaskID())
		{
			mTasks.at(i).Activate();
			std::cout << "Activated Task with ID: " << pTaskID << std::endl;
		}
	}

	SerializeOutTasks();
}

void TaskHunter::PrintTasks()
{
	std::cout<<"ID  |  Category  |  Description"<<std::endl<<std::endl;

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

void TaskHunter::PrintTasksFiltered(std::string pCategory)
{
	std::cout << "ID  |  Category  |  Description" << std::endl << std::endl;

	short numExtraSpaces = 0;

	for (int i = 0; i < mTasks.size(); ++i)
	{

		if (mTasks.at(i).GetTaskCategory() != pCategory)
		{
			continue;
		}

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

void TaskHunter::PrintActiveTasks()
{
	std::cout << "ID  |  Category  |  Description" << std::endl << std::endl;

	short numExtraSpaces = 0;

	for (int i = 0; i < mTasks.size(); ++i)
	{

		if (!mTasks.at(i).IsActive())
		{
			continue;
		}

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

	mSerializer.serialize_out(numTasks);

	for (int i = 0; i < mTasks.size(); ++i)
	{
		mSerializer.serialize_out(mTasks.at(i));
	}
}