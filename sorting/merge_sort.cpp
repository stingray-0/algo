#include <iostream>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int left_arr[n1];
    int right_arr[n2];
    
    for (int i = 0; i < n1; i++)    // left arr
    {   
        left_arr[i] = arr[left+ i];
    }
    for (int i = 0; i < n2; i++)    // right arr
    {   
        right_arr[i] = arr[mid+ 1 + i];
    }

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2)        // merging
    {
        if (left_arr[i] < right_arr[j])
        {
            arr[k++] = left_arr[i++];
        }
        else
        {
            arr[k++] = right_arr[j++];
        }
    }

    while (i < n1)                 
    {
        arr[k++] = left_arr[i++];
    }
    while (j < n2)
    {
        arr[k++] = right_arr[j++];
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) /2;
        merge_sort(arr, left, mid);     // cut
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);   //merge
    }
}

int main()
{
    int test[10];
    for (int& i : test)
    {
        std::cin >> i;
    }

    merge_sort(test, 0, 9);

    for (const int&i : test)
    {
        std::cout << i << ' ';
    }
}