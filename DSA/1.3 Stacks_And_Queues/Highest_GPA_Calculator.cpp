#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For GPA formatting

using namespace std;

// Define the student_type class
class student_type
{
private:
    double gpa;
    string name;

public:
    // Constructor to initialize a student's GPA and name
    student_type(double gpa_value, string student_name)
    {
        gpa = gpa_value;
        name = student_name;
    }

    // Getter function to retrieve the student's GPA
    double get_gpa() const
    {
        return gpa;
    }

    // Getter function to retrieve the student's name
    string get_name() const
    {
        return name;
    }

    // Function to display the student's data
    void display() const
    {
        cout << "Name: " << name << ", GPA: " << fixed << setprecision(2) << gpa << endl;
    }
};

// Function to find and display students with the highest GPA
void find_highest_gpa(vector<student_type> &students)
{
    double highest_gpa = 0.0;
    vector<student_type> highest_gpa_students;

    for (const auto &student : students)
    {
        double current_gpa = student.get_gpa();

        // Case 1: New highest GPA found
        if (current_gpa > highest_gpa)
        {
            highest_gpa = current_gpa;
            highest_gpa_students.clear();            // Reset the vector
            highest_gpa_students.push_back(student); // Add current student
        }
        // Case 2: Same GPA as the highest GPA so far
        else if (current_gpa == highest_gpa)
        {
            highest_gpa_students.push_back(student); // Add current student
        }
    }

    // Output the highest GPA and associated students
    cout << "\nThe highest GPA is: " << fixed << setprecision(2) << highest_gpa << endl;
    cout << "Students with the highest GPA:\n";
    for (const auto &student : highest_gpa_students)
    {
        cout << student.get_name() << endl;
    }
}

int main()
{
    int num_students = 7;          // Number of students (can be modified)
    vector<student_type> students; // Vector to store all students

    // Input the GPA and name of students
    cout << "Enter GPA and student name:\n";
    for (int i = 0; i < num_students; i++)
    {
        double gpa;
        string name;

        cin >> gpa;         // Input GPA
        cin.ignore();       // To ignore any newline after GPA input
        getline(cin, name); // Input student name

        // Create a new student and add to the vector
        student_type student(gpa, name);
        students.push_back(student);
    }

    // Find and display the students with the highest GPA
    find_highest_gpa(students);

    return 0;
}
