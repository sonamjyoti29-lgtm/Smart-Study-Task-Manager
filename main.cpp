/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string title;
    string priority;
    bool completed;

    Task(string t, string p) {
        title = t;
        priority = p;
        completed = false;
    }
};

void showTasks(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n========== TASK LIST ==========\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].title
             << " | Priority: " << tasks[i].priority
             << " | Status: "
             << (tasks[i].completed ? "Done" : "Pending")
             << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n===== SMART STUDY TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. Show Tasks\n";
        cout << "3. Mark Task Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore();   // Clear buffer

        switch (choice) {

        case 1: {
            string title, priority;

            cout << "Enter Task Title: ";
            getline(cin, title);

            cout << "Enter Priority (High/Medium/Low): ";
            getline(cin, priority);

            tasks.push_back(Task(title, priority));
            cout << "Task Added Successfully!\n";
            break;
        }

        case 2:
            showTasks(tasks);
            break;

        case 3: {
            if (tasks.empty()) {
                cout << "No tasks to update.\n";
                break;
            }

            showTasks(tasks);
            int num;
            cout << "Enter task number to mark completed: ";
            cin >> num;

            if (num > 0 && num <= tasks.size()) {
                tasks[num - 1].completed = true;
                cout << "Task marked as completed!\n";
            } else {
                cout << "Invalid task number.\n";
            }
            break;
        }

        case 4: {
            if (tasks.empty()) {
                cout << "No tasks to delete.\n";
                break;
            }

            showTasks(tasks);
            int num;
            cout << "Enter task number to delete: ";
            cin >> num;

            if (num > 0 && num <= tasks.size()) {
                tasks.erase(tasks.begin() + num - 1);
                cout << "Task deleted successfully!\n";
            } else {
                cout << "Invalid task number.\n";
            }
            break;
        }

        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}