#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <climits>
#include <bitset>
#include <cmath>
#include <climits>

#define INT_MAX 10000

using namespace std;

ifstream f("graf1.txt");
ofstream g("dijkstra.out");

int x[1001][1001], tata[1000], viz[1000], d[10000];

void dijkstra(int nr, int n)
{
    int i, j, min, ok, k;
    ok = 1;
    for (int i = 1; i <= n; i++)
    {
        d[i] = x[nr][i];
        tata[i] = nr;
        viz[i] = 0;
    }
    viz[nr] = 1;
    tata[nr] = 0;
    while (ok != 0)
    {
        min = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            if (viz[i] == 0 && d[i] < min)
            {
                min = d[i];
                k = i;
            }
        }
        if (min != INT_MAX)
        {
            viz[k] = 1;
            for (int i = 1; i <= n; i++)
            {
                if (viz[i] == 0 && d[i] > d[k] + x[k][i])
                {
                    d[i] = d[k] + x[k][i];
                    tata[i] = k;
                }
            }
        }
        else
            ok = 0;
    }
}

void drum(int i)
{
    if (i != 0)
    {
        drum(tata[i]);
        cout << i << " ";
    }
}

int main()
{
    int n, p, a, b, c;
    f >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                x[i][j] = 0;
            }
            else
            {
                x[i][j] = INT_MAX;
            }
        }
    }
    while (f >> a >> b >> c)
    {
        x[a][b] = c;
    }
    dijkstra(p, n);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 10000)
            cout << -1 << " ";
        else
            cout << d[i] << " ";
    }
    return 0;
}