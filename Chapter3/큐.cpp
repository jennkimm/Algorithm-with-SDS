#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	queue<int> q;
	queue<int> ans;

	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;

		if (cmd.compare("push") == 0) {
			int num;
			cin >> num;
			q.push(num);
		}

		else if (cmd.compare("pop") == 0) { //출력
			if (!q.empty()) {
				ans.push(q.front());
				q.pop();
			}
			else {
				ans.push(-1);
			}
		}
		else if (cmd.compare("empty") == 0) { //출력
			if (q.empty() == true) {
				ans.push(1);
			}
			else {
				ans.push(0);
			}
		}

		else if (cmd.compare("size") == 0) { //출력
			ans.push(q.size());
		}

		else if (cmd.compare("front") == 0) { //출력
			if (q.empty() == false) {
				ans.push(q.front());
			}
			else {
				ans.push(-1);
			}
		}

		else if (cmd.compare("back") == 0) { //출력
			if (q.empty() == false) {
				ans.push(q.back());
			}
			else {
				ans.push(-1);
			}
		}
	}

	while (!ans.empty()) {
		cout << ans.front() << "\n";
		ans.pop();
	}

	return 0;

}