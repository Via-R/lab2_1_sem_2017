#include <iostream>
#include <cmath>
#include "XLong.h"
int counter = 0;
unsigned int XLong::multType = 0;
bool isOk(){
	return true;
}
XLong::XLong(){
	l = 10;
	//p = new long long[l];
	//for (int i = 0; i < l; i++)
		//*(p + i) = 1;
}
XLong::XLong(int a) {
	l = a;
}
XLong::XLong(std::string n) {
	
	l = n.length();
	char * cnum = new char[l];
	strcpy(cnum, n.c_str());
	//std::cout << "BASE " << base << std::endl;
	long long tempSum = 0;
	int i = l-1, j = 0;
	while (i >= 0) {
		//std::cout << "Block skipped\n";
		int k = 0;
		
		while ((i >= 0 && tempSum + (*(cnum + i) - 48)*pow(10, k) < base) && *(cnum + i) - 48 > 0) {
			//std::cout << "! " << i << std::endl;
			//std::cout << (*(cnum + i) - 48)*pow(base,k) << std::endl;
			tempSum += (*(cnum + i) - 48)*pow(10, k);
			++k;
			--i;
		}
		
		
		p.insert(p.begin(), tempSum);
		
		if (*(cnum + i) - 48 == 0 && tempSum > 0)
			p.insert(p.begin(), 0);
		if (*(cnum + i) - 48 == 0)
			--i;
		tempSum = 0;
	}
}
int XLong::max(int a, int b) {
	return a > b ? a : b;
}

void XLong::print() {
	std::cout << "Length: " << l << std::endl;
	for (XNumber::const_iterator i = p.begin(); i != p.end(); ++i)
		std::cout << *i << ' ';
	std::cout << std::endl;
}

XNumber XLong::add(XNumber& n1, XNumber& n2) {
	
	XNumber c;
	long long m = 0;

	XNumber::reverse_iterator it1 = n1.rbegin(), it2 = n2.rbegin();
	for (; it1 != n1.rend() && it2 != n2.rend(); ++it1, ++it2) {
		c.insert(c.begin(), m);
		
		m = (*it1 + *it2) / XLong::base;
		if((c[0] + (*it1 + *it2)) < XLong::base)
			c[0] += (*it1 + *it2);
		else {
			m = (c[0] + (*it1 + *it2)) / XLong::base;
			c[0] = (c[0] + *it1 + *it2) % XLong::base;
		}
	}

	for (; it1 != n1.rend(); ++it1) {
		c.insert(c.begin(), (*it1 + m) % XLong::base);
		m = (*it1 + m) / XLong::base;
	}
	for (; it2 != n2.rend(); ++it2) {
		c.insert(c.begin(), (*it2 + m) % XLong::base);
		m = (*it2 + m) / XLong::base;
	}
	if (m > 0) {
		c.insert(c.begin(), m);
	}
	return c;
}

XNumber XLong::substract(XNumber& n1, XNumber& n2) {
	//XLong c(XLong::max(n1.size(), n2.size()));
	/*std::cout << "Test\n";
	XLong::show(n1);
	XLong::show(n2);
	std::cout << "End of init\n";*/
	XNumber c;
	long long m = 0;

	XNumber::reverse_iterator it1 = n1.rbegin(), it2 = n2.rbegin();
	for (; it1 != n1.rend() && it2 != n2.rend(); ++it1, ++it2) {
		c.insert(c.begin(), 0);
		c[0] += (m + XLong::base + *it1 - *it2) % XLong::base;
		m = (m + XLong::base + *it1 - *it2 >= 10) ? 0 : -1;
	}

	for (; it1 != n1.rend(); ++it1) {
		c.insert(c.begin(), (*it1 + XLong::base + m) % XLong::base);
		m = (*it1 + m + XLong::base) >= 10 ? 0 : -1;
	}
	
	for (XNumber::const_iterator i = c.begin(); i != c.end()-1;) {
		if (*i == 0)
			i = c.erase(i);
		else
			break;
	}
	return c;
}

XLong operator + (XLong &n1, XLong &n2){
	XLong c(XLong::max(n1.p.size(), n2.p.size()));
	c.p = XLong::add(n1.p, n2.p);
	return c;
}
XLong operator - (XLong& a, XLong& b) {
	XLong c(a.l);
	c.p = XLong::substract(a.p, b.p);
	c.l = c.p.size();
	return c;
}
XLong operator * (XLong& a, XLong& b) {
	XLong c;
	XNumber result;
	if(XLong::multType == 0)
		result = KaratsubaMult::XMult(a.p, b.p);

	c.p = result;
	c.l = result.size();
	return c;
}
unsigned int XLong::getLength() {
	return l;
}

