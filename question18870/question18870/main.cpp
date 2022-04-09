#include <iostream>
#include <map>
#include <vector>
#define FAST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr)
typedef long long ll;

std::map <ll, ll> mp;
std::vector<ll> vec;

void input()
{
	int N;
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		ll input;
		std::cin >> input;
		mp[input] = input;
		vec.push_back(input);
	}
}

void Solve()
{
	input();
	int k = 0;
	for (auto i = mp.begin(); i != mp.end(); i++, k++) {
		(*i).second = k;
	}
	for (int i = 0; i < vec.size(); i++) {
		std::cout << mp[vec[i]] << " ";
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}