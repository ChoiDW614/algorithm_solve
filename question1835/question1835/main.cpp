#include <iostream>
#include <deque>

void solution()
{
	std::deque<int> dq;
	int num;
	std::cin >> num;
	int i, j;
	
	for (i = num; i > 0; i--) {
		dq.push_front(i);
		for (j = 0; j < i; j++) {
			dq.push_front(dq.back());
			dq.pop_back();
		}
	}
	for (int k = 0; k < dq.size(); k++) {
		std::cout << dq[k] << " ";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	solution();
	return 0;
}