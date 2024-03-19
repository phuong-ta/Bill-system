// Bill systems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Items/Item.h"
#include "ItemsController/ItemsController.h"
#include "Bill/Bill.h"

using namespace std;

void listChoice() {
	cout << endl;
	cout << "1: Item Controller" << endl;
	cout << "2: Bill Controller" << endl;
	cout << "3: New Bill" << endl;
	cout << "Else: Quit" << endl;
	cout << endl;
}
void itemChoice() {
	cout << endl;
	cout << "1: Show All Items" << endl;
	cout << "2: Add new item" << endl;
	cout << "3: Change Price" << endl;
	cout << "4: Remove item from list" << endl;
	cout << "Else: Quit" << endl;
	cout << endl;
}
void itemOptions() {
	int choice = 0;
	ItemController itemList;

	while (true) {
		itemChoice();
		cout << "Enter your choice:";
		cin >> choice;
		if (choice ==1) {
			itemList.showAllItems();
		}
		else if (choice == 2) {
			itemList.addNewItem();
		}
		else if (choice == 3) {
			itemList.updateItemPrice();
		}
		else if (choice == 4) {
			itemList.deleteItem();
		}
		else {
			itemList.emptyList();
			break;
		}
	}
}
void billChoice() {
	cout << endl;
	cout << "1: Show All Bills" << endl;
	cout << "2: Find bill from list" << endl;
	cout << "3: Show Report" << endl;
	cout << "Else: Quit" << endl;
	cout << endl;
}

void billOption() {
	int choice = 0;

	while (true) {
		cout << "Enter your choice:";
		cin >> choice;
		if (choice == 1) {
			cout << "1: Show All Bills......." << endl;
		}
		else if (choice == 2) {
			cout << "2: Find bill from list......." << endl;
		}
		else if (choice == 3) {
			cout << "3: Show Report......" << endl;
		}
		else {
			break;
		}
	}
}

int main() {

	int choice = 0;
	while (true) {
		listChoice();
		cout << "Enter your choice:";
		cin >> choice;
		if (choice==1) {
			//itemChoice();
			itemOptions();
		}
		else if (choice==2) {
			billChoice();
			billOption();
		}
		else if (choice == 3) {
			Bill newBill;
			cin >> newBill;
			cout << newBill;
		}
		else {
			break;
		}
	}
}
