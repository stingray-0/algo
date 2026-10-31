#include<iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) 
{
    std::vector<std::vector<int>> ans = {{1}};
    for (int i = 1; i < numRows; i++)
    {
        std::vector<int> row;
        row.push_back(1);
        for (int j = 0; j < i - 1; j++)
        {
            row.push_back(ans[i-1][j]+ans[i-1][j+1]);
        }
        row.push_back(1);
        ans.push_back(row);
    }
    return ans;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> pascal = generate(n);

    for (const std::vector<int>& v : pascal)
    {
        for (const int& i : v)
        {
            std::cout << i << ' ';
        }
        std::cout << '\n';
    }
}



//leetcode solution

// class Solution {
// public:
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> ans = {{1}};
//         for (int i = 1; i < numRows; i++)
//         {
//             vector<int> row;
//             row.push_back(1);
//             for (int j = 0; j < i - 1; j++)
//             {
//                 row.push_back(ans[i-1][j]+ans[i-1][j+1]);
//             }
//             row.push_back(1);
//             ans.push_back(row);
//         }
//         return ans;
//     }
// };