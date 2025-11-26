#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Task {
    int id;
    string description;
    string status; // "Pending" or "Completed"
};

vector<Task> loadTasks() {
    vector<Task> tasks;
    ifstream file("tasks.txt");

    if (!file) return tasks; // File may not exist initially

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, desc, status;
        
        getline(ss, idStr, '|');
        getline(ss, desc, '|');
        getline(ss, status, '|');
        
        tasks.push_back({ stoi(idStr), desc, status });
    }
    return tasks;
}

void saveTasks(const vector<Task>& tasks) {
    ofstream file("tasks.txt");

    for (const auto &t : tasks) {
        file << t.id << "|" << t.description << "|" << t.status << "\n";
    }
}

void addTask() {
    vector<Task> tasks = loadTasks();

    Task t;
    t.id = tasks.size() + 1;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, t.description);
    t.status = "Pending";

    tasks.push_back(t);
    saveTasks(tasks);

    cout << "Task added successfully!\n";
}

void viewTasks() {
    vector<Task> tasks = loadTasks();

    cout << "\n--- To-Do List ---\n";
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    for (const auto &t : tasks) {
        cout << t.id << ". " << t.description 
             << " [" << t.status << "]\n";
    }
}

void markTaskCompleted() {
    vector<Task> tasks = loadTasks();
    int id;
    cout << "Enter task ID to mark as completed: ";
    cin >> id;

    bool found = false;

    for (auto &t : tasks) {
        if (t.id == id) {
            t.status = "Completed";
            found = true;
            break;
        }
    }

    if (found) {
        saveTasks(tasks);
        cout << "Task marked as completed!\n";
    } else {
        cout << "Task not found.\n";
    }
}

void deleteTask() {
    vector<Task> tasks = loadTasks();
    int id;
    cout << "Enter task ID to delete: ";
    cin >> id;

    bool found = false;

    vector<Task> updatedTasks;
    for (auto &t : tasks) {
        if (t.id == id) {
            found = true;
            continue; // skip this task
        }
        updatedTasks.push_back(t);
    }

    // Reassign IDs after deletion
    for (int i = 0; i < updatedTasks.size(); i++) {
        updatedTasks[i].id = i + 1;
    }

    if (found) {
        saveTasks(updatedTasks);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Task not found.\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===== TO-DO TASK MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskCompleted(); break;
            case 4: deleteTask(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}
