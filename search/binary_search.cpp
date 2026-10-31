#include <iostream>
#include <algorithm>


// int binary_search(int arr[], int head, int end, int num) // recursive one
// {
//     if (head <= end)
//     {
//         int mid = (head +end) / 2;
//         if (arr[mid] == num)
//         {
//             return mid;
//         }
        
//         if (arr[mid] > num)
//         {
//             return binary_search(arr, head, mid-1, num);
//         }
//         else
//         {
//             return binary_search(arr, mid+1, end, num);
//         }
//     }
//     return -1;
// }

int binary_search(int arr[], int head, int end, int num) // not recursive one
{
    while (head <= end)
    {
        int mid = (head +end) / 2;
        if (arr[mid] == num)
        {
            return mid;
        }
        
        if (arr[mid] > num)
        {
            end = mid - 1;
        }
        else
        {
            head = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    int test[n];
    for (int& i : test)
    {
        std::cin >> i;
    }

    std::sort(test, test + n);

    int search_num;
    std::cin >> search_num;

    int result = binary_search(test, 0, n-1 , search_num);

    if (result == -1)
    {
        std::cout << "Number not found\n";
    }
    else
    {
        std::cout << "Found number at " << "index " << result << '\n';
    }

    return 0;
}