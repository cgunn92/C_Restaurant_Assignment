#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "restaurant.h"
using namespace std;

const int CAPACITY = 20;
const int MAXCHAR = 101;

void openFile(ifstream& inFile);
int readData(ifstream& inFile, Restaurant aRest[], int size);
void dispRestaurants(Restaurant aRest[], int size);
void exeCommand(char option, Restaurant aRest[], int size);
char menuChoice();
void searchRestaurants(Restaurant aRest[], int size);
void dispMenu();

int main() {
  Restaurant aRest[CAPACITY];
  ifstream inFile;
  int size;
  int i;
  char option;

  cout << "Welcome to my restaurant database:" << endl;
	cout << "Pick from one of the following options:" << endl;
  inFile.open("restaurant.txt");
	if (!inFile) {
		cout << "File did not open! Program terminating!!" << endl;
		exit(0);
	}

  readData(inFile, aRest, size);
  cout << size;
  for (i = 0; i < size; i++) {
  	cout << aRest[i].restaurantName << endl;
  }

  do {
    dispMenu();
    option = menuChoice();
    cout << endl; //newline for user experience
    exeCommand(option, aRest, size);
  } while(option != 'q');
  
}

void openFile(ifstream& inFile) {
	char filename[MAXCHAR];
	cout << "Enter filename:";
	cin.get(filename, MAXCHAR);
	cin.ignore(100, '\n');
	inFile.open(filename);
	if (!inFile)
	{
		cout << "File did not open! Program terminating!!";
		exit(0);
	}
}

int readData(ifstream& inFile, Restaurant aRest[], int size) {
	while (!inFile.eof()) {
		inFile >> aRest[size].restaurantName >> aRest[size].foodType >> aRest[size].rating;
		size++;
	}
  return size; //returns the number of lines read from the txt file
}

void exeCommand(char option, Restaurant aRest[], int size) {
	switch (tolower(option)) {
	case 'p':
		dispRestaurants(aRest, size);
		break;
	case 's':
		searchRestaurants(aRest, size);
		break;
	case 'q':
		break;
	default:
		cout << "Illegal input!";
	}
}

char menuChoice() {
  char choice;
  cin.get(choice);
  cin.ignore(100, '\n');
  return choice;
}

void dispRestaurants(Restaurant aRest[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    cout << aRest[i].restaurantName << " " << aRest[i].foodType << " ";
    cout << aRest[i].rating << endl;
  }
}

void searchRestaurants(Restaurant aRest[], int size) {
	char srchStr[MAXCHAR];
	bool found = false;
	cout << "Enter restaurant name to search for:";
	cin.getline(srchStr, MAXCHAR);
	for (int i = 0; i < size; i++) {
		if (strstr(aRest[i].restaurantName, srchStr) != NULL) {
			cout << setw(10) << left << aRest[i].restaurantName
				<< setw(10) << aRest[i].foodType << setw(10) << aRest[i].rating << endl;
			found = true;
			//break;
		}
	}
	if (!found)
		cout << "Restaurant not found!!" << endl;
}

void dispMenu(){
	cout << endl;
	cout << "(p) Print the restaurant list" << endl;
	cout << "(s) Search the restaurant list by name" << endl;
	cout << "(q) Quit" << endl;
	cout << endl;
	cout << "Please enter an option: ";
}