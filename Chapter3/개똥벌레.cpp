#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, h;
	cin >> n >> h;
	vector<int> d_bottom;
	vector<int> d_up;


	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if ((i % 2) == 0) { //짝수- 위부터 자람
			d_bottom.push_back(num);
		}
		else if (i == 0) {
			d_up.push_back(h-num);
		}
		else { //아래부터 자람
			d_up.push_back(h-num);
		}
	}

	sort(d_bottom.begin(), d_bottom.end()); //정렬
	sort(d_up.begin(), d_up.end()); //정렬

	int min_cnt = 200001;
	int gatsu = 0;

	for (int k = 1; k <= h; k++) {
		vector<int>::iterator bottom, up;
		int cnt = 0;
		int index1, index2;

		bottom = lower_bound(d_bottom.begin(), d_bottom.end(), k);//k 이상인 이터레이터 반환.
		index1 = bottom - d_bottom.begin();
		cnt = d_bottom.size() - index1;


		up = lower_bound(d_up.begin(), d_up.end(), k); //k를 초과하는 이터레이터 반환.

		index2 = up - d_up.begin();

		cnt = cnt + index2;

		if (cnt < min_cnt) {
			gatsu = 1;
			min_cnt = cnt;
		}

		else if (cnt == min_cnt) {
			gatsu++;
		}
	}

	printf("%d %d\n", min_cnt, gatsu);
}