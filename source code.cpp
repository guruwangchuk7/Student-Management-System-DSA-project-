#include <iostream>
#include <string>

using namespace std;

// Structure to hold student information
struct Student {
    string name;
    string gender;
    string UID;
    string studentClass;
    int semester;
};

// Function to display student information
void displayStudent(const Student& student) {
    cout << "Name: " << student.name << endl;
    cout << "Gender: " << student.gender << endl;
    cout << "UID: " << student.UID << endl;
    cout << "Class: " << student.studentClass << endl;
    cout << "Semester: " << student.semester << endl;
    cout << "---------------------\n";
}

// Function to add a new student
void addStudent(Student students[], int& studentCount, const int maxStudents) {
    if (studentCount >= maxStudents) {
        cout << "Cannot add more students. Maximum limit reached.\n";
        return;
    }

    cout << "Enter student name: ";
    getline(cin >> ws, students[studentCount].name);
    cout << "Enter gender (male, female, other): ";
    getline(cin >> ws, students[studentCount].gender);
    cout << "Enter UID: ";
    getline(cin >> ws, students[studentCount].UID);
    cout << "Enter class: ";
    getline(cin >> ws, students[studentCount].studentClass);
    cout << "Enter semester: ";
    cin >> students[studentCount].semester;

    studentCount++;
    cout << "Student added successfully!\n";
}

// Function to display all students
void displayAllStudents(const Student students[], int studentCount) {
    cout << "\nStudent Database:\n";
    for (int i = 0; i < studentCount; ++i) {
        displayStudent(students[i]);
    }
}

// Function to find a student by UID
void findStudentByUID(const Student students[], int studentCount) {
    string UID;
    cout << "Enter UID to search: ";
    getline(cin >> ws, UID);

    bool found = false;
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].UID == UID) {
            displayStudent(students[i]);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No student found with UID: " << UID << endl;
    }
}

// Function to sort students by name (simple bubble sort)
void sortStudentsByName(Student students[], int studentCount) {
    for (int i = 0; i < studentCount - 1; ++i) {
        for (int j = 0; j < studentCount - i - 1; ++j) {
            if (students[j].name > students[j + 1].name) {
                swap(students[j], students[j + 1]);
            }
        }
    }
    cout << "Students sorted by name.\n";
}

int main() {
    const int maxStudents = 100; // Maximum number of students
    Student students[maxStudents];
    int studentCount = 0; // Current number of students
    int choice;

    do {
        cout << "\n--- Student Database Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Find Student by UID\n";
        cout << "4. Sort Students by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, studentCount, maxStudents);
                break;
            case 2:
                displayAllStudents(students, studentCount);
                break;
            case 3:
                findStudentByUID(students, studentCount);
                break;
            case 4:
                sortStudentsByName(students, studentCount);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
