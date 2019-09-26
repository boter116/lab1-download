//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>
#include <cstdlib>

/* 
 * Student Class Implementations 
 *
 */
Student::Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId)
{
  if(Cgpa < 0 || Cgpa > 4.33)//CGPA error checking if not valid, exit program 
    {
        cout << "Illegal values for CGPA inputted. Exiting program\n";
        exit(1);
    }
  if(ResearchScore < 0 || ResearchScore > 100)// Research score error checking if not valid, exit program
    {
        cout << "Illegal values for research score inputted. Exiting program\n";
        exit(1);
    }
  firstName = FirstName;
  lastName = LastName;
  cgpa = Cgpa; 
  researchScore = ResearchScore;
  studentId = StudentId;
}

Student::Student() : firstName("NULL"), lastName("NULL"), cgpa(0), researchScore(0), studentId(0) {/*intentionally empty*/}; //Intialize *empty* student class

void Student::set(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId)
{
  if(Cgpa < 0 || Cgpa > 4.33)//CGPA error checking if not valid, exit program 
    {
        cout << "Illegal values for CGPA inputted. Exiting program\n";
        exit(1);
    }
    if(ResearchScore < 0 || ResearchScore > 100)// Research score error checking if not valid, exit program
    {
        cout << "Illegal values for research score inputted. Exiting program\n";
        exit(1);
    }
    firstName = FirstName; //set first name
    lastName = LastName; //set last name
    cgpa = Cgpa; //set cgpa
    researchScore = ResearchScore; //set researchScore
    studentId = StudentId; //set studentID
}

void Student::set(float Cgpa) { cgpa = Cgpa; };

string Student::getFirstName()
{
  return firstName; //access and return firstname
}

string Student::getLastName()
{
  return lastName; //access and return lastname
}

float Student::getCgpa() 
{
  return cgpa; //access and return cgpa
}

int Student::getResearchScore()
{
  return researchScore; //access and return ResearchScore
}

int Student::getStudentId()
{
  return studentId; //access and return student ID
}
/*
 * Domestic Student Class Implenetations
 *
 */

DomesticStudent::DomesticStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId)
: Student(FirstName, LastName, Cgpa, ResearchScore, StudentId)
{
    province = Province;
};

DomesticStudent::DomesticStudent() : Student(), province("NULL") { /*intentionally empty*/ };

void DomesticStudent::set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId)
{
  Student::set(FirstName, LastName, Cgpa, ResearchScore, StudentId); //uses student set function to set student class memebers
  province = Province; //set province
}

string DomesticStudent::getProvince()
{
  return province; //access and return province
}

/*
 * ToeflScore Class Implementations
 *
 */


ToeflScore::ToeflScore() : reading(0), listening(0), speaking(0), writing(0) {/*intentionally empty*/};

ToeflScore::ToeflScore(int Reading, int Listening, int Speaking, int Writing)
{
    reading = Reading;
    listening = Listening;
    speaking = Speaking;
    writing = Writing;
    if (Reading < 0 || Reading > 30)
    {
        cout << "Illegal values for TOEFL Reading score inputted. Exiting program\n";
        exit(1);
    }
    if (Listening < 0 || Listening > 30)
    {
        cout << "Illegal values for TOEFL Listening score inputted. Exiting program\n";
        exit(1);
    }
    if (Speaking < 0 || Speaking > 30)
    {
        cout << "Illegal values for TOEFL Speaking score inputted. Exiting program\n";
        exit(1);
    }
    if (Writing < 0 || Writing > 30)
    {
        cout << "Illegal values for TOEFL Writing score inputted. Exiting program\n";
        exit(1);
    }
}

void ToeflScore::set(int Reading, int Listening, int Speaking, int Writing)
{
    reading = Reading;
    listening = Listening;
    speaking = Speaking;
    writing = Writing;
    if (reading < 0 || reading > 30)
    {
        cout << "Illegal values for TOEFL Reading score inputted. Exiting program\n";
        exit(1);
    }
    if (listening < 0 || listening > 30)
    {
        cout << "Illegal values for TOEFL Listening score inputted. Exiting program\n";
        exit(1);
    }
    if (speaking < 0 || speaking > 30)
    {
        cout << "Illegal values for TOEFL Speaking score inputted. Exiting program\n";
        exit(1);
    }
    if (writing < 0 || writing > 30)
    {
        cout << "Illegal values for TOEFL Writing score inputted. Exiting program\n";
        exit(1);
    }
}

int ToeflScore::getReading()
{
  return reading; //access and returns reading score
}

int ToeflScore::getListening()
{
  return listening; //access and returns listening score
}

int ToeflScore::getSpeaking()
{
  return speaking; //access and returns speaking score
}

int ToeflScore::getWriting()
{
  return writing; //access and returns writing scores
}

int ToeflScore::addScores()
{
  return reading + listening + speaking + writing; //accessand and returns the calculated sum of all s scor
}

InternationalStudent::InternationalStudent(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId)
: Student(FirstName, LastName, Cgpa, ResearchScore, StudentId)
{
    country = Country;
}

InternationalStudent::InternationalStudent() : Student(), country("NULL")
{
    toeflScore.set(0, 0, 0, 0);
}

void InternationalStudent::set(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId)
{
    Student::set(FirstName, LastName, Cgpa, ResearchScore, StudentId);
    toeflScore.set(TOEFLScore.getReading(), TOEFLScore.getListening(), TOEFLScore.getSpeaking(), TOEFLScore.getWriting());
    country = Country;
}
string InternationalStudent::getCountry()
{
  return country; //access and reutrns country
}

ToeflScore InternationalStudent::getToeflScore()
{
  return toeflScore; //access and returns toeflscore class
}







