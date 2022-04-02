#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

bool second_less(const pair<int, int>& m1, const pair<int, int>& m2) {
	if (m1.second == m2.second) return m1.first < m2.first;
	return m1.second > m2.second;
}


void Solution()
{
	vector<int> vec;

	map<int, int> mp;
	int N, cnt, input;
	double sum = 0, average;
	int freq_input;
	
	cin >> N;
	cnt = N;
	while (cnt--) {
		cin >> input;
		vec.push_back(input);
		mp[input] += 1;
		sum += input;
	}
	sort(vec.begin(), vec.end());
	vector<pair<int, int>> vec2(mp.begin(), mp.end());
	sort(vec2.begin(), vec2.end(), second_less);

	average = sum / N;
	average = floor(average + 0.5);

	cout << average << '\n';
	cout << vec[N/2] << '\n';
	if (N > 1 && vec2[0].second == vec2[1].second)
		cout << vec2[1].first << '\n';
	else
		cout << vec2[0].first << '\n';
	cout << (vec[N-1] - vec[0]) << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	Solution();
	return 0;
}