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
		
		XLong q("93111331371001577132131009612389691112112131009960910112992113108120969688979564511139881059638415761577612013710489612111612192116091329111011211398491077712875361273111251110368912913600");
		XLong w("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

		cout << "This: " << endl;
		(q+w).print();

		XLong mult = a * b;
		mult.print();
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;
}