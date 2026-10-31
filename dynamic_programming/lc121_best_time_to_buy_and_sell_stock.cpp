#include <iostream>
#include <vector>

int max_profit(std::vector<int>& prices)
{
    int buy = prices[0];
    int profit = 0, n = prices.size();


    for (int i = 1; i < n; i++)
    {
        if (buy > prices[i])
        {
            buy = prices[i];
        }
        else if (profit < prices[i] - buy)
        {
            profit = prices[i] - buy;
        }
    }

    return profit;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> stock_price(n);
    for (int& i : stock_price)
    {
        std::cin >> i;
    }
    
    std::cout << max_profit(stock_price);
}

// leetcode solutions

//find largest sum of continuous numbers by me
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         vector<int> price_diffs;
//         int n = prices.size();
//         if (n == 1)
//         {
//             return 0;
//         }

//         for (int i = 0; i < n-1; i++)
//         {
//             price_diffs.push_back(prices[i+1] - prices[i]);
//         }

//         int all_max = price_diffs[0], temp_max = price_diffs[0];
//         for (int i = 1; i < price_diffs.size(); i++)
//         {
//             temp_max = max(price_diffs[i], temp_max + price_diffs[i]);
//             all_max = max(all_max, temp_max);
//         }

//         if (all_max < 0)
//         {
//             return 0;
//         }
//         else
//         {
//             return all_max;
//         }
//     }
// };

//same but easier
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int buy = prices[0];
//         int profit = 0, n = prices.size();


//         for (int i = 1; i < n; i++)
//         {
//             if (buy > prices[i])
//             {
//                 buy = prices[i];
//             }
//             else if (profit < prices[i] - buy)
//             {
//                 profit = prices[i] - buy;
//             }
//         }

//         return profit;
//     }
// };