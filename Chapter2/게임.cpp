#include <iostream>
#include <algorithm>

using namespace std;

const long long MAX = 1000000000;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	long long X, Y;
	cin >> X >> Y;

	int Z = (Y * 100) / X;

	//절대 승률이 바뀔 수 없음
	if (Z >= 99) {
		cout << "-1" << "\n";
		return 0;
	}

	int low = 0;
	int high = MAX;
	int result = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		int tempZ = (100 * (Y + mid) / (X + mid));
		//이분탐색 결과 확률
		if (Z>=tempZ) {
			result = mid + 1;
			low = mid + 1;
		}
		
		else {
			high = mid - 1;
		}

	}

	cout << result << "\n";
	return 0;

}