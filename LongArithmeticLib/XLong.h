#include <string>
#include <vector>
typedef std::vector<long long> XNumber;
bool isOk();


class Multiplier {
public:
	virtual XNumber XMult(XNumber&, XNumber&) = 0;
};

class KaratsubaMult : public Multiplier {
public:
	XNumber XMult(XNumber&, XNumber&);
};

class SimpleMult : public Multiplier {
public:
	XNumber XMult(XNumber&, XNumber&);
};

class XLong {
private:
	unsigned int l;
	std::vector<long long> p;
	
	static int max(int, int);

	static Multiplier * currType;
	//int from1, to1, from2, to2;
public:
	XLong();
	XLong(int);
	XLong(std::string);
	
	void print();
	
	static XNumber add(XNumber&, XNumber&);
	static XNumber substract(XNumber&, XNumber&);
	static XNumber inv(XNumber&);
	static XNumber concat0(XNumber&, int);
	static XNumber advancedConcat0(XNumber&, int);
	static XNumber preconcat0(XNumber&, int);
	static XNumber trim0(XNumber&);


	static XNumber multByInt(XNumber&, int b);
	static XNumber toBinary(XNumber&);
	static XNumber div2(XNumber&);

	static int getDigitsNum(int);


	static void show(XNumber&);

	unsigned int getLength();

	friend XLong operator + (XLong&, XLong&);
	friend XLong operator - (XLong&, XLong&);

	friend XNumber operator + (XNumber&, XNumber&);
	friend XNumber operator - (XNumber&, XNumber&);

	friend XLong operator * (XLong&, XLong&);

	friend XNumber operator >> (XNumber&, int);
	
	static const long long base = 1000000;

	static void setMultType(int);
};

