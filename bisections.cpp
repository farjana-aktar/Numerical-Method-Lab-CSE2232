#include <bits/stdc++.h>
using namespace std;

class bisections
{
private:
    double a, b, root, eps;

public:
    bisections()
    {
        a = 0, b = 0, eps = 0.00001;
    }

public:
    double f(double x)
    {
        return x * x * x + 4 * x * x - 1;
    }

public:
    void findInterval()
    {
        do
        {
            a--;
            b++;
        } while (f(a) * f(b) >= 0);

        if (f(b) < 0)
            swap(a, b);
        return;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        findInterval();

        double mid = (a + b) / 2;

        while (abs(f(b) - f(a)) > eps)
        {
            if (f(mid) == 0)
                break;
            else if (f(mid) > 0)
                b = mid;
            else
                a = mid;

            mid = (a + b) / 2;
        }

        root = mid;
    }
};

int main()
{
    bisections Bisection;
    Bisection.findRoot();
    cout << "The root = " << setprecision(10) << Bisection.getRoot() << endl;
}
