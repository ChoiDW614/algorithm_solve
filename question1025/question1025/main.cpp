#include <bits/stdc++.h>
#define FAST_IO	ios_base::sync_with_stdio(false);	cin.tie(NULL);

using namespace std;
int Matrix[9][9];
typedef long long ll;

void Solve()
{
	int squareValue = -1;
	int N, M;
	cin >> N >> M;
	string input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < M; j++) {
			Matrix[i][j] = ((int)input[j] - 48);
		}
	}

	string num;
	for (int j = 0; j < M; j++) {
		for (int i = 0; i < N; i++)	// pos
		{
			num.clear();
			for (int l = 1; l <= N; l++)	// length
			{
				num.clear();
				for (int k1 = 0, k2 = 0; i + l * k1 < N || k2 <= l; k1++, k2++) {
					num += to_string(Matrix[i][j + k1]);
					cout << stoi(num) << '\n';
				}

			}


				



		}
	}


	


	cout << squareValue;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}