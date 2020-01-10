#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;

int N, M;

vector<int> A;

int binarySearch(int low, int high, int target)
{
	//기저 사례: low가 high보다 크면 없는 수
	if (low > high)
		return 0;

	else
	{
		int mid = (low + high) / 2;
		//해당 지점에 target이 있다면 찾았으므로 1 반환
		if (A[mid] == target)
			return 1;
		//해당 지점에 있는 수가 target보다 크면 왼쪽 반 탐색
		else if (A[mid] > target)
			return binarySearch(low, mid - 1, target);
		//해당 지점에 있는 수가 target보다 작으면 오른쪽 반 탐색
		else
			return binarySearch(mid + 1, high, target);

	}
}


int main(void)

{
	ios_base::sync_with_stdio(0);

	cin.tie(0); //cin 속도 향상 위해
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		A.push_back(num);
	}

	sort(A.begin(), A.end()); //이분탐색은 정렬되어 있어야한다.



	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
		cout << binarySearch(0, N - 1, num) << "\n"; //endl 쓰면 시간 초과
	}

	return 0;

}