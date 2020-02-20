#include <string>

class PrimalTest {
public:
	virtual bool isPrimal() = 0;
	virtual bool isValid() = 0;
};

class LucasLehmer: public PrimalTest{
	long long p = 0;
	long long number;

public:
	LucasLehmer() :number(0) {};
	LucasLehmer(long long a) :number(a) {};
	LucasLehmer(std::string a) :number(stoll(a)) {};

	bool isPrimal();
	bool isValid();

	friend std::ostream& operator<<(std::ostream& os, const LucasLehmer& ll);
};

class Lehmann : public PrimalTest {
	long long number;

public:
	Lehmann() :number(0) {};
	Lehmann(long long a) :number(a) {};
	Lehmann(std::string a) :number(stol(a)) {};

	bool isPrimal();
	bool isValid();

	friend std::ostream& operator<<(std::ostream& os, const Lehmann& ll);
};

class RabinMiller : public PrimalTest {
	long long number;
	int k = 10;

public:
	RabinMiller() :number(0) {};
	RabinMiller(long long a) :number(a) {};
	RabinMiller(std::string a) :number(stol(a)) {};

	bool isPrimal();
	bool isValid();

	friend std::ostream& operator<<(std::ostream& os, const RabinMiller& ll);
};

class SolovayStrassen : public PrimalTest {
	long long number;
	int k = 20;
public:
	SolovayStrassen() :number(0) {};
	SolovayStrassen(long long a) :number(a) {};
	SolovayStrassen(std::string a) :number(stol(a)) {};

	bool isPrimal();
	bool isValid();
	static long long GCD(long long a, long long b);
	static long long jSymbol(int, long long a, long long b);

	friend std::ostream& operator<<(std::ostream& os, const SolovayStrassen& ll);
};