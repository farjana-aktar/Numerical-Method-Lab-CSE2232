#include <bits/stdc++.h>
using namespace std;
#define max_cnt 10000000

class falsePosition
{
    
private:
    double a, b, root, eps;
    int itr;

public:
    falsePosition()
    {
        a = 0, b = 0;
        eps = 0.0001;
        itr = 1;
    }

public:
    double f(double x)
    {
        return x * x * x - 2 * x * x + 3 * x - 5;
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

        double mid = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));

        for (int i = 0; i < max_cnt; i++)
        {
            if (f(mid) == 0)
                break;
            else if (f(mid) > 0)
                b = mid;
            else
                a = mid;
            itr++;
            mid = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
        }
        root = mid;
    }
};

int main()
{
    falsePosition FalsePosition;
    FalsePosition.findRoot();
    cout << "The root = " << setprecision(10) << FalsePosition.getRoot() << endl;
}
