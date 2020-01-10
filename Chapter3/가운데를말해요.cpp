#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

#define MAX_N 100002


using namespace std;

priority_queue<int, vector<int>, less<int>> max_heap; //최대 힙
priority_queue<int, vector<int>, greater<int>> min_heap; //최소 힙

int arr[MAX_N];

//중간값 구하기
//1. 최대 힙의 크기는 최소 힙의 크기와 같거나, 하나 더 크다
//2. 최대 힙의 최대원소는 최소 힙의 최소원소보다 작거나 같다.
//   알고리즘에 맞지 않다면 최대 힙, 최소 힙의 가장 위의 값을 swap

int main() {
	int n;
	scanf("%d", &n);

	int val;

	queue<int> ans;

	while (n--) {
		scanf("%d", &val);

		if (max_heap.empty()) {
			max_heap.push(val);
		}

		else if (max_heap.size() == min_heap.size()) {
			max_heap.push(val);
		}

		else
			min_heap.push(val);

		if ( !max_heap.empty()&& !min_heap.empty() && !(max_heap.top() <= min_heap.top()) ) {
			int a = max_heap.top();
			int b = min_heap.top();

			max_heap.pop();
			min_heap.pop();

			max_heap.push(b);
			min_heap.push(a);
		}

		ans.push(max_heap.top());
	}

	while (!ans.empty()) {
		cout << ans.front() << "\n";
		ans.pop();
	}

	
	return 0;

}