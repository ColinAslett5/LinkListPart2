//Colin Aslett, Student Header file
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
class Student{
 public:
  char fname[100];
  char lname[100];
  int id;
  float gpa;
  Student(int id,float gpa);
  ~Student();
  char* getFname();
  char* getLname();
  int getId();
  float getGpa();
};
#endif
