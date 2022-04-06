#include <iostream>
#include <queue>

class Beer
{
public:
	int preference;
	int ABV;
	Beer(int a, int b) : preference(a), ABV(b) {}
};

struct cmp {
	bool operator()(Beer b1, Beer b2) {
		if (b1.ABV >= b2.ABV) {
			if (b1.ABV == b2.ABV) {
				if (b1.preference < b2.preference)
					return true;
				else
					return false;
			}
			return true;
		}
		else
			return false;
	}
};

struct cmp2 {
	bool operator()(Beer b1, Beer b2) {
		if (b1.preference >= b2.preference) {
			if (b1.preference == b2.preference) {
				if (b1.ABV < b2.ABV)
					return true;
				else
					return false;
			}
			return true;
		}
		else
			return false;
	}
};

void solution()
{
	int Day, maxPreference, typeOfBeer;
	std::cin >> Day >> maxPreference >> typeOfBeer;

	std::priority_queue<Beer, std::vector<Beer>, cmp> BeerQue;
	std::priority_queue<Beer, std::vector<Beer>, cmp2> pq;

	while (typeOfBeer) {
		int prefer, abv;
		std::cin >> prefer >> abv;
		Beer a = { prefer, abv };
		BeerQue.push(a);
		typeOfBeer--;
	}

	int nowPrefer = 0, maxABV = 0;
	while (1) {
		pq.push(BeerQue.top());
		nowPrefer += BeerQue.top().preference;
		if (maxABV < BeerQue.top().ABV) {
			maxABV = BeerQue.top().ABV;
		}
		BeerQue.pop();

		if (pq.size() > Day)
		{
			nowPrefer -= pq.top().preference;
			pq.pop();
		}

		if (pq.size() == Day && nowPrefer >= maxPreference)
		{
			std::cout << maxABV;
			return;
		}

		if (BeerQue.empty()) {
			break;
		}
	}
	std::cout << "-1";
	return;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	solution();
	return 0;
}