#include <iostream>
#include <vector>

using namespace std;

int binary_searchUpperBound(vector<int> &v, int s, int e, const int k)
{
    int m;
    while(s<e)
    {
        m = (s+e)/2;
        if(k >v[m])
            s=m+1;
        else
            e=m;
    }
    return e;
}

void binary_insertionSort(vector<int> & v)
{
    int size = v.size();
    for(int i=1; i<size; i++)
    {
        int key = v[i];
        int pos = binary_searchUpperBound(v,0,i,key);
        move(v.begin()+pos, v.begin()+1, v.begin()+pos+1);
        v[pos] = key;
    }
}

int main()
{
    int totalNumOfData;
    cin >> totalNumOfData;
    
    vector<int> v;
    
    int input;
    cin >> input;
    v[0] = input;
    
    for(int i =1; i< totalNumOfData; i++)
    {
        cin >> input;
        v[i] = input;
        binary_insertionSort(v); 
        
        cout << v[i/2] << endl; 
    }
    
    return 0;
}