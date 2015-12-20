#include "linked_list.h"
#include <iostream>

using namespace std;

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
