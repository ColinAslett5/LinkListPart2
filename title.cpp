//Colin Aslett, title file for Linked List
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "student.h"
#include "node.h"

using namespace std;
//function parameters
void delt(Student* student, Node* &head);
void add(Student* student,Node* &head);
void print(Node* head);
int average();
int main(){
  Node* head = NULL;
  //head = new Node(); stuff needs to be added here
  cout.setf(ios::fixed,ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  bool kg = true;
  char input[10];
  while(kg == true){
    cout << "Input a command(add,print,delete,quit,average)" << endl;
    cin >> input;
    if(strcmp(input,"add") == 0){
      add();
    }
    if(strcmp(input,"input") == 0){
      print();
    }
    if(strcmp(input,"delete") == 0){
      delt();
    }
    if(strcmp(input,"quit") == 0){
      //have to delete all the new stuff here
      kg = false;
    }
    if(strcmp(input,"average") == 0){
      average();
    }
  }
  return 0;
}
void add(Student* student,Node* &head){
  
}
void delt(Student* student,Node* &head){
  
}
void print(Node* head){

}
int average(){
  int gpa = 0;
  //code goes in here
  return gpa;
}
