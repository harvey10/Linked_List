#include <iostream>
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

int main() {
  linkedList c;
  int menuChoice = 0;
  string addInfo;
  int addID = 1;
  int removeID;

  while (menuChoice != 3) {
    c.printList();
    cout << endl << "Menu Options" << endl << "1.Add node" << endl
	 << "2.Remove node" << endl << "3.Exit" << endl << "Please enter choice:";
    try {
      cin >> menuChoice;
      if (!cin || menuChoice > 3 || menuChoice < 1)
	throw menuChoice;
      else if (menuChoice == 1) {
	cout << "Please enter string info for node: ";
	cin >> addInfo;
	c.addToListEnd(addID, addInfo);
	addID++;
      }
      else if (menuChoice == 2) {
	cout << "Please enter ID for node to remove: ";
	cin >> removeID;
	c.removeFromList(removeID);
      }
    }
    catch(...) {
      cout << "Please enter a valid menu choice" << endl;
      cin.clear();
      cin.ignore(200, '\n');
      menuChoice = 0;
    }
  }
}
