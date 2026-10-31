#include <iostream>
#include <algorithm>

void dutch_flag (int arr[], int arr_l)
{
    int low = 0, mid = 0, high = arr_l - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            std::swap(arr[mid++], arr[low++]);
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            std::swap(arr[mid], arr[high--]);
        }
    } 
}

void counting_sort(int arr[],int arr_l, int colors)
{
    int count[colors] = {0};
    for (int i = 0; i < arr_l; i++)
    {
        count[arr[i]]++;
    }

    int index = 0;
    for (int color = 0; color < colors; color++)
    {
        while (count[color]--)
        {
            arr[index++] = color;
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    int colors[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> colors[i];
    }

    // dutch_flag(colors, n);
    counting_sort(colors, n, 3);
    
    for (int i = 0; i < n; i++)
    {
        std::cout << colors[i] << ' ';
    }
}


//leetcode solutions

//merge sort (by me)
// class Solution {
// public:
//     void merge(vector<int>& v, int left, int mid, int right)
//     {
//         int n1 = mid - left + 1;
//         int n2 = right - mid;
//         vector<int> l(n1), r(n2);
//         for (int i = 0; i < n1; i++)
//         {
//             l[i] = v[left + i];
//         }
//         for (int i = 0; i < n2; i++)
//         {
//             r[i] = v[mid + 1 + i];
//         }
//         int i = 0, j = 0, k = left;
//         while (i < n1 && j < n2)
//         {
//             if (l[i] < r[j])
//             {
//                 v[k++] = l[i++];
//             }
//             else
//             {
//                 v[k++] = r[j++];
//             }
//         }

//         while (i < n1)
//         {
//             v[k++] = l[i++];
//         }
//         while (j < n2)
//         {
//             v[k++] = r[j++];
//         }
//     }
//     void merge_sort(vector<int>& v, int left, int right)
//     {
//         if (left < right)
//         {
//             int mid = (left+right)/2;
//             merge_sort(v, left, mid);
//             merge_sort(v, mid+1, right);
//             merge(v, left, mid, right);
//         }
//     }

//     void sortColors(vector<int>& nums) {
//         merge_sort(nums, 0, nums.size()-1);
//     }
// };

// Dutch national flag algorithm
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int low = 0, mid = 0, high = nums.size() - 1;
//         while (mid <= high)
//         {
//             if (nums[mid] == 0)
//             {
//                 swap(nums[mid++], nums[low++]);
//             }
//             else if(nums[mid] == 1)
//             {
//                 mid++;
//             }
//             else
//             {
//                 swap(nums[mid], nums[high--]);
//             }
//         }
//     }
// };
