#include <iostream>

using namespace std;

class StackArray
{
public:
    int *stackArr;
    int topIndex{};

    explicit StackArray(int length)
    {
        stackArr = new int[length];
    }

    ~StackArray()
    {
        delete stackArr;
    }
};

void StackInit(StackArray * pStack)
{
    pStack->topIndex = -1;
}

int SIsEmpty(StackArray * pStack)
{
    if(pStack->topIndex == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void SPush(StackArray * pStack, int data)
{
    pStack->topIndex += 1;
    pStack->stackArr[pStack->topIndex] = data;

}

int SPop(StackArray * pStack)
{
    int rIdx;

    if(SIsEmpty(pStack)){
        cout << "Stack Memory Error!" << endl;
        return -1;
    }

    rIdx = pStack->topIndex;
    pStack->topIndex -= 1;

    return pStack->stackArr[rIdx];
}

void SDelete(StackArray * pStack)
{
    if(SIsEmpty(pStack)){
        cout << "Stack Memory Error!" << endl;;
    }

    pStack->topIndex -= 1;
}

int main()
{
    int len;
    cin >> len;

    StackArray stack(len);
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