#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false);	cin.tie(NULL);

using namespace std;

void Solve()
{
	int A, B, C;
	cin >> A >> B >> C;
	cout << (A + B) % C << '\n' << ((A % C) + (B % C)) % C << '\n' << (A * B) % C << '\n' << ((A % C) * (B % C)) % C;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}