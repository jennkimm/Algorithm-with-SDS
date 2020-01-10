#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	int size;

	stack<int> s;
	queue<int> ans;

	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;

		if(cmd.compare("push")==0){
			int num;
			cin >> num;
			s.push(num);

		}
		else if (cmd.compare("pop") == 0) { //출력
			if (!s.empty()) {
				ans.push(s.top());
				s.pop();
			}
			else {
				ans.push(-1);
			}
		}
		else if (cmd.compare("empty") == 0) { //출력
			if (s.empty()==true) {
				ans.push(1);
			}
			else {
				ans.push(0);
			}
		}
		else if (cmd.compare("size") == 0) { //출력
			ans.push(s.size());
		}
		else if (cmd.compare("top") == 0) { //출력
			if (s.empty() == false) {
				ans.push(s.top());
			}
			else {
				ans.push(-1);
			}
		}
	}

	while(!ans.empty()){
		cout << ans.front() << "\n";
		ans.pop();
	}

	return 0;
}