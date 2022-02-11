#include <iostream>
#include <iomanip>

int main() {
	double A, B;
	std::cin >> A >> B;
	std::cout << std::setprecision(16);
	std::cout << A / B;
}