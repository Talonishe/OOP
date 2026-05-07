#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<string> st;

	st.push("Hello");
	st.push("Programming");
	st.push("C++");

	string longest = "";

	while (!st.empty())
	{
		string s = st.top();

		if (s.length() > longest.length())
			longest = s;

		cout << s << endl;

		st.pop();
	}

	cout << "Longest: " << longest;

	return 0;
}
