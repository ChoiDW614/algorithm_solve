/*
#include <cstdio>
#include <vector>

using namespace std;

int binary_searchUpperBound(vector<int> &v, int s, int e, const int k)
{
    int m;
    while (s < e)
    {
        m = (s + e) / 2;
        if (k > v[m])
            s = m + 1;
        else
            e = m;
    }
    return e;
}

void binary_insertionSort(vector<int> & v)
{
    int size = v.size();
    for (int i = 1; i < size; i++)
    {
        int key = v[i];
        int pos = binary_searchUpperBound(v, 0, i, key);
        move(v.begin() + pos, v.begin() + i, v.begin() + pos + 1);
        v[pos] = key;
    }
}

int main()
{
    int totalNumOfData;
    scanf("%d", &totalNumOfData);

    vector<int> v;

    int input;
    scanf("%d", &input);
    v.push_back(input);
    printf("%d \n", v[0]);

    for (int i = 1; i < totalNumOfData; i++)
    {
        scanf("%d", &input);
        v.push_back(input);
        binary_insertionSort(v);

        printf("%d \n", v[i / 2]);
    }
    return 0;
}
*/