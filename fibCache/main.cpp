#include <iostream>

int fib(int n, int *f)
{
    if (n==1 || n==2)
        return 1;
    else if (f[n] > -1)
        return f[n];
    else{
        f[n] = fib(n-2, f) + fib(n-1, f);
        return f[n];
    }
}

int main()
{
    int input;
    std::cin >> input;
    int *f = new int[input];

    for(int i = 0; i < input; i++)
    {
        f[i] = -1;
    }

    std:: cout << "result: " <<fib(input, f) << std::endl;
    return 0;
}