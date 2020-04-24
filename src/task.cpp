#include "task.h"

Task::Task(uint32_t pTaskID, std::string pTaskDescription, std::string pTaskCategory)
{
	mTaskID = pTaskID;

	strcpy(mTaskDescription, pTaskDescription.c_str());
	strcpy(mTaskCategory, pTaskCategory.c_str());
	
}
void Task::SetTaskID(uint32_t pNewTaskID)
{
	mTaskID = pNewTaskID;
}

void Task::SetTaskDescription(std::string pNewTaskDescription)
{
	strcpy(mTaskDescription, pNewTaskDescription.c_str());
}

void Task::SetTaskCategory(std::string pNewCategory)
{
	strcpy(mTaskCategory, pNewCategory.c_str());
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
