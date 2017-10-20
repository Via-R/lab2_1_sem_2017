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
		
		
		XLong mult = a * b;
		
		XLong::setType(new SimpleMult());
		XLong mult2 = a * b;

		mult.print();
		mult2.print();
		(mult - mult2).print();
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;
}