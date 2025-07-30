#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string department;
    double salary;

public:
    Employee(int empId, string empName, string empDept, double empSalary) {
        id = empId;
        name = empName;
        department = empDept;
        salary = empSalary;
    }

    int getId() const {
        return id;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Department: " << department
             << ", Salary: $" << salary << endl;
    }

    void update(string newName, string newDept, double newSalary) {
        name = newName;
        department = newDept;
        salary = newSalary;
    }
};

class EmployeeManager {
private:
    vector<Employee> employees;

public:
    void addEmployee() {
        int id;
        string name, dept;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Department: ";
        getline(cin, dept);
        cout << "Enter Salary: ";
        cin >> salary;

        employees.push_back(Employee(id, name, dept, salary));
        cout << "Employee added successfully!\n";
    }

    void displayEmployees() const {
        if (employees.empty()) {
            cout << "No employees to show.\n";
            return;
        }

        for (const auto& emp : employees) {
            emp.display();
        }
    }

    void searchEmployee() const {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;

        bool found = false;
        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                emp.display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Employee not found.\n";
    }

    void updateEmployee() {
        int id;
        cout << "Enter ID to update: ";
        cin >> id;

        for (auto& emp : employees) {
            if (emp.getId() == id) {
                string newName, newDept;
                double newSalary;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, newName);
                cout << "Enter new department: ";
                getline(cin, newDept);
                cout << "Enter new salary: ";
                cin >> newSalary;

                emp.update(newName, newDept, newSalary);
                cout << "Employee updated successfully!\n";
                return;
            }
        }

        cout << "Employee not found.\n";
    }

    void deleteEmployee() {
        int id;
        cout << "Enter ID to delete: ";
        cin >> id;

        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getId() == id) {
                employees.erase(it);
                cout << "Employee deleted successfully!\n";
                return;
            }
        }

        cout << "Employee not found.\n";
    }
};

int main() {
    EmployeeManager manager;
    int choice;

    do {
        cout << "\n=== Employee Management System ===\n";
        cout << "1. Add Employee\n";
        cout << "2. Display All Employees\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Update Employee\n";
        cout << "5. Delete Employee\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addEmployee(); break;
            case 2: manager.displayEmployees(); break;
            case 3: manager.searchEmployee(); break;
            case 4: manager.updateEmployee(); break;
            case 5: manager.deleteEmployee(); break;
            case 0: cout << "Exiting program.\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
