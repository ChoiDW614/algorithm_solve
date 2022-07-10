#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
using namespace std;

class Node{
public:
	Node* left = nullptr;
	Node* right = nullptr;
	int n = 0;
};

void setTree(Node* pnode, int k)
{
	if (pnode->n == 0) {
		pnode->n = k;
	}
	if (pnode->n < k) {
		if (pnode->right == nullptr) {
			Node* tmp = new Node;
			pnode->right = tmp;
		}
		setTree(pnode->right, k);
	}
	else if (pnode->n > k) {
		if (pnode->left == nullptr) {
			Node* tmp = new Node;
			pnode->left = tmp;
		}
		setTree(pnode->left, k);
	}
}

void postOrderTraversal(Node *pnode)
{
	if (pnode->left != nullptr)
		postOrderTraversal(pnode->left);
	if (pnode->right != nullptr)
		postOrderTraversal(pnode->right);
	cout << pnode->n << '\n';
}

void Solve()
{
	int input = 1;
	Node* node1 = new Node;
	if (cin >> input) {
		node1->n = input;
	}
	while (cin >> input) {
		setTree(node1, input);
	}

	if (node1->n == 0)
		return;

	postOrderTraversal(node1);
}

int main()
{
	FASTIO;
	Solve();
	return 0;
}