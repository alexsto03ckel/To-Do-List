#pragma once
#include <vector>
#include <string>
using namespace std;

struct Task
{
	string description;
	bool done;

};

void SaveTasksToFile(const vector<Task>& tasks, const string& fileName); //Tasks a vector of tasks and the string file name
vector<Task> LoadTasksFromFile(const string& fileName); //Return a vector of tasks and takes the file name as parameter.