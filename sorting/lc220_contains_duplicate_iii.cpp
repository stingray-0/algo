#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

bool bad_solution(std::vector<int>& nums, int i_diff, int v_diff)
{
        int length = nums.size();
        std::vector<int> test_values = nums; 

        //this part is purely to check if valid valueDiff even exists
        //yeah this is for one of the TLE cases.....
        std::sort(test_values.begin(), test_values.end());
        bool valid_dif = false;
        for (int i = 0; i < length-1; i++)
        {
             if ((test_values[i+1] - test_values[i]) <= v_diff)
             {
                 valid_dif = true;
                 break;
             }
         }
         if (!valid_dif)
         {
             return false;
         }

        for (int i = 0; i < length; i++)
        {
            for (int j = 1; j <= i_diff; j++)
            {
                if (i+j >= length)
                {
                    break;
                }
                if (abs(nums[i] - nums[i+j]) <= v_diff)
                {
                    return true;
                }
            }
        }
        return false;
}


bool multiset_solution(std::vector<int>& nums, int i_diff, int v_diff)
{
        std::multiset<std::pair<int, int>> m;
        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            m.insert({nums[i], i});
        }

        for (auto it = m.cbegin(); next(it) != m.cend(); it++)
        {
            auto compare_it = next(it);
            if (compare_it->first == it->first && compare_it->second - it->second > i_diff)
            {
                continue;
            }
            while (compare_it != m.cend() && compare_it->first - it->first <= v_diff)
            {
                if (abs(compare_it->second - it->second) <= i_diff)
                {
                    return true;
                }
                compare_it = next(compare_it);
            }
        }
        return false;
}


int main()
{
    int n, index_diff, value_diff;
    std::cin >> n;
    std::vector<int> numbers_with_duplicates(n);
    for (int& i : numbers_with_duplicates)
    {
        std::cin >> i;
    }
    std::cin >> index_diff >> value_diff;

    if (bad_solution(numbers_with_duplicates, index_diff, value_diff))
    {
        std::cout << "Hell yeah!\n";
    }
    else
    {
        std::cout << ":skull:\n";
    }

    if (multiset_solution(numbers_with_duplicates, index_diff, value_diff))
    {
        std::cout << "Hell yeah!\n";
    }
    else
    {
        std::cout << ":skull:\n";
    }

    return 0;
}






//leetcode solutions both by me

//kinda bad solution (brute force)
// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
//         int length = nums.size();
//         vector<int> test_values = nums; 
//         sort(test_values.begin(), test_values.end());
//         bool valid_dif = false;
//         for (int i = 0; i < length-1; i++)
//         {
//              if ((test_values[i+1] - test_values[i]) <= valueDiff)
//              {
//                  valid_dif = true;
//                  break;
//              }
//          }
//          if (!valid_dif)
//          {
//              return false;
//          }

//         for (int i = 0; i < length; i++)
//         {
//             for (int j = 1; j <= indexDiff; j++)
//             {
//                 if (i+j >= length)
//                 {
//                     break;
//                 }
//                 if (abs(nums[i] - nums[i+j]) <= valueDiff)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
// };



//slighty better but absolutely too complicate solution
// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
//         multiset<pair<int, int>> m;
//         int length = nums.size();
//         for (int i = 0; i < length; i++)
//         {
//             m.insert({nums[i], i});
//         }

//         for (auto it = m.cbegin(); next(it) != m.cend(); it++)
//         {
//             auto compare_it = next(it);
//             if (compare_it->first == it->first && compare_it->second - it->second > indexDiff)
//             {
//                 continue;
//             }
//             while (compare_it != m.cend() && compare_it->first - it->first <= valueDiff)
//             {
//                 if (abs(compare_it->second - it->second) <= indexDiff)
//                 {
//                     cout << it->second << compare_it->second;
//                     return true;
//                 }
//                 compare_it = next(compare_it);
//             }
//         }
//         return false;
//     }
// };