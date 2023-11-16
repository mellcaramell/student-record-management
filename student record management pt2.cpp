/*
	Filename:StudentRecordManagement.cpp
	Date:11 November 2023
	Programmer: mell
	Description: 

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Function prototypes
void inputStudentData(int[], string[], double[], int[], int&);
double calculateAverageScores(const double[], int);
void displayStudentRecords(const int[], const string[], const double[], const int[], int, double);

int main() {
    // Arrays to store student data
    int studentID[50];
    string studentName[50];
    double scores[50];
    int attendance[50];

    // Number of students
    int numStudents = 0;

    // Menu-driven program
    int choice;
    do {
        // Display menu
        cout << "\nHigh School Student Records\n";
        cout << "1. Input Student Data\n";
        cout << "2. Calculate Average Scores\n";
        cout << "3. Display Student Records\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Perform the selected operation
        switch (choice) {
            case 1:
                // Input student data
                inputStudentData(studentID, studentName, scores, attendance, numStudents);
                break;
            case 2:
                // Calculate average scores
                if (numStudents > 0) {
                    double average = calculateAverageScores(scores, numStudents);
                    cout << "Average Score: " << fixed << setprecision(2) << average << "\n";
                } else {
                    cout << "No student data available. Please input student data first.\n";
                }
                break;
            case 3:
                // Display student records
                if (numStudents > 0) {
                    displayStudentRecords(studentID, studentName, scores, attendance, numStudents, calculateAverageScores(scores, numStudents));
                } else {
                    cout << "No student data available. Please input student data first.\n";
                }
                break;
            case 4:
                // Exit the program
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to input student data
void inputStudentData(int studentID[], string studentName[], double scores[], int attendance[], int& numStudents) {
    cout << "Enter the number of students (up to " << 50 << "): ";
    cin >> numStudents;

    if (numStudents > 50) {
        cout << "Number of students exceeds the maximum limit. Setting to maximum limit.\n";
        numStudents = 50;
    }

    cout << "Enter student data:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "  ID: ";
        cin >> studentID[i];

        cout << "  Name: ";
        cin.ignore(); // Clear newline character from previous input
        getline(cin, studentName[i]);

        cout << "  Scores: ";
        cin >> scores[i];

        cout << "  Attendance (%): ";
        cin >> attendance[i];
    }
} //end of input student data

// Function to calculate average scores
double calculateAverageScores(const double scores[], int numStudents) {
    double sum = 0;
    for (int i = 0; i < numStudents; ++i) {
        sum += scores[i];
    }
    return (numStudents > 0) ? sum / numStudents : 0.0;
} // end of calculate average scores

// Function to display student records
void displayStudentRecords(const int studentID[], const string studentName[], const double scores[],
                            const int attendance[], int numStudents, double average) {
    cout << fixed << setprecision(2);

    // Display header
    cout << "\nStudent Records:\n";
    cout << "--------------------------------------------------\n";
    cout << "ID\tName\t\tScores\tAttendance\n";
    cout << "--------------------------------------------------\n";

    // Display student data
    for (int i = 0; i < numStudents; ++i) {
        cout << studentID[i] << "\t" << setw(15) << left << studentName[i] << "\t" 
                  << scores[i] << "\t" << attendance[i] << "%\n";
    }

    // Display average score
    cout << "--------------------------------------------------\n";
    cout << "Average Score: " << average << "\n";
} //end of display student records
