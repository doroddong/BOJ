#include <iostream>
#include <queue>

using namespace std;

int main() {

	int N, K;
	queue<int> q;
	
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		q.push(i);

	cout << "<";
	
	while (q.size()) {
		if (q.size() == 1) {
			cout << q.front()<< ">";
			q.pop();
			break;
		}
		else {
			for (int i = 1; i < K; i++) {
				q.push(q.front());
				q.pop();
			}
			cout << q.front() << ", ";
			q.pop();
		}
	}
	cout << "\n";
	return 0;
}
