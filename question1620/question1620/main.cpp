#include <iostream>
#include <string>
#include <map>
#include <vector>
#define FAST_IO	std::ios_base::sync_with_stdio(false);	std::cin.tie(NULL);	std::cout.tie(NULL);
#define str std::string

std::vector<str> vec;
std::map<str, int> mp;

void Solve()
{
	int N, M;
	std::cin >> N >> M;
	str pokemon;

	for(int i = 1; i <= N; i++) {
		std::cin >> pokemon;
		vec.push_back(pokemon);
		mp[pokemon] = i;
	}

	while (M--) {
		std::cin >> pokemon;
		if (mp.find(pokemon) != mp.end()) {
			std::cout << mp.find(pokemon)->second << '\n';
		}
		else {
			std::cout << vec.at(std::atoi(pokemon.c_str())-1) << '\n';
		}
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}