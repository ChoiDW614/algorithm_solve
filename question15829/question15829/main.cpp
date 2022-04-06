#include <iostream>
#include <string>
#include <cmath>

void solution()
{
	//a = 97, z = 122
	int cnt;
	std::cin >> cnt;
	std::string word;
	if (cnt <= 5 && cnt >= 1) {
		std::cin >> word;
		int originHash = 0;
		int i = 0;
		for (std::string::iterator iter = word.begin(); iter != word.end(); iter++, i++) {
			originHash += (*iter - 96) * pow(31, i);
		}
		std::cout << originHash;
	}
	else if (cnt >= 6 && cnt <= 50) {
		std::cin >> word;
		long long originHash = 0;
		int i = 0;
		long long mod = 1;
		for (std::string::iterator iter = word.begin(); iter != word.end(); iter++, i++) {
			originHash += (*iter - 96) * mod;
			mod = (mod * 31) % 1234567891;
		}
		originHash %= 1234567891;
		std::cout << originHash;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	
	solution();
	return 0;
}