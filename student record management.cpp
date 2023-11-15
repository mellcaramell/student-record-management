#include <iostream>
#include <string>
using namespace std;

// Step 1: Declare the arrays
int studentID[50];
string studentName[50];
double scores[50];
int attendance[50];

// Step 2: Input Student Data Function
void inputStudentData(int i) {
    cout << "Enter student ID: ";
    cin >> studentID[i];
    cout << "Enter student name: ";
    cin >> studentName[i];
    cout << "Enter student scores: ";
    cin >> scores[i];
    cout << "Enter student attendance: ";
    cin >> attendance[i];
}

// Step 3: Calculate Average Scores Function
double calculateAverageScores() {
    double totalScores = 0;
    for (int i = 0; i < 50; i++) {
        totalScores += scores[i];
    }
    return totalScores / 50;
}

// Step 4: Display Student Records Function
void displayStudentRecords(int i) {
    cout << "Student ID: " << studentID[i] << endl;
    cout << "Student Name: " << studentName[i] << endl;
    cout << "Student Scores: " << scores[i] << endl;
    cout << "Student Attendance: " << attendance[i] << "%" << endl;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // Collecting and storing student data
    for (int i = 0; i < n; i++) {
        inputStudentData(i);
    }

    // Displaying student records
    for (int i = 0; i < n; i++) {
        displayStudentRecords(i);
        cout << "Average Scores: " << calculateAverageScores() << endl;
    }

    return 0;
}