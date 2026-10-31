#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int p1 = m - 1;
    int p2 = n - 1;
    int p = m + n -1;
    while (p1 >= 0 && p2 >= 0)
    {
        if (nums1[p1] > nums2[p2])
        {
            nums1[p--] = nums1[p1--];
        }
        else
        {
            nums1[p--] = nums2[p2--];
        }
    }
    while (p2 >= 0)
    {
        nums1[p--] = nums2[p2--];
    }
}

int main()
{
    int n1, n2, m, n; 
    std::cin >> n1 >> n2;
    std::vector<int> nums1(n1), nums2(n2);

    for (int& i : nums1)
    {
        std::cin >> i;
    }
    for(int& i : nums2)
    {
        std::cin >> i;
    }
    std::cin >> m >> n;

    merge(nums1, m, nums2, n);
    
    for (const int& i : nums1)
    {
        std::cout << i << ' ';
    }
    
    return 0;
}

//leetcode solution

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int p1 = m - 1;
//         int p2 = n - 1;
//         int p = m + n - 1;        
//         while (p1 >= 0 && p2 >= 0)
//         {
//             if (nums1[p1] > nums2[p2])
//             {
//                 nums1[p--] = nums1[p1--];
//             }
//             else
//             {
//                 nums1[p--] = nums2[p2--];
//             }
//         }
//         while (p2 >= 0)
//         {
//             nums1[p--] = nums2[p2--];
//         }
//     }
// };