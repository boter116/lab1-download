//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class Student
{
    public:
    Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId);
    Student();
    void set(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId);
    void set(float Cgpa);
    string getFirstName();
    string getLastName();
    float getCgpa();
    int getResearchScore();
    int getStudentId();
    private:
    string firstName;  //first name string variable 
    string lastName;   //last name string variable
    float cgpa;        //cgpa float variable
    int researchScore; //researchscore int variable
    int studentId;     //studentId int variable
};

class DomesticStudent : public Student
{
    public:
    DomesticStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId);
    DomesticStudent();
    void set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId);
    string getProvince();
    private:
    string province; //province string variable
};

class ToeflScore
{
    public:
    ToeflScore(int Reading, int Listening, int Speaking, int Writing);
    ToeflScore();
    void set(int Reading, int Listening, int Speaking, int Writing);
    int getReading();        
    int getListening();
    int getSpeaking();
    int getWriting();
    int addScores();
    private: 
    int reading;    //reading score int variable
    int listening;  //listening score int variable
    int speaking;   //speaking score int variable
    int writing;    //writing score int variable
};

class InternationalStudent : public Student
{
    public:
    InternationalStudent(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId); //Intialize international student class
    InternationalStudent(); //Initalize empty international student class
    void set(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId); //intialize set internation student function
    string getCountry(); //intialize get country function
    ToeflScore getToeflScore(); //intialize get toefl score function
    private:
    string country;          //country string variable
    ToeflScore toeflScore;   //toefl score of a toeflscore class variable
};
