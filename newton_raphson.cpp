#include <bits/stdc++.h>
using namespace std;

class newton_raphson
{
private:
    double root, eps;

public:
    newton_raphson()
    {
        root = 1;
        eps = 0.0001;
    }

public:
    double f(double x)
    {
        return x * x * x - 2 * x - 5;
    }

public:
    double derif(double x)
    {
        return 3 * x * x - 2;
    }

public:
    double getRoot()
    {
        return root;
    }

public:
    void findRoot()
    {
        while (abs(f(root)) > eps)
        {
            root = root - (f(root) / derif(root));
        }
    }
};

int main()
{
    newton_raphson newton_raphson;
    newton_raphson.findRoot();
    cout << "The root = " << setprecision(10) << newton_raphson.getRoot() << endl;
}
