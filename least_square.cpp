#include <bits/stdc++.h>
using namespace std;

class least_square
{
private:
    double a, b, sumx, sumy, sumxx, sumxy;

public:
    least_square()
    {
        sumx = 0, sumxx = 0;
        sumy = 0, sumxy = 0;
    }

public:
    void leastSquare(int n, double x[], double y[])
    {
        for (int i = 0; i < n; i++)
        {
            sumx += x[i];
            sumy += y[i];
            sumxx += (x[i] * x[i]);
            sumxy += (x[i] * y[i]);
        }

        a = (n * sumxy - sumx * sumy) / (n * sumxx - sumx * sumx);
        b = (sumy / n) - a * (sumx / n);
    }

public:
    void getAns()
    {
        cout << "The value are : " << a << " and " << b << endl;
        cout << "The best stright line fit is : " << a << " x + " << b << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    double x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];

    least_square least_square;
    least_square.leastSquare(n, x, y);
    least_square.getAns();
}
