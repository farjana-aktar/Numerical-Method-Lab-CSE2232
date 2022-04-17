#include <bits/stdc++.h>
using namespace std;

class secant
{
private:
    double a, b, root, eps;

public:
    secant()
    {
        a = 1, b = 2, eps = 0.0001;
    }

public:
    double f(double x)
    {
        return x * x * x - 2 * x - 5;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        do
        {
            root = b - (f(b) * (b - a)) / (f(b) - f(a));
            a = b;
            b = root;
        } while (abs(f(root)) > eps);
    }
};

int main()
{
    secant secant;
    secant.findRoot();
    cout << "The root = " << setprecision(10) << secant.getRoot() << endl;
}
