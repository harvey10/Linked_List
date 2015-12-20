#ifndef "linked_list_h"
#define "linked_list_h"

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
  int id;
  string info;
  Node *next;
};

class linkedList {
public:
  void addToListEnd(const int, const string);
  void removeFromList(const int);
  void printList();
  linkedList();
  ~linkedList();
private:
  Node *first;
  Node *last;
  int count;
};
