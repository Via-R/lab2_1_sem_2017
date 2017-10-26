#include <iostream>
#include "XLong.h"
#include "PrimalTest.h"
#include <fstream>

using namespace std;
int main() {
	cout << "All systems are functional: " << isOk() <<"\n";
	string num1, num2;
	ifstream myfile("input.txt");
	if (myfile.is_open()){
		/*getline(myfile, num1);
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
		*/

		string numToTest;
		getline(myfile, numToTest);

		//LucasLehmer n(numToTest);
		//Lehmann n(numToTest);
		//RabinMiller n(numToTest);
		SolovayStrassen n(numToTest);
		//jacobi(12, 3) = 0, jacobi(28, 21) = 0, jacobi(6, 11) = -1, jacobi(226, 135) = 1, 
		//jacobi(26, 35) = -1, jacobi(-286, 4272943) = 1, jacobi(888, 1999) = -1
	//	cout << "KEKUS: " << SolovayStrassen::jSymbol(1, 2197, 383) << endl
		
		cout << "We've got this mumber: " << n << endl;
		if (n.isValid()) {
			string answer = n.isPrimal() ? "Yes" : "No";
			cout << "Is it primal?: " << answer << endl;
		}
		else
			cout << "This number cannot be checked using this algorithm\n";
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;
}