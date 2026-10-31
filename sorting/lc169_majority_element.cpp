#include <iostream>
#include <algorithm>
#include <map>

int sorting_solution(int arr[], int n)  //uses sort
{
    std::sort(arr, arr+n);
    int half = n/2;
    return arr[half+1];
}

int maping_solution(int arr[], int n) // uses map
{
    std::map<int,int> m ;
    int half = n/2;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
        if (m[arr[i]] > half)
        {
            return arr[i];
        }
    }

    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    int numbers[n];
    for (int& i : numbers)
    {
        std::cin >> i;
    }

    std::cout << sorting_solution(numbers, n) << '\n';
    std::cout << maping_solution(numbers, n) << '\n';
    return 0;
}


// leetcode solutions (all by me)

////sorting method
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int half = nums.size()/2;
//         for (int i = 0; i < half+1; i++)
//         {
//             if (nums[i] == nums[i+half])
//             {
//                 return nums[i];
//             }
//         }
//         return -1;
//     }
// };

////sorting method improved version
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int half = nums.size()/2;
//         return nums[half+1];
//     }
// };

////map method(beats 100%)
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         map<int,int> m ;
//         int half = nums.size()/2;
//         for (const int& i : nums)
//         {
//             if (!m.count(i))
//             {
//                 m[i] = 1;
//                 if(m[i] > half)
//                 {
//                     return i;
//                 }
//             }
//             else
//             {
//                 m[i]++;
//                 if(m[i] > half)
//                 {
//                     return i;
//                 }
//             }
//         }
//         return -1;
//     }
// };