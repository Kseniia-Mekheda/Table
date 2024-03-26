#include <iostream>
#include "table.h"
using namespace std;

int main() {
	Table T; 
	T.addToTable("Element 1", "05664a");
	T.addToTable("Element 2", "67809c");
	T.addToTable("Element 3", "45624g");

	T.printTable(); 

	cout<<T.findInTable("67809c") << endl;
	cout << endl;


	cout<<T.remove("67809c") << endl;
	cout << endl;

	T.printTable();


	return 0;
}