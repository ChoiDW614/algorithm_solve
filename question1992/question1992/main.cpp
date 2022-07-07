#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;

int matrix[65][65];

void div(int x, int y, int n)
{
	int check;
	check = matrix[x][y];
	bool notsame = false;
	for (int i = x; i < x + n && !notsame; i++) {
		for (int j = y; j < y + n && !notsame; j++) {
			if (check != matrix[i][j]) {
				notsame = true;
				break;
			}
		}
	}

	if (!notsame) {
		cout << check;
	}
	else {
		cout << "(";
		div(x, y, n / 2);
		div(x, y + n / 2, n / 2);
		div(x + n / 2, y, n / 2);
		div(x + n / 2, y + n / 2, n / 2);
		cout << ")";
	}
}

void Solve()
{
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= N; j++) {
			matrix[i][j] = static_cast<int>(str[j - 1]) - 48;
		}
	}
	div(1, 1, N);
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}