#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);   cin.tie(NULL), cout.tie(NULL);
using namespace std;

vector<pair<int, int>> p1, p2;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second > b.second;
}

void Solve()
{
	int N, M, input;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		p1.push_back(make_pair(i, input));
	}
	cin >> M;
	
	if (N == 1) { cout << 0; return; }

	sort(p1.begin(), p1.end(), compare);
	
	int sum = 0, cnt = 0;
	while (1) {
		if (!cnt) {
			if ((p1.back().first == 0) && (p1[N - 2].second <= M)) {
				p2.push_back(p1[N - 2]);
				sum += p2.back().second;
				cnt++;
				continue;
			}
			else if ((p1.back().first != 0) && p1[N - 2].second > M) {
				p2.push_back(p1.back());
				sum += p1.back().second;
				cnt++;
				continue;
			}
			else if (p1[N - 2].second > M) {
				cout << 0;
				return;
			}
		}
		if (sum + p1.back().second > M)
			break;
		p2.push_back(p1.back());
		sum += p1.back().second;
		cnt++;
	}

	for (int i = 0; i < p2.size(); i++) {
		pair<int, int> tmp = p2[i];
		for (int j = 0; j < N - 1; j++) {
			if (tmp.first < p1[j].first && (M - sum + tmp.second >= p1[j].second))
				tmp = p1[j];
		}
		sum -= p2[i].second;
		p2[i] = tmp;
		sum += p2[i].second;
		if (M == sum) break;
	}
	
	for (int i = 0; i < p2.size(); i++) {
		cout << p2[i].first;
	}
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}