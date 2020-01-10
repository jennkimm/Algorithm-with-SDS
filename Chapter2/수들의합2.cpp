#include <iostream>

using namespace std;

int main(void) {
	int N;
	cin >> N;

	int goal;
	cin >> goal;

	int *A = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int sum;
	int ans = 0;
	int index=0;

	for (int i = 0; i < N; i++) {
		sum = 0;
		index = i;
		while ((sum < goal)&&(index<N)) {
			sum = sum + A[index];
			index++;
		}

		if (sum == goal) {
			ans++;
		}

		else
			continue;
	}

	cout << ans<<"\n";

	return 0;
}