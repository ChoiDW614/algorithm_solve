#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
#define FAST_IO	ios_base::sync_with_stdio(false);	cin.tie(NULL);
using namespace std;


void Solution()
{
	while (true) {
		string input;
		stack<char> st;
		getline(cin, input);

		if (input == ".")	return;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == '(' || input[i] == '[')
				st.push(input[i]);
			if (!st.empty()) {
				if (input[i] == ')' && st.top() == '(')
					st.pop();
				else if (input[i] == ')')
					st.push(input[i]);
				if (input[i] == ']' && st.top() == '[')
					st.pop();
				else if (input[i] == ']')
					st.push(input[i]);
			}
			else if (input[i] == ')' || input[i] == ']')
				st.push(input[i]);
		}
		if (st.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
}

int main()
{
	FAST_IO;

	Solution();
	return 0;
}