#include <bits/stdc++.h>
#define FASTIO	ios_base::sync_with_stdio(false); cin.tie(NULL);	cout.tie(NULL);
using namespace std;

int parent[51];
vector<int> v;

int getParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool unionFind(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) return true;
	return false;
}

void Solve()
{
	int i, j, input, N, M, numOfTrue, numOfPartyPerson, person, cnt;
	cin >> N >> M >> numOfTrue;
	for (i = 1; i <= N; i++) {
		parent[i] = i;
	}

	if (numOfTrue == 0) {
		cout << M;
		return;
	}

	int trueperson = -1;
	cin >> trueperson;
	for (i = 0; i < numOfTrue - 1; i++) {
		cin >> input;
		unionParent(parent, trueperson, input);
	}

	cnt = 0;
	int per[51];
	for (i = 1; i <= M; i++) {
		cin >> numOfPartyPerson;
		per[i] = -1;
		for (j = 0; j < numOfPartyPerson; j++) {
			if (j == 0) {
				cin >> per[i];
			}
			else {
				cin >> person;
				unionParent(parent, per[i], person);
			}
		}
	}
	
	for (i = 1; i <= M; i++) {
		if (per[i] != -1 && unionFind(parent, trueperson, per[i])) {
			unionParent(parent, trueperson, per[i]);
		}
		else
			cnt++;
	}
	cout << cnt;
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}