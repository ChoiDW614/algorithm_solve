#include <iostream>
#include <deque>

void solution()
{
	int N, K;
	std::cin >> N >> K;
	std::deque<int> deq, deq2;

	for (int i = 0; i < N; i++) {
		deq.push_back(i + 1);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 1; j < K; j++) {
			deq.push_back(deq.front());
			deq.pop_front();
		}
		deq2.push_back(deq.front());
		deq.pop_front();
	}

	std::cout << '<';
	for (int i = 0; i < N - 1; i++) {
		std::cout << deq2.front() << ", ";
		deq2.pop_front();
	}
	std::cout << deq2.front() << '>';
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	solution();
	return 0;
}