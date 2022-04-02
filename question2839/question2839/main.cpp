#include <iostream>
using namespace std;

void Solution()
{
	int sugar, bag = 0;
	cin >> sugar;

	while (sugar >= 5) {
		sugar -= 5;
		bag += 1;
	}

	switch (sugar) {
		case 0:
			cout << bag;
			return;
		case 1:
			if (bag >= 1) {
				bag += 1;
				cout << bag;
			}
			else {
				cout << -1;
			}
			return;
		case 2:
			if (bag >= 2) {
				bag += 2;
				cout << bag;
			}
			else {
				cout << -1;
			}
			return;
		case 3:
			bag += 1;
			cout << bag;
			return;
		case 4:
			if (bag >= 1) {
				bag += 2;
				cout << bag;
			}
			else {
				cout << -1;
			}
			return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	Solution();
	return 0;
}