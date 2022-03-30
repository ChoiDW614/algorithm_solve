#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> premutation, arr;
bool check[8];

void calpermutation(int n, int depth)
{
	if (depth == M) {
		for (int i = 0; i < M; i++) {
			cout << premutation[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = n; i < N; i++)
	{
		if (check[i] == true) continue;
		check[i] = true;
		premutation.push_back(arr[i]);
		calpermutation(i, depth + 1);
		premutation.pop_back();
		check[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	calpermutation(0, 0);

	return 0;
}