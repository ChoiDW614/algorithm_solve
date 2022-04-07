#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);	cin.tie(NULL);

int R, C;

int check(vector<string> &b)
{
	int cntOdd = 0, cntEven = 0;;
	for (int i = 0; i < 8; i = i + 2) {
		for (int j = 0; j < 8; j = j + 2) {
			if (b[i][j] == 'B') {
				cntEven++;
			}
		}
	}
	for (int i = 1; i < 8; i = i + 2) {
		for (int j = 1; j < 8; j = j + 2) {
			if (b[i][j] == 'B') {
				cntEven++;
			}
		}
	}
	for (int i = 1; i < 8; i = i + 2) {
		for (int j = 0; j < 8; j = j + 2) {
			if (b[i][j] == 'B') {
				cntOdd++;
			}
		}
	}
	for (int i = 0; i < 8; i = i + 2) {
		for (int j = 1; j < 8; j = j + 2) {
			if (b[i][j] == 'B') {
				cntOdd++;
			}
		}
	}
	int move1, move2;
	move1 = cntOdd + (32 - cntEven);
	move2 = (32 - cntOdd) + cntEven;
	if (move1 >= move2)
		return move2;
	else
		return move1;
}

void Solve()
{
	cin >> R >> C;
	// vector<vector<char>> chessBoard(R, vector<char>(C, 0));

	vector<string> chessBoard(R);
	for (int i = 0; i < R; i++)	cin >>chessBoard[i];

	int MinCnt = 32;
	for (int i = 0; i < R - 7; i++) {
		for (int j = 0; j < C - 7; j++) {
			vector<string> chessBoard1(8);
			for (int k = 0; k < 8; k++) {
				chessBoard1[k] = chessBoard[i + k].substr(j, j + 8);
			}
			int tmp = check(chessBoard1);
			MinCnt = (MinCnt > tmp) ? tmp : MinCnt;
		}
	}
	cout << MinCnt;
	return;
}

int main()
{
	FAST_IO;
	Solve();
	return 0;
}