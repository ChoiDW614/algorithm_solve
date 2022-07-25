#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;

void Solve()
{
	map<string, string> mp;
	string str1, str2;
	int i, N, M;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		cin >> str1 >> str2;
		mp[str1] = str2;
	}
	for (i = 0; i < M; i++) {
		cin >> str1;
		cout << mp[str1] << '\n';
	}
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}