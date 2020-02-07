#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;
int main() {
	int heights[10];
	int sum = 0;
	bool find = false;

	for (int i = 1; i<10; i++) {
		cin >> heights[i];
		sum += heights[i];
	}

	for (int i = 1; i < 10; i++) {
		for (int j = i + 1; j < 10; j++) {
			if ((sum - heights[i] - heights[j]) == 100) {
				heights[i] = MAX;
				heights[j] = MAX;
				find = true;
				break;
			}
		}
		if (find)
			break;
	}
	sort(heights, heights + 10);
	for (int i = 1; i<8; i++) {
		if (heights[i] != MAX) {
			cout << heights[i] << endl;
		}
	}
	return 0;
}
