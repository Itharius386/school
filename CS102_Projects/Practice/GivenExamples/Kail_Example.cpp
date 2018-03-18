// This program demonstrates the overloaded = operator
#include <iostream>
#include "StudentTestScores.h"
#include "StudentTestScores.cpp"
using namespace std;

void displayStudent(StudentTestScores);    // Function prototype

int main()
{
    // Create a StudentTestScores object and assign test scores.
    StudentTestScores student1("Kelly Thorton", 3);
    student1.setTestScore(100.0, 0);
    student1.setTestScore(95.0, 1);
    student1.setTestScore(80, 2);

    cout << "\n\tStudent1:";
    displayStudent(student1);
	    
    StudentTestScores student2("Jimmy Griffin", 5);
    student2.setTestScore(55.8, 0);
    student2.setTestScore(57.0, 1);
    student2.setTestScore(65, 2); 
    student2.setTestScore(78.0, 3);
    student2.setTestScore(102, 4);  

    cout << "\n\tStudent2:";
    displayStudent(student2);
		
    student2 = student1;

    cout << "\n\tStudent2:";
    displayStudent(student2);	


    student1.setTestScore(111.1, 0);  

	StudentTestScores student3 = student2;
    
    cout << "\n\tStudent1:";
    displayStudent(student1);
    cout << "\n\tStudent2:";
    displayStudent(student2);
    cout << "\n\tStudent3:";
	displayStudent(student3);
    return 0;
}
// The displayStudent function accepts a StudentTestScores object's data.
void displayStudent(StudentTestScores s)
{
     cout << "\nName: " << s.getStudentName() << endl;
     cout << "Test Scores: ";
     for (int i = 0; i < s.getNumTestScores(); i++)
        cout << s.getTestScore(i) << " ";
     cout << endl;
}

