#include <string>


class LucasLehmer{
	long long number;
	long long p = 0;
public:
	LucasLehmer() :number(0) {};
	LucasLehmer(long long a) :number(a) {};
	LucasLehmer(std::string a) :number(stol(a)) {};

	bool isPrimal() {	
		int s = 4;
		int k = 1;
		long long m = pow(2, p) - 1;
		while (k != p - 1) {
			s = (s*s - 2) % m;
			++k;
		}
		if (s == 0)
			return true;
		return false;
	};
	
	bool isValid() {
		long long temp = 1;
		while (temp < number + 1) {
			temp *= 2;
			++p;
		}
		if (temp == number + 1)
			return true;
		return false;
	}

	friend std::ostream& operator<<(std::ostream& os, const LucasLehmer& ll) {
		os << ll.number;
		return os;
	};
};
