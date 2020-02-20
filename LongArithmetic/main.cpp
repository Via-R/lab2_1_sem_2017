#include <iostream>
#include "XLong.h"
#include "PrimalTest.h"
#include <fstream>

using namespace std;
int main() {
	cout << "All systems are functional: " << isOk() <<"\n";
	string num1, num2, expected_answer;
	ifstream myfile("input.txt");
	if (myfile.is_open()){
		getline(myfile, num1);
		getline(myfile, num2);
		getline(myfile, expected_answer);
		cout << num1 << endl;
		cout << "Processing started\n";
		cout << "Number 1: " << num1 << "\nNumber 2: " << num2 << endl << endl;
	
		XLong a(num1);
		XLong b(num2);
		XLong mult = a * b;
		
		XLong::setType(new SimpleMult());
		
		XLong mult2 = a * b;
		cout << "Results: " << endl;
		cout << "Karatsuba said a * b = ";
		mult.print();
		cout << "Simple Multiplication said a * b = ";
		mult2.print();
		cout << "The desired result is: " << expected_answer << endl;
		cout << "So the difference between our results is: ";
		(mult - mult2).print();
		
		cout << "\nNow checking if the entered number is prime\n";
		string numToTest;
		getline(myfile, numToTest);
		cout << "We've got this number to check: " << numToTest << endl;
		cout << "Is it primal?" << endl << endl;
		
		cout << "Lehmann says: ";
		Lehmann n_l(numToTest);
		if (n_l.isValid()) {
			string answer = n_l.isPrimal() ? "Yes" : "No";
			cout << answer << endl;
		}
		else {
			cout << "sorry, the number couldn't be parsed\n";
		}
		cout << "Lucas and Lehmer say: ";
		LucasLehmer n_ll(numToTest);
		if (n_ll.isValid()) {
			string answer = n_ll.isPrimal() ? "Yes" : "No";
			cout << answer << endl;
		}
		else {
			cout << "sorry, the number couldn't be parsed\n";
		}
		cout << "Rabin and Miller say: ";
		RabinMiller n_r(numToTest);
		if (n_r.isValid()) {
			string answer = n_r.isPrimal() ? "Yes" : "No";
			cout << answer << endl;
		}
		else {
			cout << "sorry, the number couldn't be parsed\n";
		}
		cout << "Solovay and Strassen say: ";
		SolovayStrassen n_s(numToTest);
		if (n_s.isValid()) {
			string answer = n_s.isPrimal() ? "Yes" : "No";
			cout << answer << endl;
		}
		else {
			cout << "sorry, the number couldn't be parsed\n";
		}
		
		cout << endl;
		myfile.close();
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;
}