#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

class MyArray
{

public:
	MyArray(int r = 0, int s = 0) {
		reel = r;
		sanal = s;

	}

public:
	double virtualSortFunction() {
		int a, b;
		double c;
		int getReel();
		int getSanal();
		void setReel(int r);
		void setSanal(int s);
		void print();
		a = getReel();
		b = getSanal();

		c = sqrt((double)a * (double)a + ((double)b * (double)b));

		return c;

	}

	int getReel()
	{
		return reel;
	}

	int getSanal()
	{
		return sanal;
	}

	void setReel(int r)
	{
		reel = r;
	}

	void setSanal(int s)
	{
		sanal = s;
	}

	void print()
	{
		if (sanal > 0)
			cout << reel << " + " << sanal << "i" << endl;
		else if (sanal < 0)
			cout << reel << " - " << -sanal << "i" << endl;
		else
			cout << reel << endl;
	}

protected:
	int reel;
	int sanal;


};

class TwoD : public MyArray
{



public:
	TwoD(int reel = 0, int sanal = 0) {

		this->reel = reel;
		this->sanal = sanal;

		int TwoDArray[1][2] = {
		{reel, sanal},

		};

		printf("Calling Constructor, Creating a Complex Number from 2D Array: ");

	}


};


class OneD : public MyArray
{

public:
	OneD(int r, int s) {

		reel = r;
		sanal = s;

		int OneDArray[1][2] = {
		{r, s},

		};

		printf("Calling Constructor, Creating a Complex Number from 1D Array: ");

	}

};

// sum overloading

MyArray operator+(MyArray obj1, MyArray obj2)
{
	MyArray toplam;
	toplam.setReel(obj1.getReel() + obj2.getReel());
	toplam.setSanal(obj1.getSanal() + obj2.getSanal());
	return toplam;
}

// substraction overloading

MyArray operator-(MyArray obj1, MyArray obj2)
{
	MyArray cýkarma;
	cýkarma.setReel(obj1.getReel() - obj2.getReel());
	cýkarma.setSanal(obj1.getSanal() - obj2.getSanal());
	return cýkarma;
}

// * overloading

MyArray operator*(MyArray obj1, MyArray obj2)
{
	MyArray multiply;
	multiply.setReel((obj1.getReel() * obj2.getReel()) - (obj1.getSanal() * obj2.getSanal()));
	multiply.setSanal(((obj1.getReel() * obj2.getSanal())) + (obj2.getReel() * obj1.getSanal()));
	return multiply;
}


// cout overloading

ostream& operator<<(ostream& out, MyArray obj)
{
	int sanal = obj.getSanal();
	int reel = obj.getReel();

	if (sanal > 0)
		out << reel << " + " << sanal << "i" << endl;
	else if (sanal < 0)
		out << reel << " - " << -sanal << "i" << endl;
	else
		out << reel << endl;
	return out;
}


int main() {


	OneD k1(1, 4);
	cout << k1 << endl;
	TwoD k2(2, 3);
	cout << k2 << endl;
	OneD k3(3, 2);
	cout << k3 << endl;
	TwoD k4(4, 1);
	cout << k4 << endl;

	printf("Sum of first and second complex numbers: ");
	MyArray k5 = k1 + k2;
	cout << k5 << endl;
	printf("Substraction of first and second 2 complex numbers: ");
	MyArray k6 = k1 - k2;
	cout << k6 << endl;
	printf("Multiplication of first and second  2 complex numbers: ");
	MyArray k7 = k1 * k2;
	cout << k7 << endl;


	// ranking
	printf("Ranking of the 3rd and 4th numbers: ");

	k3.virtualSortFunction();
	double d = k3.virtualSortFunction();
	k4.virtualSortFunction();
	double e = k4.virtualSortFunction();

	if (d < e) {
		printf("k4>k3");
	}
	else {
		printf("k3>k4");
	}


	return 0;
}