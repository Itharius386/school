#include "StudentTestScores.h"
#include <string>
using namespace std;

const double DEFAULT_SCORE = 0.0;


    // Private member function to create an array of test scores.
   void StudentTestScores::createTestScoresArray(int size)
       { numTestScores = size;
         testScores = new double[size]; 
         for (int i = 0; i < size; i++)
            testScores[i] = DEFAULT_SCORE; }
        
     StudentTestScores::StudentTestScores(string name, int numScores) // Constructor
       { studentName = name;
         createTestScoresArray(numScores); }
 
     StudentTestScores::StudentTestScores(const StudentTestScores &obj) // Copy constructor
   { studentName = obj.studentName;
     numTestScores = obj. numTestScores;
     testScores = new double[numTestScores];
     for (int i = 0; i < numTestScores; i++)
        testScores[i] = obj.testScores[i]; }

StudentTestScores::~StudentTestScores()	                            // Destructor
   { delete [] testScores; }

    // The setTestScore function sets a specific test score's value.
   void StudentTestScores::setTestScore(double score, int index)
      { testScores[index] = score; }

   void StudentTestScores::setStudentName(string name)        // Set the student's name.
      { studentName = name; }
 
   string StudentTestScores::getStudentName() const	  	   // Get the student's name.
      { return studentName; }
   
   int StudentTestScores::getNumTestScores() const        	 // Get the number of test scores.
      { return numTestScores; }

    double StudentTestScores::getTestScore(int index) const     // Get a specific test score.
      { return testScores[index]; }

   // Overloaded = operator
    void StudentTestScores::operator=(const StudentTestScores &right)
     { delete [] testScores;
        studentName = right.studentName;
        numTestScores = right.numTestScores;
        testScores = new double[numTestScores];
        for (int i = 0; i < numTestScores; i++)
           testScores[i] = right.testScores[i]; }


