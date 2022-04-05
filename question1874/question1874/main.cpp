#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);
#define Max_size	100001

void Solve()
{
	int n, k = 1;
	std::cin >> n;
	int input[Max_size];
	std::stack<int> st;
	std::string v;

	for (int i = 1; i <= n; i++)	std::cin >> input[i];

	for (int i = 1; i <= n; i++)
	{
		if (k <= n)
		{
			while (input[i] > k)
			{
				st.push(k);
				v += '+';
				k++;
			}
			if (input[i] == k) {
				v += '+';
				v += '-';
				k++;
			}
		}
		if (!st.empty() && input[i] == st.top())
		{
			st.pop();
			v += '-';
		}
	}
	if (!st.empty()) {
		std::cout << "NO";
		return;
	}
	else {
		for (int i = 0; i < v.size(); i++)
			std::cout << v[i] << '\n';
		return;
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}