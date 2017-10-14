#include <iostream>
#include "XLong.h"
#include <fstream>

using namespace std;
int main() {
	cout << (367>>1) << endl;
	cout << "All systems are functional: " << isOk() <<"\n";
	string num1, num2;
	ifstream myfile("input.txt");
	if (myfile.is_open()){
		getline(myfile, num1);
		getline(myfile, num2);
		cout << "Number 1: " << num1 << "\nNumber 2: " << num2 << endl;
		myfile.close();

		XLong a(num1);
		XLong b(num2);
		
		(a + b).print();

		XLong q("909");
		XLong w("999");

		cout << "This: " << endl;
		(q+w).print();

		XLong mult = a * b;
		mult.print();
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;
}