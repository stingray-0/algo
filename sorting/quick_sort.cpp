#include <iostream>

int partition(int arr[], int left, int right)
{
    int i = left;
    int j = right - 1;
    int pivot = arr[right];

    while (i < j)
    {
        while (i < right && arr[i] < pivot)
        {
            i++;
        }
        while (j > left && arr[j] >= pivot)
        {
            j--;
        } 
        if (i < j)
        {
            std::swap(arr[i], arr[j]);
        }
    }

    if (arr[i] > pivot)
    {
        std::swap(arr[i], arr[right]);
    }

    return i;
}

void quick_sort(int arr[], int left, int right)
{
    if (right > left)
    {
        int partiiton_pos = partition(arr,  left, right);
        quick_sort(arr, left, partiiton_pos - 1);
        quick_sort(arr, partiiton_pos + 1, right);
    }
}

int main()
{
    int test[10];
    for (int& i : test)
    {
        std::cin >> i;
    }

    quick_sort(test, 0, 9);

    for (const int&i : test)
    {
        std::cout << i << ' ';
    }
}