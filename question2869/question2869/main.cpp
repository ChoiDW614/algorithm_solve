#include <iostream>
using namespace std;

typedef long long ll;

void Solution()
{
	ll V, up, down, cur, day = 0;;
	cin >> up >> down >> V;
	
	day += (V - up) / (up - down);
	cur = (up - down) * day;
	while (true) {
		if (cur + up >= V) {
			cout << day + 1;
			return;
		}
		else {
			cur += up;
			day++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	Solution();
	return 0;
}