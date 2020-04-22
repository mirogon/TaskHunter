#pragma once
#include "global.h"

class Task
{
public:

	Task() = delete;
	Task(uint32_t pTaskID, std::string pTaskDescription, std::string pTaskCategory = "");
	~Task() = default;

	void			SetTaskID(uint32_t pNewTaskID);
	void			SetTaskDescription(std::string pNewTaskDescription);
	void			SetTaskCategory(std::string pNewCategory);

	uint32_t 		GetTaskID();
	std::string 	GetTaskDescription();
	std::string 	GetTaskCategory();

private:

	uint32_t 		mTaskID;
	std::string 	mTaskCategory;
	std::string 	mTaskDescription;

};
