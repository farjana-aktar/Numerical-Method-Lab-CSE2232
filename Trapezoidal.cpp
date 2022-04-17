#include <bits/stdc++.h>
using namespace std;

class Trapezoidal
{
private:
    double sum;

public:
    Trapezoidal()
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
    void findAns(double ub, double lb, int n)
    {
        double h = (ub - lb) / n;
        double k;

        sum = f(ub) + f(lb);

        for (int i = 1; i <= n - 1; i++)
        {
            k = (lb + i * h);
            sum = sum + 2 * f(k);
        }
        sum = sum * h / 2;
    }
};

int main()
{
    int n;
    cin >> n;
    double ub, lb;
    cin >> ub >> lb;

    Trapezoidal Trapezoidal;
    Trapezoidal.findAns(ub, lb, n);
    cout << "The definite integral is : " << Trapezoidal.getAns() << endl;
}
