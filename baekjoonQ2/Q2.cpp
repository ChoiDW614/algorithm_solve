#include <iostream>

using namespace std;

class StackArray
{
public:
    int stackArr[100];
    int topIndex;
};

void StackInit(StackArray * pstack)
{
    pstack->topIndex = -1;
}

int SIsEmpty(StackArray * pstack)
{
    if(pstack->topIndex == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void SPush(StackArray * pstack, int data)
{
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

int SPop(StackArray * pstack)
{
    int rIdx;
    
    if(SIsEmpty(pstack)){
        cout << "Stack Memory Error!" << endl;
        return -1;
    }
    
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    
    return pstack->stackArr[rIdx];
}

void SDelete(StackArray * pstack)
{
    if(SIsEmpty(pstack)){
        cout << "Stack Memory Error!" << endl;;
    }
    
    pstack->topIndex -= 1;
}

int main()
{
    int len;
    cin >> len;

    StackArray stack;
    StackInit(&stack);

    int k;
    for(int i =0; i<len; i++)
    {
        cin>>k;
    
        if(k == 0)
        {
            SDelete(&stack);
        }
        else
        {
            SPush(&stack, k);
        }
    }
    
    int total = 0;
    while(!SIsEmpty(&stack))
    {
        total += SPop(&stack);
    }
    cout << total << endl;

    return 0;
}