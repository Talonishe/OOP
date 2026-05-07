#include <iostream>
#include <cmath>
using namespace std;

class Equation
{
public:
	virtual void roots() = 0;
};

class Linear : public Equation
{
private:
	double a, b;

public:
	Linear(double x, double y)
	{
		a = x;
		b = y;
	}

	void roots()
	{
		cout << "x = " << -b / a << endl;
	}
};

class Quadratic : public Equation
{
private:
	double a, b, c;

public:
	Quadratic(double x, double y, double z)
	{
		a = x;
		b = y;
		c = z;
	}

	void roots()
	{
		double d = b * b - 4 * a*c;

		if (d >= 0)
		{
			cout << (-b + sqrt(d)) / (2 * a) << endl;
			cout << (-b - sqrt(d)) / (2 * a) << endl;
		}
	}
};

int main()
{
	Equation* eq[2];

	eq[0] = new Linear(2, 4);
	eq[1] = new Quadratic(1, -3, 2);

	for (int i = 0; i < 2; i++)
		eq[i]->roots();

	return 0;
}