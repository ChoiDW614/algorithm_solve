#include <iostream>
#include <string.h>
#define FAST_IO std::ios_base::sync_with_stdio(false);	std::cin.tie(nullptr)
typedef char int_8;
typedef short int_16;

void add(int_8 *st ,int_16 x) {
	st[x] = 49;
}

void remove(int_8* st, int_16 x) {
	st[x] = 0;
}

void check(int_8* st, int_16 x) {
	if (st[x] == 49)
		std::cout << 1 << '\n';
	else
		std::cout << 0 << '\n';
}

void toggle(int_8* st, int_16 x) {
	if (st[x] == 49)
		st[x] = 0;
	else
		st[x] = 49;
}

void all(int_8* st) {
	for (int_16 i = 1; i <= 20; i++) st[i] = 49;
}

void empty(int_8* st) {
	memset(st, 0, 21);
}

void Solve()
{
	int_8* stack = new int_8[21];
	empty(stack);
	
	int testcase;	std::string str;	int_16 target;
	std::cin >> testcase;
	while (testcase--) {
		std::cin >> str;
		if (str == "add") {
			std::cin >> target;	add(stack, target);
		}
		else if (str == "remove") {
			std::cin >> target;	remove(stack, target);
		}
		else if (str == "check") {
			std::cin >> target;	check(stack, target);
		}
		else if (str == "toggle") {
			std::cin >> target;	toggle(stack, target);
		}
		else if (str == "all")
			all(stack);
		else if (str == "empty")
			empty(stack);
	}
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}