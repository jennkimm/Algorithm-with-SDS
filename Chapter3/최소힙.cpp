#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

#define MAX_N 100002

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap; //최대 힙

int arr[MAX_N];

int main() {
	int n, x;
	scanf("%d", &n);

	queue<int> ans;

	while (n--) {
		scanf("%d", &x);
		if (x>0) {
			//x 추가
			min_heap.push(x);
		}

		//배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거
		else {
			if (!min_heap.empty()) {
				ans.push(min_heap.top());
				min_heap.pop();
			}
			else {
				ans.push(0);
			}
		}
	}

	while (!ans.empty()) {
		printf( "%d\n",ans.front());
		ans.pop();
	}

	return 0;
}