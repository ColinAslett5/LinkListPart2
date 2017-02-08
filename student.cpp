//Colin Aslett, Student CPP FILE, C++ period 07
#include <iostream>
#include "student.h"
using namespace std;
Student::Student(int newid,float newgpa){
  id = newid;
  gpa = newgpa;
}
Student::~Student(){
}
char* Student::getFname(){
  return fname;
}
char* Student::getLname(){
  return lname;
}
int Student::getId(){
  return id;
}
float Student::getGpa(){
  return gpa;
}
