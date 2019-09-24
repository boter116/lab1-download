//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>

Student::Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId)
{
    if(Cgpa < 0 || Cgpa > 4.33)
    {
        cout << "Illegal values for CGPA inputted. Exiting program\n";
        exit(1);
    }
    if(ResearchScore < 0 || ResearchScore > 100)
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

Student::Student() : firstName("NULL"), lastName("NULL"), cgpa(-1), researchScore(-1), studentId(-1) {/*intentionally empty*/};

void Student::set(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId)
{
    if(Cgpa < 0 || Cgpa > 4.33)
    {
        cout << "Illegal values for CGPA inputted. Exiting program\n";
        exit(1);
    }
    if(ResearchScore < 0 || ResearchScore > 100)
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

void Student::set(float Cgpa) { cgpa = Cgpa; };

string Student::getFirstName()
{
    return firstName;
}

string Student::getLastName()
{
    return lastName;
}

float Student::getCgpa()
{
    return cgpa;
}

int Student::getResearchScore()
{
    return researchScore;
}

int Student::getStudentId()
{
    return studentId;
}

DomesticStudent::DomesticStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId)
: Student(FirstName, LastName, Cgpa, ResearchScore, StudentId)
{
    province = Province;
};

DomesticStudent::DomesticStudent() : Student(), province("NULL") { /*intentionally empty*/ };

void DomesticStudent::set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId)
{
    Student::set(FirstName, LastName, Cgpa, ResearchScore, StudentId);
    province = Province;
}

string DomesticStudent::getProvince()
{
    return province;
}

ToeflScore::ToeflScore(int Reading, int Listening, int Speaking, int Writing)
{
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
    reading = Reading;
    listening = Listening;
    speaking = Speaking;
    writing = Writing;
}

ToeflScore::ToeflScore() : reading(0), listening(0), speaking(0), writing(0) {/*intentionally empty*/};

void ToeflScore::set(int Reading, int Listening, int Speaking, int Writing)
{
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
    reading = Reading;
    listening = Listening;
    speaking = Speaking;
    writing = Writing;
}

int ToeflScore::getReading()
{
    return reading;
}

int ToeflScore::getListening()
{
    return listening;
}

int ToeflScore::getSpeaking()
{
    return speaking;
}

int ToeflScore::getWriting()
{
    return writing;
}

int ToeflScore::addScores()
{
    return reading + listening + speaking + writing;
}

InternationalStudent::InternationalStudent(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId)
: Student(FirstName, LastName, Cgpa, ResearchScore, StudentId)
{
    country = Country;
}

InternationalStudent::InternationalStudent() : Student(), country("NULL")
{
    toeflScore.set(-1, -1, -1, -1);
}

void InternationalStudent::set(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId)
{
    Student::set(FirstName, LastName, Cgpa, ResearchScore, StudentId);
    toeflScore.set(TOEFLScore.getReading(), TOEFLScore.getListening(), TOEFLScore.getSpeaking(), TOEFLScore.getWriting());
    country = Country;
}
string InternationalStudent::getCountry()
{
    return country;
}

ToeflScore InternationalStudent::getToeflScore()
{
    return toeflScore;
}




