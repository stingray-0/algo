#include <iostream>

int climb_stairs(int n)
{
    int temp = 0, cur = 1, prev = 0;
    for (int i = 0; i < n; i++)
    {
        temp = cur;
        cur += prev;
        prev = temp;
    }

    return cur;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << climb_stairs(n);

    return 0;
}


//leetcode solution

// class Solution {
// public:
//     int climbStairs(int n) {
//         int temp = 0, cur = 1, prev  = 0;
//         for (int i = 0; i < n; i++)
//         {
//             temp = cur;
//             cur += prev;
//             prev = temp;
//         }
//         return cur;
//     }
// };