#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "sort.h"

using namespace std;

class Human {
private:
	char* information;
public:
	char* getInformation() {
		return information;
	}
	Human(char* intxt) {
		information = new char[strlen(intxt) + 1];
		for (int i = 0; i < strlen(intxt); i++)
			information[i] = intxt[i];
		information[strlen(intxt)] = 0;
	}
	void operator =(const Human& human);
	bool operator ==(const Human& human) const;
	bool operator >(const Human& human) const;
	bool operator <(const Human& human) const;
};
void Human::operator =(const Human& human) {
	information = new char[strlen(human.information) + 1];
	for (int i = 0; i < strlen(human.information); i++)
		information[i] = human.information[i];
	information[strlen(human.information)] = 0;
}
bool Human::operator ==(const Human& human) const {
	if (strcmp((*this).information, human.information) == 0)
		return true;
	return false;
}
bool Human::operator >(const Human& human) const {
	if (strcmp((*this).information, human.information) > 0)
		return true;
	return false;
}
bool Human::operator <(const Human& human) const {
	if (strcmp((*this).information, human.information) < 0)
		return true;
	return false;
}
bool readHumans(const char* filename, vector<Human>& humans) {
	ifstream in(filename);
	char information[200];
	while (!in.eof()){
		in.getline(information, 200, '\n');
		Human human = Human(information);
		humans.push_back(human);
	}
	return true;
}
ostream& operator << (ostream& out, Human& human) {
	out << human.getInformation();
	return out;
}
bool writeHumans(const char* filename, vector<Human>& humans) {
	ofstream out(filename);
	for (int i = 0; i < humans.size(); i++) {
		out << humans[i] << endl;
	}
	return true;
}