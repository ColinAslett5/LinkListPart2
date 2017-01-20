//Colin Aslett, node header file 
#include <iostream>
#include <string.h>
#include "student.h"
//Node.h

class Node {
 public:
  Node(); // creates a Node with null student and null next pointer
  Node(Student*); //creates a Node with Student pointer
  ~Node(); //destructor for Node (gets called in deleteNode)(
  Node* getNext(); //gets the next Node pointer
  Student* getStudent(); //gets the Student pointer the Node has
  void setNext(Node*); //sets the next Node pointer
  void setStudent(Student*); //sets the Student* in the node
 private:
  Node* next;
  Student* student;
};
