#include <iostream>
#include "XLong.h"
#include <fstream>

using namespace std;
int main() {
	cout << "All systems are functional: " << isOk() <<"\n";
	string num1, num2;
	ifstream myfile("input.txt");
	if (myfile.is_open()){
		getline(myfile, num1);
		getline(myfile, num2);
		cout << "Number 1: " << num1 << "\nNumber 2: " << num2 << endl;
		myfile.close();

		XLong::multType = 0;

		XLong a(num1);
		XLong b(num2);
		XLong mult = a * b;
		mult.print();
		
		/*XLong q("1000"), w("0"), e("0");
		//XLong q("90060000"), w("20000200"), e("1908");
		(q - w - e).print();
		//XLong temp = -d;
		//d.print();
		//XNumber res = KaratsubaMult::XMult()*/
	}
	else cout << "Unable to open file";
	system("pause");
	return 0;
}