#include <string>
#include <vector>
typedef std::vector<long long> XNumber;
bool isOk();
class XLong {

private:
	unsigned int l;
	std::vector<long long> p;
	
	static int max(int, int);

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
	static XNumber preconcat0(XNumber&, int);
	static XNumber trim0(XNumber&);
	static void show(XNumber&);

	unsigned int getLength();

	friend XLong operator + (XLong&, XLong&);
	friend XLong operator - (XLong&, XLong&);

	friend XNumber operator + (XNumber&, XNumber&);
	friend XNumber operator - (XNumber&, XNumber&);

	friend XLong operator * (XLong&, XLong&);

	friend XNumber operator * (XNumber&, int);
	
	static const long long base = 1000000;
	static unsigned int multType;
};

class Multiplier {
public:
	virtual XNumber XMult(XNumber&, XNumber&) = 0;
};

class KaratsubaMult: public Multiplier {
public:
	static XNumber XMult(XNumber&, XNumber&);
};