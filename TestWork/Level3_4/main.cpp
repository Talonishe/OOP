#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Base
{
protected:
	int n;

public:
	Base(int x)
	{
		n = x;
	}

	virtual ~Base() {}

	virtual int factorial(int x)
	{
		if (x <= 1)
			return 1;

		int f = 1;
		
		for (int i = 1; i <= x; i++)
			f *= i;

		return f;
	}
};

class Derived : public Base
{
private:
	int arr[100];

public:
	Derived(int size) : Base(size)
	{
		cout << "Enter " << size << " elements:\n";
		for (int i = 0; i < n; i++)
			cin >> arr[i];
	}

	void show()
	{
		cout << "Number\tFactorial\n";

		for (int i = 0; i < n; i++)
			cout << arr[i] << "\t" << factorial(arr[i]) << endl;
	}
};

int main()
{
	Derived d(5);

	d.show();

	return 0;
}