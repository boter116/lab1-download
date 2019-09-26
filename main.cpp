//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <ctime> //time
#include "student.hpp" //include student header file

/* 
 *  Helper Functions (Mainly used for random number generator and checker)
 *
 */
int getRandStudentNumber(int ary[]); 
bool checkValidNumber(int num, int ary[]);

/* (Bonus) Assigns a random generated student number rather than a linear count
 * Assume the range is from 20200000 to 20210000 
 * 
 */
int getRandStudentNumber(int ary[]){
  
  int temp = rand()%10000 + 20200000; //randomize number from 0 to 10000 and added to 20200000 ie. range from 20200000 to 20210000
  if (checkValidNumber(temp,ary)==true){ //if valid returns value
     return temp;
  }
  else{
    return getRandStudentNumber(ary); //if number was not valid goes through the same function (recursive)
   }
}
/* Receives given number and array to find and check if the number given does not exist
 * in the given array. Onces it reaches the end, meaning that the number has not been   
 * found, it intialize that spot to the according number given.
 */
bool checkValidNumber(int num, int ary[]){
for(int i=0;i<10000;i++){
   if (ary[i]==num){  //if number already exist in library return false (not valid number)
      return false;
   }
   if (ary[i]==-1){ //if number has not been found set the number to list and return true (valid number)
      ary[i]=num;
      return true;
   }
}   
} 

/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */
int main(){
  //Read the domestic-stu.txt file and exit if failed
  srand(time(NULL));// random seed generator
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
  int StudentNumLibrary[10000]; //create empty array of all zeros. Size 10000, assuming less than 100000 students
  fill_n(StudentNumLibrary,10000,-1); //Initalize and fill the array with a constant number (-1) besides 0 because its in the range of the random num. generator
  int stu_count = 1; //student count; 
  int studentNumber = getRandStudentNumber(StudentNumLibrary); //generates a random student number in the appropriate range
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
  
    stu_count++; //increment student count
  studentNumber=getRandStudentNumber(StudentNumLibrary); //generate randome student number
  
  }
  //close your file
  domesticFile.close();
  //read internation file and exit if failed
  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open())
  {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  
  getline(internationalFile, line);
  cout << "File format: " << line << endl;
  
  stu_count = 1; //intialize student count back to 1 for international student 
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
    
    //get reading score seperated by comma, and convert to int 
    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());
    
    //get listening score seperated by comma, and convert to int
    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());

    //get speaking score seperated by comma, and convert to int
    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());

    //get writing score seperated by comma, and convert to int
    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());

    //set 
    TOEFLScore.set(reading, listening, speaking, writing);
    I_Student.set(firstName, lastName, country, cgpa, researchScore, TOEFLScore, studentNumber);

    //print the student info to the screen
    cout << "International student " << stu_count << " " << I_Student.getFirstName() << " " 
	 << I_Student.getLastName() << " from " << I_Student.getCountry() << " has cgpa of "
	 << I_Student.getCgpa() << ", and research score of " << I_Student.getResearchScore() 
	 << ". Assigned Student ID: " << I_Student.getStudentId() << endl
	 << "Their TOEFL Scores are: reading = " << I_Student.getToeflScore().getReading()
	 << ", listening = " << I_Student.getToeflScore().getListening() << ", speaking = "
	 << I_Student.getToeflScore().getSpeaking() << ", writing = " << I_Student.getToeflScore().getWriting()
         << "\n" << "Total TOEFL Score = " << I_Student.getToeflScore().addScores() << endl;

    stu_count++;//Increment student count
    studentNumber=getRandStudentNumber(StudentNumLibrary); //generator random student number
  }
  internationalFile.close(); // close file
  return 0;
}



