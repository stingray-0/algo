#include <bits/stdc++.h>
using namespace std;
 
 
long long divide_apples(int index, int* arr, long long first, long long second, int n)
{
    if (index == n)
    {
        return abs(first - second);
    }

    return min(divide_apples(index+1, arr, first+arr[index], second, n), divide_apples(index+1, arr, first, second+arr[index], n));
}

 
 
int main()
{
    int n;
    cin >> n;
    int apples[20];
    for (int i = 0; i < n; i++)
    {
        cin >> apples[i];
    }
    cout << divide_apples(0, apples, 0, 0, n);
 
    return 0;
}