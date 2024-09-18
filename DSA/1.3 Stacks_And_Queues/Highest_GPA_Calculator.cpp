#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For GPA formatting

using namespace std;

// Define the StudentType class
class StudentType
{
private:
    double GPA;
    string name;

public:
    // Constructor to initialize a student's GPA and name
    StudentType(double gpa, string studentName)
    {
        GPA = gpa;
        name = studentName;
    }

    // Getter function to retrieve the student's GPA
    double getGPA() const
    {
        return GPA;
    }

    // Getter function to retrieve the student's name
    string getName() const
    {
        return name;
    }

    // Function to display the student's data
    void display() const
    {
        cout << "Name: " << name << ", GPA: " << fixed << setprecision(2) << GPA << endl;
    }
};

// Function to find and display students with the highest GPA
void findHighestGPA(vector<StudentType> &students)
{
    double highestGPA = 0.0;
    vector<StudentType> highestGPAStudents;

    for (const auto &student : students)
    {
        double currentGPA = student.getGPA();

        // Case 1: New highest GPA found
        if (currentGPA > highestGPA)
        {
            highestGPA = currentGPA;
            highestGPAStudents.clear();            // Reset the vector
            highestGPAStudents.push_back(student); // Add current student
        }
        // Case 2: Same GPA as the highest GPA so far
        else if (currentGPA == highestGPA)
        {
            highestGPAStudents.push_back(student); // Add current student
        }
    }

    // Output the highest GPA and associated students
    cout << "\nThe highest GPA is: " << fixed << setprecision(2) << highestGPA << endl;
    cout << "Students with the highest GPA:\n";
    for (const auto &student : highestGPAStudents)
    {
        cout << student.getName() << endl;
    }
}
