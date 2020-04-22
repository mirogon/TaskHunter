#include "task.h"

class TaskHunter
{
	public:

	TaskHunter();
	~TaskHunter();

	void HandleArgv(int 

	void AddTask(Task pNewTask);
	void DeleteTask(uint32_t pTaskID);	
	void PrintTasks();

	std::vector<Task> GetTasks();
	
	private:

	std::vector<Task> mTasks;
}
