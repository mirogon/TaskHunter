#include "task.h"

Task::Task(uint32_t pTaskID, std::string pTaskDescription, std::string pTaskCategory)
{
	SetTaskID(pTaskID);

	if (!SetTaskDescription(pTaskDescription))
	{
		mTaskDescription[0] = '\0';
		std::cout << "Error: Task description is too long!" << std::endl;
	}

	if (!SetTaskCategory(pTaskCategory))
	{
		mTaskCategory[0] = '\0';
		std::cout << "Error: Task category is too long!" << std::endl;
	}

	mIsActive = false;

}
void Task::SetTaskID(uint32_t pNewTaskID)
{
	mTaskID = pNewTaskID;
}

bool Task::SetTaskDescription(std::string pNewTaskDescription)
{
	if (pNewTaskDescription.size() > LENGTH_TASKDESCRIPTION)
	{
		return false;
	}
	strcpy(mTaskDescription, pNewTaskDescription.c_str());
	return true;
}

bool Task::SetTaskCategory(std::string pNewCategory)
{
	if (pNewCategory.size() > LENGTH_TASKCATEGORY)
	{
		return false;
	}
	strcpy(mTaskCategory, pNewCategory.c_str());
	return true;
}

void Task::Activate()
{
	mIsActive = true;
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

bool Task::IsActive()
{
	return mIsActive;
}
