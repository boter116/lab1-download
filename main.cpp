//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"

/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */
int main(){
  //Read the domestic-stu.txt file and exit if failed
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  cout << "File format: " << line << endl;

  /*Keep reading the rest of the lines in domestic-stu.txt.
   *In the example code here, I will read each data separated
   *by a comma, and then print it out to the screen.
   *In your lab assignment 1, you should use these read data
   *to initialize your DomesticStudent object. Then you can
   *use get and set functions to manipulate your object, and
   *print the object content to the screen
   */
  int stu_count = 1;
  int studentNumber = 20200000;
  DomesticStudent D_Student;
  while( getline(domesticFile, line) ) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     *Note in this example code here, we assume the file format
     *is perfect and do NOT handle error cases. We will leave the
     *error and exception handling of file format to Lab Assignment 4
     */
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    D_Student.set(firstName, lastName, province, cgpa, researchScore, studentNumber);

    //print the student info to the screen
    cout << "Domestic student " << stu_count << " " << D_Student.getFirstName() << " " 
	 << D_Student.getLastName() << " from " << D_Student.getProvince() << " province has cgpa of "
	 << D_Student.getCgpa() << ", and research score of " << D_Student.getResearchScore() 
   << ". Assigned Student ID: " << D_Student.getStudentId() << endl;
  
  stu_count++;
  studentNumber++;
  
  }
  //close your file
  domesticFile.close();

  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open())
  {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  
  getline(internationalFile, line);
  cout << "File format: " << line << endl;

  stu_count = 1;
  InternationalStudent I_Student;
  ToeflScore TOEFLScore;

  while(getline(internationalFile, line))
  {
    istringstream ss(line);

    string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore, reading, listening, speaking, writing;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, country, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());

    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());

    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());

    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());

    TOEFLScore.set(reading, listening, speaking, writing);
    I_Student.set(firstName, lastName, country, cgpa, researchScore, TOEFLScore, studentNumber);

    //print the student info to the screen
    cout << "International student " << stu_count << " " << I_Student.getFirstName() << " " 
	 << I_Student.getLastName() << " from " << I_Student.getCountry() << " has cgpa of "
	 << I_Student.getCgpa() << ", and research score of " << I_Student.getResearchScore() 
   << ". Assigned Student ID: " << I_Student.getStudentId() << endl
   << "Their TOEFL Scores are: reading = " << I_Student.getToeflScore().getReading()
   << ", listening = " << I_Student.getToeflScore().getListening() << ", speaking = "
   << I_Student.getToeflScore().getSpeaking() << ", writing = " << I_Student.getToeflScore().getWriting() << endl;

    stu_count++;
    studentNumber++;
  }
  internationalFile.close();

  return 0;
}