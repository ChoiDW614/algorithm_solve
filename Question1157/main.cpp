#include <iostream>
#include <string>

void checkup(std::string word)
{
	int alpha[26];
	for (int i = 0; i < 26; i++) {
		alpha[i] = 0;
	}

	for (int i = 0; i < word.size(); i++) {
		switch (word[i])
		{
		case 'a':
		case 'A':
			alpha[0] += 1;
			break;
		case 'b':
		case 'B':
			alpha[1] += 1;
			break;
		case 'c':
		case 'C':
			alpha[2] += 1;
			break;
		case 'd':
		case 'D':
			alpha[3] += 1;
			break;
		case 'e':
		case 'E':
			alpha[4] += 1;
			break;
		case 'f':
		case 'F':
			alpha[5] += 1;
			break;
		case 'g':
		case 'G':
			alpha[6] += 1;
			break;
		case 'h':
		case 'H':
			alpha[7] += 1;
			break;
		case 'i':
		case 'I':
			alpha[8] += 1;
			break;
		case 'j':
		case 'J':
			alpha[9] += 1;
			break;
		case 'k':
		case 'K':
			alpha[10] += 1;
			break;
		case 'l':
		case 'L':
			alpha[11] += 1;
			break;
		case 'm':
		case 'M':
			alpha[12] += 1;
			break;
		case 'n':
		case 'N':
			alpha[13] += 1;
			break;
		case 'o':
		case 'O':
			alpha[14] += 1;
			break;
		case 'p':
		case 'P':
			alpha[15] += 1;
			break;
		case 'q':
		case 'Q':
			alpha[16] += 1;
			break;
		case 'r':
		case 'R':
			alpha[17] += 1;
			break;
		case 's':
		case 'S':
			alpha[18] += 1;
			break;
		case 't':
		case 'T':
			alpha[19] += 1;
			break;
		case 'u':
		case 'U':
			alpha[20] += 1;
			break;
		case 'v':
		case 'V':
			alpha[21] += 1;
			break;
		case 'w':
		case 'W':
			alpha[22] += 1;
			break;
		case 'x':
		case 'X':
			alpha[23] += 1;
			break;
		case 'y':
		case 'Y':
			alpha[24] += 1;
			break;
		case 'z':
		case 'Z':
			alpha[25] += 1;
			break;
		default:
			break;
		}
	}

	int firstNum = 0, secondNum = 0;
	for (int i = 0; i < 26; i++) {
		if (firstNum <= alpha[i]) {
			secondNum = firstNum;
			firstNum = alpha[i];
		}
	}

	if (firstNum == secondNum) {
		std::cout << "?";
	}
	else {
		for (int i = 0; i < 26; i++) {
			if (firstNum == alpha[i]) {
				std::cout << (char)(i + 65);
			}
		}
	}
}

int main()
{
	std::string word;
	std::cin >> word;

	checkup(word);

	return 0;
}