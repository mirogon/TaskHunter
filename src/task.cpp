#include "task.h"

Task::Task(uint32 pTaskID, std::string pTaskDescription, std::string pTaskCategory)
{
	mTaskID = pTaskID;
	mTaskDescription = pTaskDescription;
	mTaskCategory = pTaskCategory;
	
}
void Task::SetTaskID(uint32_t pNewTaskID)
{
	mTaskID = pNewTaskID
}

void Task::SetTaskDescription(std::string pNewTaskDescription)
{
	mTaskDescription = pNewTaskDescription;
}

void Task::SetTaskCategory(std::string pNewCategory)
{
	mTaskCategory=pNewCategory;
}

uint32_t Task::GetTaskID()
{
	return mTaskID;
}

std::string Task::GetTaskDescription()
{
	return mTaskDescription;
}

std::string Task::GetTaskCategory()
{
	return mTaskCategory;
}
