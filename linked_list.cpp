#include "linked_list.h"
#include <iostream>

using namespace std;

void linkedList::addToListEnd(const int idEntered, const string infoEntered) {
  Node *newNode;
  newNode = new Node;
  newNode->id = idEntered;
  newNode->string = infoEntered;
  newNode->next = NULL;
  last->next = newNode;
  last = newNode;
}

void linkedList::removeFromList(const int idEntered) {
  Node *current;
  Node *trailCurrent;
  current = first;
  while ((current->id != idEntered) && (current != NULL)) {
    trailCurrent = current;
    current = current->next;
  }

  if (current->id != idEntered) {
    cout << "Item is not in list" << endl;
  }
  else if (current == first) {
    trailCurrent = current;
    current = current->next;
    first = current;
    delete trailCurrent;
  }
  else if (current == last) {
    last = trailCurrent;
    trailCurrent->next = NULL;
    delete trailCurrent;
  }
  else {
    trailCurrent->next = current->next;
    delete current;
  }
}

void linkedList::printList() {
  Node *current;
  current = first;

  cout << setw(5) << "ID" << "Info" << endl;

  while (current != NULL) {
    cout << setw(5) << current->id << current->info << endl;
  }
}

linkedList::linkedList() {
  first = NULL;
  last = NULL;
  count = 0;
}

linkedList::~linkedList() {
  Node *current;
  current = first;
  trailCurrent = first;

  while (current != NULL) {
    current = current->next;
    delete trailCurrent;
    trailCurrent = current;
  }
  delete trailCUrrent;
}
