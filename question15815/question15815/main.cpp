#include <iostream>
#include <stack>
#include <string>

void solve() {
	std::string inputString;
	getline(std::cin, inputString);

	std::stack<int> s;

	for (auto iter = inputString.begin(); iter != inputString.end(); iter++)
	{
		if (*iter >= '0' && *iter <= '9')
		{
			s.push(*iter - '0');
		}
		else
		{
			int ps1, ps2;
			ps2 = s.top();
			s.pop();
			ps1 = s.top();
			s.pop();
			switch (*iter)
			{
			case '+':
				s.push(ps1 + ps2);
				break;
			case '-':
				s.push(ps1 - ps2);
				break;
			case '*':
				s.push(ps1 * ps2);
				break;
			case '/':
				s.push(ps1 / ps2);
				break;
			}
		}
	}
	std::cout << s.top();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	solve();
}