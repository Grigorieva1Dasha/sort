#include <iostream>
#include "human.h"
#include "sort.h"

using namespace std;

int main(void) {
	SortableVector<Human> humans;
	if (!readHumans("in.txt", humans)) {
		cout << "Can't open input file: in.txt" << endl;
		return -1;
	}
	humans.sort();
	if (!writeHumans("out.txt", humans)) {
		cout << "Can't open output file: out.txt" << endl;
		return -2;
	}
	system("pause");
	return 0;
}

