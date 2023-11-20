/*
	Filename   :StudentRecordManagement.cpp
	Date       :11 November 2023
	Programmer : mell, najihah, nadz, athirah, nabihah
	Description:This C++ program is designed for managing and analyzing student records at a 
			high school named "Starlight High School Student Records." The program provides a menu-driven 
			interface that allows users to perform various operations, including inputting student data, 
			calculating average scores, displaying student records, and finding students by using id.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// Function prototypes
void inputStudentData(int[], string[], double[], int[], int&);
double calculateAverageScores(const double[], int);
void displayStudentRecords(const int[], const string[], const double[], const int[], int, double);
void findStudent(const int[], const string[], const double[], const int[], int, int);

//najihah husna
//start of main
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
        cout << "\n Starlight High School Student Records\n";
        cout << "1. Input Student Data\n";
        cout << "2. Calculate Average Scores\n";
        cout << "3. Display Student Records\n";
        cout << "4. Find a Student by ID\n"; // Added option to find a student by ID
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
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
                // Find a student by ID
                if (numStudents > 0) {
                    int searchID;
                    cout << "Enter the student ID to search for: ";
                    cin >> searchID;
                    findStudent(studentID, studentName, scores, attendance, numStudents, searchID);
                } else {
                    cout << "No student data available. Please input student data first.\n";
                }
                break;
            case 5:
                // Exit the program
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
//end of main

//athirah m.faslee
// Function to input student data to collect user input for student data
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

    	cout<<"  Score: ";
		cin>>scores[i];
	
		while(scores[i] < 0 || scores[i] > 100){
		cout<<"Invalid score. Please enter a number between 0 and 100:";
		cin>>scores[i];
	}

	    cout << "  Attendance: ";
	    cin >> attendance[i];
	
	    while(attendance[i] < 0 || attendance[i] > 100){
		cout<<"Invalid score. Please enter a number between 0 and 100:";
		cin>>attendance[i];
	}
}

} //end of input student data

//nur nabihah
// Function to calculate average scores to calculate the everage score for all students
double calculateAverageScores(const double scores[], int numStudents) {
    double sum = 0;
    for (int i = 0; i < numStudents; ++i) {
        sum += scores[i];
    }
    return (numStudents > 0) ? sum / numStudents : 0.0;
} // end of calculate average scores

//nurain nadzirah
// Function to display student records to presents student information, including IDs, names, scores, attendance, and the calculated average score
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

//nur ku safiyyah (mell)
//functions to find student by insertind IDs number
void findStudent(const int studentID[], const string studentName[], const double scores[],
                 const int attendance[], int numStudents, int searchID) {
    bool found = false;

    for (int i = 0; i < numStudents; ++i) {
        if (studentID[i] == searchID) {
            cout << "Found student:\n";
            cout << "ID: " << studentID[i] << "\n";
            cout << "Name: " << studentName[i] << "\n";
            cout << "Scores: " << scores[i] << "\n";
            cout << "Attendance: " << attendance[i] << "%\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << searchID << " not found.\n";
    }
} //end of find student
