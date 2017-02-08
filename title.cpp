//Colin Aslett, title file for Linked List
#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "student.h"
#include "node.h"
using namespace std;
//function parameters
void add(Student* student,Node* &head);
void print(Node* head);
void avg(Node* head);
void delt(Student* student, Node* &head);
void addd(Node* &head, Node* next, Student* student);
void deltt(Student* student, Node* next,int id, Node* &head);
Node* head = NULL;
int main(){
  //Node* head = NULL;
  //head = new Node(); stuff needs to be added here
  cout.setf(ios::fixed,ios::floatfield);
  cout.setf(ios::showpoint);
  cout.precision(2);
  bool kg = true;
  char input[10];
  int id;
  float gpa;
  while(kg == true){
    cout << "Input a command(add,print,delete,quit,average)" << endl;
    cin >> input;
    Student* newstudent = new Student(id,gpa);
    if(strcmp(input,"add") == 0){
      //new student
      add(newstudent,head);
    }
    if(strcmp(input,"print") == 0){
      print(head);
    }
    if(strcmp(input,"delete") == 0){
      delt(newstudent,head);
    }
    if(strcmp(input,"quit") == 0){
      //have to delete all the new stuff here
      kg = false;
      newstudent = NULL;
      delete newstudent;
    }
    if(strcmp(input,"average") == 0){
      avg(head);
    }
  }
  return 0;
}
//add function
void add(Student* student,Node* &head){
  cout << "Input Information: first name, last name, id , gpa" << endl;
  cin >> student->fname;
  cin >> student->lname;
  cin >> student->id;
  cin >> student->gpa;
  //head->setStudent(student);
  Node* current = head;
  if(current == NULL){
    head = new Node();
    head->setStudent(student);
  }
  else{
    /*
    while(current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext(new Node());
    current->getNext()->setStudent(student);
    */
    addd(head,head,student);
  }
}
//sorts the linked list by ID from smallest to largest
void addd(Node* &head,Node* next,Student* student){
  if(next == head){
    if(next->getNext() == NULL){
      if(student->getId() < next->getStudent()->getId()){
	Node* current = new Node();
	head = current;
	current->setNext(next);
	current->setStudent(student);
      }
      else{
	Node* current = new Node();
	next->setNext(current);
	next->getNext()->setStudent(student);
      }
    }
    else{
      if(student->getId() < next->getStudent()->getId()){
	Node* current = new Node();
	head = current;
	current->setNext(next);
	current->setStudent(student);
      }
      else{
	addd(head,next->getNext(),student);
      }
    }
  }
  else{
    if(next->getNext() == NULL){
      next->setNext(new Node());
      next->getNext()->setStudent(student);
      next->getNext()->setNext(NULL);
    }
    else{
      if(next->getNext() != NULL){
	if(student->getId() < next->getNext()->getStudent()->getId()){
	  Node* current = next->getNext();
	  next->setNext(new Node(student));
	  next->getNext()->setNext(current);
	  //next->setNext(current);
	}
	else{
	  addd(head,next->getNext(),student);
	}
      }
    }
  }
}
//print function
void print(Node* next){
  if(next == NULL){
    //cout << "list:";
  }
  if(next != NULL){
    cout << next->getStudent()->getFname() << " " << next->getStudent()->getLname() << " , " << next->getStudent()->getId() << " , " << next->getStudent()->getGpa() << endl;
    //using RECURSION!
    print(next->getNext());
  }
}
//delete function
void delt(Student* student,Node* &next){
  cout << "Enter a ID Number to delete" << endl;
  int id;
  cin >> id;
  deltt(student,next,id,head);
  /*
  Node* current = head;
  Node* prev = head;
  while(prev->getNext()->getStudent()->getId() != id){
    if(next == NULL){
      break;
    }
    else{
      prev = prev->getNext();
    }
  }
  while(current->getStudent()->getId() != id){
    if(next == NULL){
      break;
    }
    else{
      current = current->getNext();
    }
  }
  prev->setNext(current->getNext());
  //current->setNext(NULL);
  student = NULL;
  current = NULL;
  delete student;
  delete current;
  */
}
//recursion for delete
void deltt(Student* student, Node* next,int id,Node* &head){
  if(next == head){
    if(next->getNext() == NULL){
      if(next->getStudent()->getId() == id){
        student = NULL;
	next = NULL;
	delete next;
	delete student;
      }
      else{
	cout << "NO ID EXISTS TO DELETE!" << endl;
      }
    }
    else{
      if(next->getStudent()->getId() == id){
        Node* current = head->getNext();
	student = NULL;
	next = NULL;
	delete next;
	delete student;
	head = current;
      }
      else{
	deltt(student,next->getNext(),id,head);
      }
    }
  }
  else{
    if(next->getNext() == NULL){
      if(next->getStudent()->getId() == id){
	Node* prev = head;
	while(prev->getNext()->getStudent()->getId() != id){
	  prev = prev->getNext();
	}
	prev->setNext(NULL);
	student = NULL;
	next = NULL;
	delete next;
	delete student;
      }
      else{
	cout << "NO ID EXISTS TO DELETE!" << endl;
      }
    }
    else{
      if(next->getStudent()->getId() == id){
	Node* prev = head;
	//Node* current = head;
	while(prev->getNext()->getStudent()->getId() != id){
	  prev = prev->getNext();
	}
	prev->setNext(next->getNext());
	student = NULL;
	next = NULL;
	delete next;
	delete student;
      }
      else{
	deltt(student,next->getNext(),id,head);
      }
    }
  }
}
//average function
void avg(Node* next){
  float sum = 0;
  int count = 0;
  Node* current = head;
  while(current != NULL){
    count++;
    sum += current->getStudent()->getGpa();
    current = current->getNext();
  }
  sum = sum/count;
  //cout << count << endl;
  cout << sum << endl;
}
