#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int count = 0;
    while (n != 0)
    {
        int x[110] = {}, y[110] = {};
        int xmax = 1100, xmin = -1100, ymax = 1100, ymin = -1100;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
            if (i == 0)
            {
                x[n] = x[0];
                y[n] = y[0];
            }
            else
            {
                if (x[i] == x[i - 1])
                {
                    if (y[i] < y[i - 1])
                    {
                        xmax = min(x[i], xmax);
                    }
                    else
                    {
                        xmin = max(x[i], xmin);
                    }
                }
                else //可知y[i]==y[i-1]
                {
                    if (x[i] > x[i - 1])
                    {
                        ymax = min(y[i], ymax);
                    }
                    else
                    {
                        ymin = max(y[i], ymin);
                    }
                }
            }
        }
        if (x[n-1] == x[n])
        {
            if (y[n-1] > y[n])
            {
                xmax = min(x[n-1], xmax);
            }
            else
            {
                xmin = max(x[n-1], xmin);
            }
        }
        else //可知y[n-1]==y[n]
        {
            if (x[n-1] < x[n])
            {
                ymax = min(y[n-1], ymax);
            }
            else
            {
                ymin = max(y[n-1], ymin);
            }
        }
        if (ymin < ymax &&xmin < xmax)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        cin >> n;
    }
    return 0;
}
