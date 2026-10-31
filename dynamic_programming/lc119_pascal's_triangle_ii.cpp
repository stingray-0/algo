#include <iostream>
#include <vector>

std::vector<int> get_row(int rowIndex) 
{
    std::vector<int> cur;
    std::vector<int> prev;
    for (int i = 0; i < rowIndex + 1; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            cur[j+1] = prev[j] + prev[j+1];
        }
        cur.push_back(1);
        prev = cur;
    }

    return cur;
}

int main()
{
    int row;
    std::cin >> row;

    std::vector<int> pascal_row = get_row(row);

    for (const int& i : pascal_row)
    {
        std::cout << i << ' ';
    }
}



//leetcode solution

// class Solution {
// public:
//     vector<int> getRow(int rowIndex) {
//         vector<int> cur;
//         vector<int> prev;
//         for (int i = 0; i < rowIndex + 1; i++)
//         {
//             for (int j = 0; j < i - 1; j++)
//             {
//                 cur[j+1] = prev[j] + prev[j+1];
//             }
//             cur.push_back(1);
//             prev = cur;
//         }

//         return cur;
//     }
// };