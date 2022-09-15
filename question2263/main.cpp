#include <bits/stdc++.h>
#define FASTIO  ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
using namespace std;

class Node
{
public:
    int val;
    Node* Next;
    Node* Prev;
};

Node* makeNode(int val)
{
    Node* newNode = new Node;
    newNode->val = val;
    return newNode;
}

void connectNode(Node* A, int I, int P)
{
    Node* newNode = makeNode(P);
    if (I == P)
        A->Prev = newNode;
    else
        A->Next = newNode;
}

void Solve()
{
    int N, input;
    cin >> N;

    vector<int> InOrder, PostOrder;
    for (int i = 0; i < N; i++) {
        cin >> input;
        InOrder.push_back(input);
    }
    for (int i = 0; i < N; i++) {
        cin >> input;
        PostOrder.push_back(input);
    }

    

}

int main()
{
    FASTIO;
    Solve();
    return 0;
}