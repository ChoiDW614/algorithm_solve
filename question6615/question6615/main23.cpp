//#include <iostream>
//#include <map>
//
//int main()
//{
//	std::ios_base::sync_with_stdio(false);
//	std::cout.tie(NULL); std::cin.tie(NULL);
//
//	int A, B;
//
//	while (1) {
//		std::map<int, int> mp;
//		mp.clear();
//		std::cin >> A >> B;
//		if (A == 0 && B == 0)
//			return;
//		int originA = A, originB = B;
//		int cntA = 0, cntB = 0;
//
//		while (B != 1) {
//			mp[B] = cntB;
//
//			if (B % 2 == 0)
//				B = B / 2;
//			else
//				B = 3 * B + 1;
//			cntB++;
//
//			A = originA;
//			cntA = 0;
//			while (A != 1) {
//				if (mp.find(A) != mp.end()) {
//					std::cout << originA << " needs " << cntA << " steps, " << originB << " needs " << mp[A]
//						<< " steps, they meet at " << A << '\n';
//					goto outside;
//				}
//				else {
//					if (A % 2 == 0)
//						A = A / 2;
//					else
//						A = 3 * A + 1;
//					cntA++;
//				}
//			}
//		}
//	outside:;
//	}
//
//	return 0;
//}

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); std::cin.tie(NULL);

	int A, B;

	while (1) {
		cin >> A >> B;
		if (A == 0 && B == 0)
			return 0;

		vector<pair<int, int>> v;
		pair<int, int> p;
		int originA = A, originB = B;
		int cntA = 0, cntB = 0;

		while (B != 1) {
			p = make_pair(B, cntB);
			v.push_back(p);

			if (B % 2 == 0)
				B = B / 2;
			else
				B = 3 * B + 1;
			cntB++;
		}
		sort(v.begin(), v.end());

		while (A != 1) {
			if (binary_search(v.begin(), v.end(), A)) {
				cout << originA << " needs " << cntA << " steps, " << originB << " needs " << 1
					<< " steps, they meet at " << A << '\n';
				goto outside;
			}
			else {
				if (A % 2 == 0)
					A = A / 2;
				else
					A = 3 * A + 1;
				cntA++;
			}
		}
	outside:;
	}

	return 0;
}