#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int c2i(char c) {
	return (int)c - 48;
}

void Solve()
{
	int A = 0, B = 0;
	string str;
	cin >> str;
	int sSize = str.size();

	if (str.size() >= 6) {
		if (c2i(str[0]) * 100 + c2i(str[1]) * 10 + c2i(str[2]) + 1 == c2i(str[3]) * 100 + c2i(str[4]) * 10 + c2i(str[5]))
		{
			A = str[0] * 100 + str[1] * 10 + str[2];
		}
	}
	if (str.size() >= 5) {
		if (c2i(str[0]) * 10 + c2i(str[1]) + 1 == c2i(str[2]) * 100 + c2i(str[3]) * 10 + c2i(str[4]))
		{
			A = str[0] * 10 + str[1];
		}
	}
	if (str.size() >= 4) {
		if (c2i(str[0]) * 10 + c2i(str[1]) + 1 == c2i(str[2]) * 10 + c2i(str[3]))
		{
			A = str[0] * 10 + str[1];
		}
	}
	if (str.size() >= 3) {
		if (c2i(str[0]) + 1 == c2i(str[1]) * 10 + c2i(str[2]))
		{
			A = str[0];
		}
	}
	if (c2i(str[0]) + 1 == c2i(str[1])) {
		A = str[0];
	}



	if (c2i(str[sSize - 2]) + 1 == c2i(str[sSize - 1])) {
		B = str[sSize - 1];
	}
	else if (sSize >= 3) {
		if (c2i(str[sSize - 3]) + 1 == c2i(str[sSize - 2]) * 10 + c2i(str[sSize - 1]))
		{
			B = str[sSize - 2] * 10 + str[sSize - 1];
		}
	}
	else if (sSize >= 4) {
		if (c2i(str[sSize - 4]) * 10 + c2i(str[sSize - 3]) + 1 == c2i(str[sSize - 2]) * 10 + c2i(str[sSize - 1]))
		{
			B = str[sSize - 2] * 10 + str[sSize - 1];
		}
	}
	else if (sSize >= 5) {
		if (c2i(str[sSize - 5]) * 10 + c2i(str[sSize - 4]) + 1== c2i(str[sSize - 3]) * 100 + c2i(str[sSize - 2]) * 10 + c2i(str[sSize - 1]))
		{
			B = str[sSize - 3] * 100 + str[sSize - 2] * 10 + str[sSize - 1];
		}
	}
	else if (sSize >= 6) {
		if (c2i(str[sSize - 6]) * 100 + c2i(str[sSize - 5]) * 10 + c2i(str[sSize - 4]) + 1 == c2i(str[sSize - 3]) * 100 + c2i(str[sSize - 2]) * 10 + c2i(str[sSize - 1]))
		{
			B = str[sSize - 3] * 100 + str[sSize - 2] * 10 + str[sSize - 1];
		}
	}




	cout << c2i(A) << " " << c2i(B);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}