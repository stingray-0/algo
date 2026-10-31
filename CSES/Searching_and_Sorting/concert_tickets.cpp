#include <iostream>
// #include <vector>
#include <algorithm>
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