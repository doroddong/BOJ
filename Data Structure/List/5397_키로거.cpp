#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
	int T;
	cin >> T;

	while (T--) {
		string L;
		cin >> L;
		list<char> ans;
		list<char>::iterator ans_iter = ans.begin();
		int L_len = L.size();
		int L_idx = 0;

		while (L_idx < L_len) {
			switch (L[L_idx])
			{
			case '<':
				if (ans_iter != ans.begin()) ans_iter--;
				break;
			case '>':
				if (ans_iter != ans.end()) ans_iter++;
				break;
			case '-':
				if (ans_iter != ans.begin()) ans.erase((--ans_iter)++);
				break;
			default:
				ans.insert(ans_iter, L[L_idx]);
				break;
			}
			L_idx++;
		}
		for (auto x : ans) cout << x;
		cout << "\n";
	}
	return 0;
}
