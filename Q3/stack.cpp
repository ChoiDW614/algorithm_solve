/*
#include<iostream>
#include<vector>

int main() {
    int numOfInteger;
    std::cin >> numOfInteger;

    std::vector<int> stack;
    stack.resize(numOfInteger, 0);

    for (int i = 0; i < numOfInteger; i++)
    {
        // input the data;
        int suBinNum;
        while (true)
        {
            std::cin >> suBinNum;
            if (suBinNum >= -10000 && suBinNum <= 10000)
                break;
        }

        // input and sort the data in stack;
        if (i == 0)
        {
            stack[0] = suBinNum;
        }
        else
        {
            for (int j = 0; j <= i; j++)
            {
                if (stack[j] >= suBinNum && j != i)
                {
                    for (int k = i - 1; k >= j; k--)
                    {
                        stack[k + 1] = stack[k];
                    }
                    stack[j] = suBinNum;
                    break;
                }
                if (stack[j] == 0)
                {
                    stack[i] = suBinNum;
                    break;
                }
            }
        }

        // return the target data
        std::cout << stack[i/2] << std::endl;
    }

    return 0;
}
*/