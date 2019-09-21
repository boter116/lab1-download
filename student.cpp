//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>

Student::Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId)
{
    if(Cgpa < 0 || Cgpa > 4.33)
    {
        cout << "Illegal values for CGPA inputted. Exiting program";
        exit(1);
    }
    if(ResearchScore < 0 || ResearchScore > 100)
    {
        cout << "Illegal values for research score inputted. Exiting program";
        exit(1);
    }
    firstName = FirstName;
    lastName = LastName;
    cgpa = Cgpa;
    researchScore = ResearchScore;
    studentId = StudentId;
}

Student::Student() : firstName(NULL), lastName(NULL), cgpa(0), researchScore(0), studentId(0) {/*intentionally empty*/};

DomesticStudent::DomesticStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId)
: Student()
{

}