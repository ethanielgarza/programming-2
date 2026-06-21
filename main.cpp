// AI Usage: Moderate
// I used AI to help debug my code and explain STL algorithms.
// All design decisions, implementation, and testing are my own work.



//loadTasks()
// saveTasks()
// addTask()
// deleteTask()
// printTasks()
// showStatistics()



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <limits>


struct Task
{
    std::string title;
    std::string category;
    int priority;
    bool completed;
};


void addTask(std::vector<Task>& tasks)
{
    Task temp;

    std::cout << "Title: ";
    std::getline(std::cin, temp.title);

    std::cout << "Category: ";
    std::getline(std::cin, temp.category);

    std::cout << "Priority: ";
    std::cin >> temp.priority;

    temp.completed = false;

    tasks.push_back(temp);

}

void printTasks(const std::vector<Task>& tasks)
{
    for(size_t i = 0; i < tasks.size(); i++)
    {
        std::cout << i + 1 
        << ". " 
        << tasks.at(i).title 
        <<" | " 
        << tasks.at(i).category
        << " | Priority "
        << tasks.at(i).priority
        << " | Completed: "
        <<(tasks.at(i).completed ? "Yes" : "No") 
        << "\n";
    }

}

void markComplete(std::vector<Task>& tasks)
{
    int num;

    std::cout << "Enter task number: ";
    std::cin >> num;

    if (num >= 1 && num <= static_cast <int>(tasks.size()))
    {
        tasks.at(num - 1).completed = true; // change from brackets.
    }
}

void deleteTask(std::vector<Task>& tasks)
{
    int num;
    
    std::cout << "Enter task number: ";
    std::cin >> num;

    if ((num >= 1 && num <= static_cast <int>(tasks.size())))
    {
        tasks.erase(tasks.begin() + (num - 1));
    }

}
void searchTasks(const std::vector<Task>& tasks)
{
    std::string title;

    std::cout << "Enter title: ";
    std::getline(std::cin, title);

    auto found = std::find_if(tasks.begin(), tasks.end(),[&](const Task& t)
    {
        return t.title == title;
    }); 

    if (found != tasks.end())
    {
        std::cout << "Task Found!" << "\n";
    }

    else
    {
        std::cout << "Task Not Found!" << "\n";
    }
}

void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b)
    {
        return a.priority > b.priority;
    });
}

void showStatistics(const std::vector<Task>& tasks)
{
    int completed = std::count_if(tasks.begin(), tasks.end(), [](const Task& t)
    {
        return t.completed;
    });

    int remaining = tasks.size() - completed;

    std::cout << "Completed Tasks: " << completed << "\n";

    std::cout << "Remaining Tasks: " << remaining << "\n";
}

void saveTasks(const std::vector<Task>& tasks)
{
    std::ofstream fout ("tasks.txt");
}
void loadTasks(std::vector<Task>& tasks)
{
    std::ifstream fin ("tasks.txt");
}

int printMenu()
{
    int userInput;

    std::cout << std::string(65, '=') << std::endl;
    std::cout << "To-Do List Manager" << "\n\n";
    std::cout << "1. Add Task" << "\n";
    std::cout << "2. View Tasks" << "\n";
    std::cout << "3. Mark Task Complete" << "\n";
    std::cout << "4. Delete Task" << "\n";
    std::cout << "5. Search Tasks" << "\n";
    std::cout << "6. Sort Tasks" << "\n";
    std::cout << "7. Show Statistics" << "\n";
    std::cout << "8. Save and Exit" << "\n";
    std::cout << std::string(65, '=') << std::endl;

    std::cout << "Enter a choice(1-8): ";
    std::cin >> userInput;

    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }

    return userInput;
  
}

int main ()
{
    std::vector <Task> tasks;

    while (true)
    {
        int choice = printMenu();


        if (choice == 1)
        {
            // add task.
            addTask(tasks);
        }

        else if (choice == 2)
        {
            // view tasks.
            printTasks(tasks);
        }

        else if (choice == 3)
        {
            // mark task complete.
            markComplete(tasks);
        }

        else if(choice == 4)
        {
            // delete task.
            deleteTask(tasks);
        }

        else if (choice == 5)
        {
            // search tasks.
            searchTasks(tasks);
        }

        else if (choice == 6)
        {
            // sort tasks.
            sortTasks(tasks);
        }

        else if (choice == 7)
        {
            // show stats.
            showStatistics(tasks);
        }

        else if (choice == 8)
        {
            std::cout << "Exiting program." << std::endl;
            break;
        }

        else
        {
            std::cout << "Invalid Input. Try again" << std::endl;
        }
    }
    return 0;
}