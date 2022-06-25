#include <bits/stdc++.h>
#define FAST_IO	ios_base::sync_with_stdio(false);	cin.tie(NULL);

using namespace std;
int vertex[101];
int vplus[101];
int edge[101];
int eplus[101];

int getvPlus(int n)
{
	if (n == 1) {
		vplus[1] = 1;
		return vplus[1];
	}
	if (vplus[n] != 0)
		return vplus[n];
	if (n % 3 != 0) {
		vplus[n] = getvPlus(n - 1) + 1;
		return vplus[n];
	}
	else {
		vplus[n] = getvPlus(n - 1);
		return vplus[n];
	}
}

int getVertex(int n)
{
	if (n == 1) {
		vertex[1] = 0;
		return vertex[1];
	}
	if (vertex[n] != 0)
		return vertex[n];
	vertex[n] = getVertex(n - 1) + getvPlus(n - 1);
	return vertex[n];
}

int getePlus(int n)
{
	if (n == 1) {
		eplus[1] = 3;
		return eplus[1];
	}
	if (eplus[n] != 0)
		return eplus[n];
	if (n % 3 != 0) {
		eplus[n] = getePlus(n - 1) + 2;
		return eplus[n];
	}
	else {
		eplus[n] = getePlus(n - 1);
		return eplus[n];
	}
}

int getEdge(int n)
{
	if (n == 1) {
		edge[1] = 1;
		return edge[1];
	}
	if (edge[n] != 0)
		return edge[n];
	edge[n] = getEdge(n - 1) + getePlus(n - 1);
	return edge[n];
}

void Solve()
{
	int N;
	cin >> N;
	cout << 1 - getVertex(N) + getEdge(N);
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}