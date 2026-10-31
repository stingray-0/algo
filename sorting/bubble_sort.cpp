#include <iostream>

int main()
{
    int n, temp;
    std::cin >> n;
    int a[n] = {0};

    for (int& i : a)
    {
        std::cin >> i;
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i; j < n-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for (const int& i : a)
    {
        std::cout << i << " ";
    }
}
