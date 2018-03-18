#ifndef STUDENTTESTSCORES_H
#define STUDENTTESTSCORES_H
#include <string>
using namespace std;

class StudentTestScores
{
private:
   string studentName; 	 // The student's name
   double *testScores;  	// Points to array of test scores
   int numTestScores;   	// Number of test scores
   void createTestScoresArray(int size);

public:
     StudentTestScores(string name, int numScores); 
     StudentTestScores(const StudentTestScores &obj);
     ~StudentTestScores();	                              
     void setTestScore(double score, int index);
     void setStudentName(string name);      
     string getStudentName() const;	   	  
     int getNumTestScores() const;         
     double getTestScore(int index) const;   

   // Overloaded = operator
    void operator=(const StudentTestScores &right);
};  
#endif

