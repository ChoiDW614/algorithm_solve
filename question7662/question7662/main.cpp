#include <iostream>
#include <map>
#include <utility>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr);
typedef long long ll;

bool setVal(std::map<ll, ll>& mp, ll val)
{
	auto it = mp.find(val);
	if (it != mp.end()) {
		(*it).second++;
		return true;
	}
	return false;
}

void Solve()
{
	ll testcase, k;
	char command;	ll input;
	std::cin >> testcase;
	while (testcase--) {
		std::map<ll, ll> mp;
		std::cin >> k;
		while (k--) {
			std::cin >> command >> input;
			if (command == 'I') {
				if (!setVal(mp, input))
					mp.insert({ input, 1 });
			}
			else if (!mp.empty()) {
				if (input == 1) {
					std::map<ll, ll>::iterator endmp = --mp.end();
					if ((*endmp).second > 1) {
						(*endmp).second--;
					}
					else
						mp.erase(endmp);
				}
				else {
					std::map<ll, ll>::iterator beginmp = mp.begin();
					if ((*beginmp).second > 1) {
						(*beginmp).second--;
					}
					else
						mp.erase(beginmp);
				}
			}
		}
		if (!mp.empty())
			std::cout << (*--mp.end()).first << ' ' << (*mp.begin()).first << '\n';
		else
			std::cout << "EMPTY" << '\n';
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}