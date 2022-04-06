#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

ll cal(ll A);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll A, B, numB, startA, startB;
	while (true) {
		vector<ll> seq;
		numB = 0;
		cin >> A >> B;
		if (A == 0 && B == 0)
			break;
		startA = A;
		startB = B;

		while (A != 1) {
			seq.push_back(A);
			A = cal(A);
		}
		seq.push_back(1);
		bool escape = false;
		while (true) {
			for (int i = 0; i < seq.size(); i++) {
				if (seq[i] == B) {
					cout << startA << " needs " << i << " steps, " << startB << " needs " << numB << " steps, they meet at " << B << '\n';
					escape = true;
					break;
				}
			}
			if (escape)
				break;
			B = cal(B);
			numB++;
		}
	}
	return 0;
}

ll cal(ll A) {
	if (A % 2 == 1)
		return 3 * A + 1;
	else
		return A / 2;
}