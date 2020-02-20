#include <iostream>
#include "PrimalTest.h"
double getRandNum();

long long modPow(long long a, long long p, long long m) {
	long long temp = a;
	while (p - 1) {
		a *= temp;
		a %= m;
		--p;
	}
	return a;
};

bool LucasLehmer::isPrimal(){
	long long s = 4;
	long long m = pow(2, p) - 1;
	for (int k = 0; k < p - 2; ++k) {
		s = ((s * s) - 2) % m;
	}
	if (s == 0)
		return true;
	return false;
}
bool LucasLehmer::isValid() {
	long long temp = 1;
	while (temp < number + 1) {
		temp *= 2;
		++p;
	}
	if (temp == number + 1)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const LucasLehmer& ll){
	os << ll.number;
	return os;
};



/*-----------------------------------------------------------------------------*/



bool Lehmann::isValid() {
	return true;
}

bool Lehmann::isPrimal() {
	long long r = (getRandNum())*(number);
	if (r == 1)++r;
	if (r == 0)r=2;
	long long q = modPow(r, (number - 1) / 2, number);
	//std::cout << "R: " << r << std::endl;
	//q %= number;
	if (q == number - 1)
		q = -1;
	//std::cout << "Q: " << q << std::endl;

	if (q == 1 || q == -1)
		return true;
	return false;
}
std::ostream& operator<<(std::ostream& os, const Lehmann& ll) {
	os << ll.number;
	return os;
};



/*-----------------------------------------------------------------------------*/



bool RabinMiller::isValid() {
	return true;
}

bool RabinMiller::isPrimal() {
	if (number % 2 == 0)
		return false;
	long long t = number - 1, p, s = 0;
	while (t % 2 == 0) {
		++s;
		t /= 2;
	}
	for (int i = 0; i < k; ++i) {
		long long a = (long long)(getRandNum()*(number - 4) + 2);
		long long x = modPow(a, t, number);
		//x %= number;
		if (x == 1 || x == number - 1)
			continue;
		bool skip = false;
		for (int j = 0; j < s - 1; ++j) {
			x *= x;
			x %= number;
			if (x == 1)
				return false;
			else if (x == number - 1) {
				skip = true;
				break;
			}
		}
		if(!skip)
			return false;
	}
	//std::cout << t << " " << s << std::endl;
	return true;
}
std::ostream& operator<<(std::ostream& os, const RabinMiller& ll) {
	os << ll.number;
	return os;
};



/*-----------------------------------------------------------------------------*/



bool SolovayStrassen::isValid() {
	return true;
}

bool SolovayStrassen::isPrimal() {
	if (number == 2)
		return true;
	if (number % 2 == 0)
		return false;
	for (int i = 1; i <= k; ++i) {
		long long a = getRandNum() * (number - 3) + 2;
		if (GCD(a, number) > 1) {
			return false;
		}
		long long temp = modPow(a, (number - 1) / 2, number);
		int tempSign = float(a) / number > 0 ? 1 : -1;
		long long symbol = jSymbol(tempSign, a, number);
		long long toTest = temp;// % number;
		if (temp % number == number - 1) {
			toTest = -1;
		}
		if (toTest != symbol)
			return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const SolovayStrassen& ll) {
	os << ll.number;
	return os;
};

long long SolovayStrassen::GCD(long long a, long long b) {
	long long k = 1;
	while ((a != 0) && (b != 0)) {
		while ((a % 2 == 0) && (b % 2 == 0)) {
			a /= 2;
			b /= 2;
			k *= 2;
		}
		while (a % 2 == 0) a /= 2;
		while (b % 2 == 0) b /= 2;
		if (a >= b)
			a -= b;
		else
			b -= a;
	}
	return b * k;
}
/*long long SolovayStrassen::jSymbol(long long a, long long b) {
	if (GCD(a, b) != 1)
		return 0;
	long long r = 1;
	if (a < 0) {
		a = -a;
		if (b % 4 == 3)
			r = -r;
	}
	long long t = 0;
	do {
		while (a % 2 == 0) {
			++t;
			a /= 2;
		}
		if (t % 2 == 1) {
			if (b % 8 == 3 || b % 8 == 5)
				r = -r;
		}

		if (a % 4 == b % 4 && b % 4 == 3) {
			r = -r;
			long long c = a;
			a = b % c;
			b = c;
		}
	} while (a != 0);
	return r;
}
*//*
long long SolovayStrassen::jSymbol(long long a, long long b) {
	long long s = 0, u = a, v = b;
	long long r, k, t;
	do {
		r = u % v;
		k = t = 0;
		while (r % 2 == 0 && r > 0){
			k++;
			r >>= 1;
		}
		t = r;
		s = (s + k * (v*v - 1) / 8 + (t - 1)*(v - 1) / 4) % 2;
		if (t == 1)
			return (s) ? -1 : 1;
		u = v;
		v = t;
	} while (t >= 3);
	//std::cout << "DHUSNDJSKDNWJKDNDJKNDKOWDNKNKLW\n";
}
*/




long long SolovayStrassen::jSymbol(int s, long long a, long long b) {

//function jacobi(a) {
	int B0;
	long long B1, B2;
	B0 = 1; B1 = 1; B2 = 1; // Array(1,1,1);
	int sign = s;
	long long m = a;
	long long n = b;
//	if (sign > 0) out.put("(" + m + "/" + n + ") = ");
//	if (sign < 0) out.put("-(" + m + "/" + n + ") = ");
	if (m > n - 1) {
		m = m % n;
		//if (sign > 0) out.put("(" + m + "/" + n + ") = ");
		//if (sign < 0) out.put("-(" + m + "/" + n + ") = ");
	}
	m = m % n;
	if (m == 0) {
		//out.put("0");
		return 0;
	}
	if (m == 1) {
		if (sign > 0) { /*out.put("1");*/ return 1; }
		//out.put("-1");
		return -1;
	}
	long long J2n = 1;
	if ((3 == (n % 8)) || (5 == (n % 8))) J2n = -1;
	if (0 == (m % 2)) {
		B0 = J2n*sign;
		B1 = m / 2;
		B2 = n;
		return jSymbol(B0, B1, B2);
	}
	if ((3 == (n % 4)) && (3 == (m % 4))) {
		B0 = -sign;
		B1 = n % m;
		B2 = m;
		return jSymbol(B0, B1, B2);
	}
	else {
		B0 = sign;
		B1 = n % m;
		B2 = m;
		return jSymbol(B0, B1, B2);
	}
}