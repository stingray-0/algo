#include <iostream>

int fast_pow(int b, int e)
{
    if (e == 0)
    {
        return 1;
    }

    double temp = fast_pow(b, e/2);

    if (e%2)
    {
        return temp * temp * b;
    }
    else
    {
        return temp * temp;
    }
}


int main()
{
    int base, exponent;
    std::cin >> base >> exponent;

    std::cout << fast_pow(base, exponent);
}