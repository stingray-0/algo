#include <iostream>
#include <cmath>
using namespace std;


void hanoi(int disks, int start, int end)
{
    if (disks == 1)
    {
        cout <<start << ' ' << end <<'\n';
        return;
    }
    hanoi(disks-1, start, 6 - start - end);
    hanoi(1, start, end);
    hanoi(disks-1, 6 - start - end, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << pow(2, n) - 1 << '\n';
    hanoi(n, 1, 3);

    return 0;
}