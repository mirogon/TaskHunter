#pragma once
#include "task.h"

class TaskHunter
{
public:

	TaskHunter();
	~TaskHunter() = default;

	void HandleArgv(int pArgc, char** pArgv);
	void AddTask(Task pNewTask);
	void DeleteTask(uint32_t pTaskID);
	void PrintTasks();

	std::vector<Task> GetTasks();

private:

	//void SerializeInTasks();

	std::vector<Task> mTasks;
};
