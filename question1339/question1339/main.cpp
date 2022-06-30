#include <bits/stdc++.h>
#define FASTIO 	ios_base::sync_with_stdio(false);   cin.tie(NULL), cout.tie(NULL);
using namespace std;
typedef long long ll;

vector<int[8]> v1(26);
int arr[11][8];
ll num[10];

bool cmp1(pair<char, int> p1, pair<char, int> p2)
{
	if (p1.second == p2.second) return p1.first > p2.first;
	else	return p1.second > p2.second;
}

bool cmp2(pair<char, int> p1, pair<char, int> p2)
{
	return p1.first < p2.first;
}


void Solve()
{
	string str[10];
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> str[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < str[i].size(); j++) {
			v1[(int)(str[i][j] - 'A')][8 - str[i].size() + j]++;
		}
	}

	vector<pair<char, int>> v;
	for (int i = 0; i < 26; i++) {
		int cnt = 0;
		bool check = false;
		for (int j = 0; j < 8; j++) {
			if (v1[i][j] != 0)
				check = true;
		}
		if (!check)
			continue;
		for (int j = 0; j < 8; j++) {
			cnt += v1[i][j] * (ll)pow(10, 7 - j);
		}
		v.push_back({ (char)(i + 65), cnt });
	}
	sort(v.begin(), v.end(), cmp1);
	for (int i = 0; i < v.size(); i++) {
		v[i].second = 9 - i;
	}
	sort(v.begin(), v.end(), cmp2);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < str[i].size(); j++) {
			if (str[i][j] == 0) continue;
			for (int k = 0; k < v.size(); k++) {
				if (str[i][j] == v[k].first) {
					num[i] += v[k].second * (ll)pow(10, str[i].size() - j - 1);
				}
			}
		}
	}

	ll sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += num[i];
	}

	cout << sum;
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}