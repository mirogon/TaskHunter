#pragma once
#include "global.h"

class Task
{
public:

	Task() = delete;
	Task(uint32_t pTaskID, std::string pTaskDescription, std::string pTaskCategory = "");
	~Task() = default;

	void			SetTaskID(uint32_t pNewTaskID);
	bool			SetTaskDescription(std::string pNewTaskDescription);
	bool			SetTaskCategory(std::string pNewCategory);
	void			Activate();

	uint32_t 		GetTaskID();
	std::string 	GetTaskDescription();
	std::string 	GetTaskCategory();
	bool			IsActive();

private:

	uint32_t 		mTaskID;
	char 			mTaskCategory[LENGTH_TASKCATEGORY];
	char		 	mTaskDescription[LENGTH_TASKDESCRIPTION];

	bool			mIsActive;

};
