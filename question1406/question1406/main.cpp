#include <iostream>
#include <list>
#include <string>

std::list<char> lt;
std::list<char>::iterator iter;

void Command()
{
	char chartype;
	std::cin >> chartype;
	switch (chartype) {
	case'L':
		if (iter != lt.begin()) {
			iter--;
		}
		break;
	case'D':
		if (iter != lt.end()) {
			iter++;
		}
		break;
	case'B':
		if (iter != lt.begin()) {
			iter = lt.erase(--iter);
		}
		break;
	case'P':
		char tmp;
		std::cin >> tmp;
		lt.insert(iter, tmp);
		break;
	default:
		break;
	}
}

void Input()
{
	std::string st;
	std::cin >> st;
	int size = st.size();
	for (int i = 0; i < size; i++) {
		lt.push_front(st.back());
		st.pop_back();
	}

	iter = lt.end();
	int cnt;
	std::cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		Command();
	}

	for (auto it = lt.begin(); it != lt.end(); it++) {
		std::cout << *it;
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	Input();

	return 0;
}