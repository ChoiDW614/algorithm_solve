#include <iostream>

int numofUnit;
int arr[500000];

void modify(int unit, int soldierNum)
{
	for (int i = unit - 1; i < numofUnit; i++) {
		arr[i] += soldierNum;
	}
}

void Bsearch(int serialNum)
{
	int first = 0;
	int last = numofUnit - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (serialNum <= arr[mid] && serialNum > arr[mid-1]) {
			std::cout << (mid + 1) << std::endl;
			break;
		}
		else
		{
			if (serialNum > arr[mid]) {
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
	}
}

void inputUnitInfo()
{
	int sizeofUnit;

	std::cin >> numofUnit;
	std::cin >> sizeofUnit;
	arr[0] = sizeofUnit;

	for (int i = 1; i < numofUnit; i++) {
		std::cin >> sizeofUnit;
		arr[i] = arr[i - 1] + sizeofUnit;
	}

	int repe, command, targetNumofUnit, modifiedSoldier, targetNum;
	std::cin >> repe;
	for (int j = 0; j < repe; j++) {
		std::cin >> command;
		if (command == 1) {
			std::cin >> targetNumofUnit >> modifiedSoldier;
			modify(targetNumofUnit, modifiedSoldier);
		}
		else {
			std::cin >> targetNum;
			Bsearch(targetNum);
		}
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);
	inputUnitInfo();

	return 0;
}