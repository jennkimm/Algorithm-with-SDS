#include <cstdio>
#include <iostream>
#include <math.h>
#include <vector>

#define swap(a,b) {int t = a; a = b; b = t;}

using namespace std;

typedef long long ll;

ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;

	return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff)
{
	if (!(start <= index && index <= end))
		return;

	tree[node] += diff;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}

}

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	int n, q;
	scanf("%d %d", &n, &q);

	int h = (int)ceil(log2(n));
	int tree_size = (1<<(h + 1));

	vector<ll> arr(n);
	vector<ll> tree(tree_size);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i - 1]);
		update(tree, 1, 0, n - 1, i - 1, arr[i - 1]);
	}

	init(arr, tree, 1, 0, n - 1);

	while (q--)
	{
		int x, y, a, b;
		scanf("%d %d", &x, &y);

		if (x > y)
			swap(x, y);

		printf("%lld\n", sum(tree, 1, 0, n - 1, x-1, y-1));
		scanf("%d %d", &a, &b);

		ll diff = b - arr[a - 1];
		arr[a - 1] = b;
		update(tree, 1, 0, n - 1, a - 1, diff);

	}

	return 0;
}