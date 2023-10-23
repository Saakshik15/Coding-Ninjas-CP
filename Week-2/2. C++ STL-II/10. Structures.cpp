#include <bits/stdc++.h>
using namespace std;

//Structures in C++ are used to store different data types in a single entity set.

struct Student{

  string name;
  int rollNo;
  int classNum;
  char section;
}; 

//all the entities name, rollNo, section are stored under a single structure which is s1
//so, structures help to capture various data types under a sigle variable name

void printStudentDetails(Student s){
  cout << s.name << " is a student of class " << s.classNum << " in section " << s.section << " and has roll number " << s.rollNo << ".\n";
}

int main() {

  Student s1;
  s1.name = "Saakshi";
  s1.rollNo = 58;
  s1.classNum = 12;
  s1.section = 'A'; 

  printStudentDetails(s1);

  return 0;
}
