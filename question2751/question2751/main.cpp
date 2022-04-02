#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Solution()
{
	vector<int> vec;
	int N, input;
	cin >> N;
	while (N--) {
		cin >> input;
		vec.push_back(input);
	}
	sort(vec.begin(), vec.end());
	for (auto i = vec.begin(); i < vec.end(); i++) {
		cout << *i << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	Solution();
	return 0;
}