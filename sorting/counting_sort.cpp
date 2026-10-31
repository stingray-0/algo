#include <iostream>

int* counting_sort(int arr[],int arr_l)
{
    int M = 0;
    for (int i = 0; i < arr_l; i++)
    {
        M = std::max(M, arr[i]);
    }

    int count_arr[M+1] = {0};
    for (int i = 0; i < arr_l; i++)
    {
        count_arr[arr[i]]++;
    }
    
    //sum prefix , makes the output part easier
    for (int i = 0; i < M; i++)
    {
        count_arr[i+1] += count_arr[i]; 
    }

    int sorted_arr[arr_l];

    for (int i = arr_l-1; i >= 0; i--)
    {
        sorted_arr[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }
    return sorted_arr;
}

int main()
{
    int n;
    std::cin >> n;
    int messy_arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> messy_arr[i];
    }

    int* good_arr = counting_sort(messy_arr, n);

    for (int i = 0; i < n; i++)
    {
        std::cout << good_arr[i];
    }

    return 0;
}