#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long int greatest{};
    long long int greatest_n{};
    long long int count{};
    for (int n = 1; n < pow(10, 6); n++)
    {
        count = 1;
        for (long long int i = n;;)
        {
            if (i % 2 == 0)
                i /= 2;
            else
                i = 3 * i + 1;
            count++;
            if (i == 1)
                break;
        }
        if (count > greatest)
        {
            greatest = count;
            greatest_n = n;
        }
    }
    cout << greatest_n;
}
