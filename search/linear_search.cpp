#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;
    int arr[n];
    for (int& i : arr)
    {
        std::cin >> i;
    }

    std::sort(arr, arr + n);

    int search_num;
    std::cin >> search_num;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == search_num)
        {
            std::cout << "found " << search_num << " at " << i+1 <<'\n';
            return 0;
        }
    }

    std::cout << "number not found\n";
    return 0;
}