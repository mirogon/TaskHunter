#include "tashhunter.h"

TaskHunter::TaskHunter()
{
	mTasks = std::vector<Task>();
}

void TaskHunter::AddTask(Task pNewTask)
{
	mTasks.push_back(pNewTask);
}
void TaskHuner::DeleteTask(uint32_t pTaskID)
{
	for(int i = 0; i < mTasks.size(); ++i)
	{
		if(mTasks.at(i).GetTaskID == pTaskID)
		{
			mTasks.erase(mTasks.begin() + i);
		}
	}
}
void TaskHunter::PrintTasks()
{
	std::cout<<"ID  |  Category  |  Description
	for(int i = 0; i <mTasks.size();++i)
	{
		std::cout<<mTasks.at(i).GetTaskID<<"  "<<mTasks.at(i).GetTaskCategory<<"  "<<mTasks.at(i).GetTaskDescription()<<std::endl;
	}
}

std::vector<Task> TaskHunter::GetTasks()
{
	return mTasks;
}
