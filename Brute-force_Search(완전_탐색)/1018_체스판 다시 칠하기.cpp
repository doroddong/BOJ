#include <iostream>
#include <string>
#include <algorithm>

#define MAX 50
#define INF 2500
using namespace std;
int m, n;

string board[MAX];

//(0, 0)이 W인 체스보드

string whiteFirst[8] = {

	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" }
};

//(0, 0)이 B인 체스보드

string blackFirst[8] = {

	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" }
};

int whiteFirstCheck(int x, int y) {
	int count = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++)
			if (board[i][j] != whiteFirst[i - x][j - y])
				count++;
	}
	return count;
}

int blackFirstCheck(int x, int y) {
	int count = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++)
			if (board[i][j] != blackFirst[i - x][j - y])
				count++;
	}
	return count;
}



int main() {

	cin >> m >> n;

	for (int i = 0; i < m; i++)
		cin >> board[i];

	int result = INF;

	for (int i = 0; i + 7 < m; i++)
		for (int j = 0; j + 7 < n; j++)
			result = min(result, min(whiteFirstCheck(i, j), blackFirstCheck(i, j)));

	cout << result << "\n";
	return 0;
}