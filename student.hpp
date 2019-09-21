//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class Student
{
    public:
    Student(string FirstName, string LastName, float Cgpa, int ResearchScore, int StudentId);
    Student();
    void set(float Cgpa);
    string getFirstName();
    string getLastName();
    float getCgpa();
    int getResearchScore();
    int getStudentId();
    private:
    string firstName;
    string lastName;
    float cgpa;
    int researchScore;
    int studentId;
};

class DomesticStudent : public Student
{
    public:
    DomesticStudent(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId);
    DomesticStudent();
    void set(string FirstName, string LastName, string Province, float Cgpa, int ResearchScore, int StudentId);
    private:
    string province;
};


class ToeflScore
{
    public:
    ToeflScore(int reading, int listening, int speaking, int writing);
    ToeflScore();
    void set(int reading, int listening, int speaking, int writing);
    int getReading();
    int getListening();
    int getSpeaking();
    int getWriting();
    private:
    void addScores();
    int reading;
    int listening;
    int speaking;
    int writing;
};

class InternationalStudent : public DomesticStudent
{
    public:
    InternationalStudent(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, ToeflScore TOEFLScore, int StudentId);
    InternationalStudent();
    void set(string FirstName, string LastName, string Country, float Cgpa, int ResearchScore, int StudentId, ToeflScore TOEFLScore);
    private:
    string country;
    ToeflScore toeflScore;
};
