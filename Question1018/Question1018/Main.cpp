#include <iostream>
#include <vector>

using namespace std;

int H, W;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W;
	vector<vector<char>> chessBoard(H, vector<char>(W, 0));

	return 0;
}