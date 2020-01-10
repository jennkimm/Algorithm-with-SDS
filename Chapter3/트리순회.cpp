#include <iostream>

using namespace std;

struct Node {
	char data;
	Node *left;
	Node *right;
};

Node *nodes; //노드포인터

			 //전위순회 (루트) (왼쪽 자식) (오른쪽 자식)
void preorder_traverse(Node *R) {
	printf("%c", R->data);
	if (R->left)
		preorder_traverse(R->left);
	if (R->right)
		preorder_traverse(R->right);

}

//중위순회 (왼쪽 자식) (루트) (오른쪽 자식)
void inorder_traverse(Node *R) {
	if (R->left)
		inorder_traverse(R->left);

	printf("%c", R->data);

	if (R->right)
		inorder_traverse(R->right);
}

//후위순회 (왼쪽 자식) (오른쪽 자식) (루트)
void postorder_traverse(Node *R) {
	if (R->left)
		postorder_traverse(R->left);
	if (R->right)
		postorder_traverse(R->right);

	printf("%c", R->data);
}

int main(void) {
	int N;
	cin >> N;
	char chr, nr, nl;
	int nmb;

	//동적할당
	nodes = (Node*)malloc(sizeof(Node)*N);

	for (int i = 0; i < N; i++) {
		cin >> chr >> nl >> nr;
		nmb = chr - 'A';

		nodes[nmb].data = chr;

		if (nl == '.') {
			nodes[nmb].left = NULL;
		}

		else {
			nodes[nmb].left = &nodes[nl - 'A'];
		}

		if (nr == '.') {
			nodes[nmb].right = NULL;
		}

		else {
			nodes[nmb].right = &nodes[nr - 'A'];
		}
	}

	preorder_traverse(&nodes[0]);
	printf("\n");
	inorder_traverse(&nodes[0]);
	printf("\n");
	postorder_traverse(&nodes[0]);
	printf("\n");

	free(nodes);
}