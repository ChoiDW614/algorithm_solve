#include <iostream>
#include <vector>

class TreeNode {
public:
	int nodeOrder;
	int parentNodeOrder;
	std::vector<TreeNode*> childrenNode;
};

int count = 0;
std::vector<TreeNode*> vnode;

void MakeSubTree(TreeNode* main, TreeNode* sub) {
	main->childrenNode.push_back(sub);
	return;
}

void countTraverse(TreeNode* bt) {
	if (bt->childrenNode.empty()) {
		count += 1;
		return;
	}

	for (auto iter = bt->childrenNode.begin(); iter < bt->childrenNode.end(); iter++) {
		countTraverse(*iter);
	}
}

void DeleteNode(TreeNode* bt, int idx)
{
	if (bt->parentNodeOrder == -1 && bt->nodeOrder == idx) {
		std::cout << 0;
		count = -1;
		return;
	}
	for (auto iter = bt->childrenNode.begin(); iter < bt->childrenNode.end(); iter++) {
		if ((*iter)->nodeOrder == idx) {
			bt->childrenNode.erase(iter);
			return;
		}
		DeleteNode(*iter, idx);
	}
}

void solution() {
	int numOfNode;
	std::cin >> numOfNode;

	int nodeType;
	TreeNode* Tn = new TreeNode;
	for (int idx = 0; idx < numOfNode; idx++) {
		std::cin >> nodeType;
		TreeNode* Ctn = new TreeNode;
		Ctn->nodeOrder = idx;
		Ctn->parentNodeOrder = nodeType;
		if (nodeType == -1) {
			delete Tn;
			Tn = Ctn;
		}
		vnode.push_back(Ctn);
	}

	for (auto iter = vnode.begin(); iter < vnode.end(); iter++) {
		for (auto iter2 = vnode.begin(); iter2 < vnode.end(); iter2++) {
			if ((*iter)->parentNodeOrder == (*iter2)->nodeOrder) {
				MakeSubTree(*iter2, *iter);
			}
		}
	}

	int delNode;
	std::cin >> delNode;
	DeleteNode(Tn, delNode);
	
	if (count != -1) {
		countTraverse(Tn);
		std::cout << count;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	solution();
	return 0;
}