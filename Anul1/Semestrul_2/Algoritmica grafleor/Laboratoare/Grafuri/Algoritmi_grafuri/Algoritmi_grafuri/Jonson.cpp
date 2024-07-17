#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
int a[100][100], nod, n, m;
int costuri[100], vizitat[100], d[100], tati[101], rezultat[3][3];

ifstream f("a.txt");
ofstream g("o.txt");
void bellman_ford(int nod) {
    int x;
    for (int i = 0; i < n; i++)
        costuri[i] = 1000001, vizitat[i] = 0;

    costuri[nod] = 0;
    vizitat[nod] = 1;
    std::queue<int> c;

    c.push(nod);
    while (!c.empty()) {
        x = c.front();
        for (int i = 0; i < n; i++)
            if (a[x][i] != 0 && costuri[i] > costuri[x] + a[x][i]) {
                costuri[i] = costuri[x] + a[x][i];
                c.push(i);
                vizitat[i] = 1;
            }
        c.pop();
        vizitat[x] = 0;
    }


}


void dijkstra(int nod)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && a[i][j] == 0)
                a[i][j] = 1000001;


    for (int i = 0; i < n; i++)
    {
        d[i] = a[nod][i];
        if (a[nod][i] != 1000001)
            tati[i] = nod;
        else tati[i] = -1;
        vizitat[i] = 0;
    }

    vizitat[nod] = 1;
    tati[nod] = 0;
    bool ok = true;
    int mini, k;
    while (ok)
    {
        mini = 1000001;
        for (int i = 0; i < n; i++)
            if (!vizitat[i] && mini > d[i])
                mini = d[i], k = i;

        if (mini != 1000001)
        {
            vizitat[k] = 1;
            for (int i = 0; i < n; i++)
                if (!vizitat[i] && d[i] > d[k] + a[k][i])
                { 
                    d[i] = d[k] + a[k][i];
                    tati[i] = k;
                }
        }
        else ok = false;
    }


}

void jonson()
{
    for (int i = 0; i < n; i++)
        a[n + 1][i] = 0;

    bellman_ford(n + 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0 && a[i][j] != 1000001)
                a[i][j] += costuri[i] - costuri[j];



}


int main(int argc, char* argv[]) {


    f >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int j, k, cost;
        f >> j >> k >> cost;
        a[j][k] = cost;
    }


    jonson();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != 0 && a[i][j] != 1000001)
                g << i << " " << j << " " << a[i][j] << '\n';

    for (int j = 0; j < n; j++)
    {
        dijkstra(j);
        for (int i = 0; i < n; i++)
            if (d[i] > 999995)
                g << "inf" << " ";
            else
                g << d[i] << " ";

        g << '\n';
    }


    f.close();
    g.close();
    return 0;
}