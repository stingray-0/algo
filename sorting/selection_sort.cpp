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
        int min_idx = i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j] < a[min_idx])
            {
                min_idx = j;
            }
        }
        temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }

    for (const int& i : a)
    {
        std::cout << i << ' ';
    }
}