XNumber KaratsubaMult::XMult(XNumber& a, XNumber& b) {
	//a0b0
	//(a0+a1)(b0+b1)
	//a1b1
	
	
	//std::cout << counter++ << " F started\n";
	
	
	XNumber a0, a1, b0, b1, a0b0, a1b1, sum;


	if (a.size() > b.size())
		b = XLong::preconcat0(b, a.size() - b.size());
	else if (a.size() < b.size())
		a = XLong::preconcat0(a, b.size() - a.size());

	int n = a.size() % 2 == 0 ? a.size() / 2 : a.size() / 2 + 1;
	int m = b.size() % 2 == 0 ? b.size() / 2 : b.size() / 2 + 1;
	
	int s = n > a.size() - n ? a.size() - n : n;
	
	XNumber::reverse_iterator it1 = a.rbegin(), it2 = b.rbegin();
	for (; it1 != a.rend()-n; ++it1) {
		a0.insert(a0.begin(), *it1);
	}
	for (; it1 != a.rend(); ++it1) {
		a1.insert(a1.begin(), *it1);
	}
	for (; it2 != b.rend() - m; ++it2) {
		b0.insert(b0.begin(), *it2);
	}
	for (; it2 != b.rend(); ++it2) {
		b1.insert(b1.begin(), *it2);
	}

	/*
	std::cout << "--------------------------------<\na0:\n";
	XLong::show(a0);

	std::cout << "a1:\n";
	XLong::show(a1);

	std::cout << "b0:\n";
	XLong::show(b0);

	std::cout << "b1:\n";
	XLong::show(b1);

	std::cout << "-------------------------------->\n";

	//*/

	if (a0.size() == 1 && b0.size() == 1) {
		a0b0.insert(a0b0.begin(), (a0[0] * b0[0]) % XLong::base);
		if ((a0[0] * b0[0]) / XLong::base > 0) {
			a0b0.insert(a0b0.begin(), (a0[0] * b0[0]) / XLong::base);
			a0b0[1] = a0b0[1] % XLong::base;
		}
	}
	else
		a0b0 = KaratsubaMult::XMult(a0, b0);

	if (a1.size() == 1 && b1.size() == 1) {
		a1b1.insert(a1b1.begin(), a1[0] * b1[0]);
		if ((a1[0] * b1[0]) / XLong::base > 0) {
			a1b1.insert(a1b1.begin(), (a1[0] * b1[0]) / XLong::base);
			a1b1[1] = a1b1[1] % XLong::base;
		}
	}
	else
		a1b1 = KaratsubaMult::XMult(a1, b1);
	
	XNumber temp1 = XLong::add(a0, a1), temp2 = XLong::add(b0, b1);
	if (temp1.size() == 1 && temp2.size() == 1) {
		sum.insert(sum.begin(), temp1[0] * temp2[0]);
		if ((temp1[0] * temp2[0]) / XLong::base > 0) {
			sum.insert(sum.begin(), (temp1[0] * temp2[0]) / XLong::base);
			sum[1] = sum[1] % XLong::base;
		}
	}
	else
		sum = KaratsubaMult::XMult(temp1, temp2);

	a0b0 = XLong::trim0(a0b0);
	a1b1 = XLong::trim0(a1b1);
	sum = XLong::trim0(sum);
	
	/*
	std::cout << "--------------------------------<\n00:\n";
	XLong::show(a0b0);

	std::cout << "11:\n";
	XLong::show(a1b1);

	std::cout << "():\n";
	XLong::show(sum);

	std::cout << "() - 00 - 11, where s = "<< s <<":\n";
	XLong::show((sum - a0b0 - a1b1) * s);

	std::cout << counter-- << " F ended\n-------------------------------->\n";

	//return XLong::add(XLong::add(a0b0, XLong::concat0(XLong::substract(XLong::substract(sum, a0b0), a1b1), s)), XLong::concat0(a1b1, 2 * s));*/
	return a0b0 + (sum - a0b0 - a1b1) * s + a1b1 * (s + s);
}

XNumber XLong::inv(XNumber& a) {
	XNumber b;
	for (XNumber::reverse_iterator it1 = a.rbegin(); it1 != a.rend(); ++it1) {
		b.insert(b.begin(), (*it1)*-1);
	}
	return b;
}
XNumber XLong::concat0(XNumber&a, int s) {
	XNumber res = a;
	for (int i = 0; i < s; i++)
		res.insert(res.end(), 0);
	return res;
};
XNumber XLong::preconcat0(XNumber&a, int s) {
	XNumber res = a;
	for (int i = 0; i < s; i++)
		res.insert(res.begin(), 0);
	return res;
};
void XLong::show(XNumber&q) {
	for (XNumber::const_iterator i = q.begin(); i != q.end(); ++i)
		std::cout << *i << " ";
	std::cout << "\n\n";
}

XNumber operator + (XNumber&a, XNumber&b) {
	return XLong::add(a, b);
}

XNumber operator - (XNumber&a, XNumber&b) {
	return XLong::substract(a, b);
}

XNumber operator * (XNumber&a, int b) {
	return XLong::concat0(a, b);
}
XNumber XLong::trim0(XNumber& a) {
	XNumber c = a;
	for (XNumber::const_iterator i = c.begin(); i != c.end() - 1;) {
		if (*i == 0)
			i = c.erase(i);
		else
			break;
	}
	return c;
}
