#include <bits/stdc++.h>
using namespace std;

class Simpson
{
private:
    double sum;

public:
    Simpson()
    {
        sum = 0;
    }

public:
    double f(double x)
    {
        return 1 / (1 + x * x);
    }

public:
    double getAns()
    {
        return sum;
    }

public:
    void findAns(int n, double ub, double lb)
    {
        double h = (ub - lb) / n;
        double k;
        sum = f(ub) + f(lb);
        for (int i = 1; i <= n - 1; i++)
        {
            k = lb + i * h;
            if (i % 2 == 0)
            {
                sum = sum + 2 * f(k);
            }
            else
            {
                sum = sum + 4 * f(k);
            }
        }
        sum = sum * (h / 3);
    }
};

int main()
{
    int n, ub, lb;
    cin >> n >> ub >> lb;

    Simpson Simpson;
    Simpson.findAns(n, ub, lb);
    cout << "The required integration is : " << Simpson.getAns() << endl;
}
