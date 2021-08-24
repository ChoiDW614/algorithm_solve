/*
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

int GetHeight(BTree * bst)
{
    int leftH;
    int rightH;
    if(bst == nullptr)
        return 0;

    leftH = GetHeight(GetLeftSubTree(bst));
    rightH = GetHeight(GetRightSubTree(bst));

    if(leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
}

int GetHeightDiff(BTree * bst)
{
    int lsh;
    int rsh;
    if(bst == nullptr)
        return 0;

    lsh = GetHeight(GetLeftSubTree(bst));
    rsh = GetHeight(GetRightSubTree(bst));
    return lsh - rsh;
}

void ChangeLeftSubTree(BTree * main, BTree * sub)
{
    main->left = sub;
}

void ChangeRightSubTree(BTree * main, BTree * sub)
{
    main->right = sub;
}

BTree * RotateLL(BTree * bst)
{
    BTree * pNode;      // parent node
    BTree * cNode;      // child node

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    // Two functions responsible for LL rotation
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);

    return cNode;
}

BTree * RotateRR(BTree * bst)
{
    BTree * pNode;      // parent node
    BTree * cNode;      // child node

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    // Two functions responsible for RR rotation
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    return cNode;
}

BTree * RotateLR(BTree * bst)
{
    BTree * pNode;
    BTree * cNode;

    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    ChangeLeftSubTree(pNode, RotateRR(cNode));;
    return RotateLL(pNode);
}

BTree * RotateRL(BTree * bst)
{
    BTree * pNode;
    BTree * cNode;

    pNode = bst;
    cNode = GetRightSubTree(pNode);

    ChangeRightSubTree(pNode, RotateLL(cNode));;
    return RotateRR(pNode);
}


BTree * Rebalance(BTree ** pRoot)
{
    int hDiff = GetHeightDiff(*pRoot);
    if(hDiff > 1)
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot))>0)
            *pRoot = RotateLL(*pRoot);
        else
            *pRoot = RotateLR(*pRoot);
    }
    if(hDiff < -1)
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }
    return *pRoot;
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
    *pRoot = Rebalance(pRoot);
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

        std::cout << getData(bstRoot) << std::endl;
    }

    return 0;
}
*/