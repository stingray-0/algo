#include <iostream>
#include <vector>
#include <algorithm>

// int search_ticket(std::vector<int> v, int head, int end, int price)
// {
//     int ans = -1;
//     while (head <= end)
//     {
//         int mid = (head + end) / 2;
//         if (price >= v[mid])
//         {
//             ans = mid;
//             head = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//     }
//     return ans;
// }

// int main()
// {
//     int n1 , n2;
//     std::cin >> n1 >> n2;
//     std::vector<int> tickets(n1);
//     for (int& i : tickets)
//     {
//         std::cin >> i;
//     }
//     std::sort(tickets.begin(), tickets.end());

//     int max_price;
//     for(int i = 0;  i < n2; i++)
//     {
//         std::cin >> max_price;
//         int pos = search_ticket(tickets, 0, n1-1, max_price);
//         if (pos == -1)
//         {
//             std::cout << -1 << '\n';
//         }
//         else
//         {
//             std::cout << tickets[pos] << '\n';
//             tickets.erase(tickets.begin() + pos);
//         }
//     }

//     return 0;
// }

#include <set>

int main()
{
    int n1 , n2;
    std::cin >> n1 >> n2;
    std::multiset<int> tickets;
    for (int i = 0; i < n1; i++)
    {
        int price;
        std::cin >> price;
        tickets.insert(price);
    }

    for (int i = 0; i < n2; i++)
    {
        int max_price;
        std::cin >> max_price;
        auto it = tickets.upper_bound(max_price);
        if (it == tickets.begin())
        {
            std::cout << -1 << '\n';
        }
        else
        {
            it--;
            std::cout << *it << '\n';
            tickets.erase(it);
        }
    }
}