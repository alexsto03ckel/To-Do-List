#include "Task.h"
#include<string>
#include<vector>
#include<filesystem>
#include<fstream>
#include<algorithm>
using namespace std;

void SaveTasksToFile(const vector<Task>& tasks, const string& fileName)
{
	ofstream ostream(fileName); //ofstream se utiliza para escribir datos en un archivo
								//crea un objeto llamado ostream que se utiliza para abrir un archivo
								//con el nombre especifico 'fileName'
	ostream << tasks.size(); //escribe en el archivo la cantidad de tareas que se encuentran
							 //en el vector 'tasks'. << es para enviar los datos al flujo de salida de ostream
	
	for (const Task& task : tasks) //range of items over the loop will iterate.
	{
		string description = task.description; //object task
		replace(description.begin(), description.end(), ' ', '_'); //reemplazaría todos los espacios en blanco por guiones bajos dentro de este rango para guardar como un string 

		ostream << '\n' << description << ' ' << task.done; //escribe la tarea y 1/0
	}

}

vector<Task> LoadTasksFromFile(const string& fileName) //pass the file into a vector of task objects
{
	if (!filesystem::exists(fileName)) //check if the given file exists or not
	{
		return vector<Task>(); //return an empty vector
	}
	vector<Task> tasks; //create an empty vector for the tasks
	ifstream istream(fileName); //declares an input file stream istream and opens the file
								//specified by fileName for reading.

	int n;
	istream >> n; //the function reads an integer value n from the file stream istream. 
				  //This value represents the number of tasks stored in the file.

	for (int i = 0; i < n; i++)
	{
		string description;
		bool done;
		istream >> description >> done; //>> operator is used, it reads the next available data from the file, ensuring that different values are read in each iteration.
		replace(description.begin(), description.end(), '_', ' ');
		tasks.push_back(Task{ description, done }); //task object is created and adding to the vector 'tasks' and add the task to the vector.

	}
	return tasks; //return the final vector
}