#include<iostream>

class BTree{
public:
    int data;
    BTree * left;
    BTree * right;
};

BTree * MakeBTree(){
    BTree * nd = new BTree;
    nd->left = nullptr;
    nd->right = nullptr;
    return nd;
}

int getData(BTree * bt){
    return bt->data;
}

void setData(BTree * bt, int data){
    bt->data = data;
}

void MakeLeftSubTree(BTree * main, BTree * sub){
    if(main->left != nullptr)
        delete main->left;
    main->left = sub;
}

void MakeRightSubTree(BTree * main, BTree * sub){
    if(main->right != nullptr)
        delete main->right;
    main->right = sub;
}

BTree * GetLeftSubTree(BTree * bt){
    return bt->left;
}

BTree * GetRightSubTree(BTree * bt){
    return bt->right;
}

void BSTMakeAndInit(BTree ** pRoot){
    *pRoot = nullptr;
}

int BSTGetNodeData(BTree * bst){
    return getData(bst);
}

void BSTInsert(BTree ** pRoot, int data)
{
    BTree * pNode = nullptr;
    BTree * cNode = *pRoot;
    BTree * nNode = nullptr;

    while(cNode != nullptr)
    {
        if(data == getData(cNode))
            return;

        pNode = cNode;

        if(getData(cNode) > data)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    nNode = MakeBTree();
    setData(nNode, data);

    if(pNode != nullptr)
    {
        if(data < getData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);
    }
    else{
        *pRoot = nNode;
    }
}

void Rebalance(BTree * bst)
{

}

int main()
{
    BTree * bstRoot;
    BSTMakeAndInit(&bstRoot);

    int sumOfN;
    std::cin >> sumOfN;
    int inputNum;
    for(int i = 0; i < sumOfN; i++)
    {
        std::cin >> inputNum;
        BSTInsert(&bstRoot, inputNum);

        std::cout << bstRoot->data << std::endl;
    }

    return 0;
}