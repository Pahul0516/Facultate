#include <iostream> 
#include <fstream>
#include <queue>

using namespace std;

ifstream f("graf.txt");
ofstream g("dijkstra.out");

queue<int>coada;
int t[3][1001], start[10001], cost[100001], viz[100001], fr[100001];

void modificare_costuri(int primul_element, int indica_vecin)
{
    if (cost[primul_element] + t[2][indica_vecin] < cost[t[0][indica_vecin]])
    {
        cost[t[0][indica_vecin]] = cost[primul_element] + t[2][indica_vecin];
        if (viz[t[0][indica_vecin]] == 0)
        {
            viz[t[0][indica_vecin]] = 1;
            coada.push(t[0][indica_vecin]);
        }
    }
}

int main()
{
    int n, k, a, b, c, z = 0, nr, cop;
    bool ok = 0;
    f >> n >> a >> k;
    k++;
    while (f >> a >> b >> c)
    {
        a++;
        b++;
        z++;
        t[2][z] = c;
        t[0][z] = b;
        t[1][z] = start[a];
        start[a] = z;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == k)
            cost[i] = 0;
        else
            cost[i] = 999999;
    }
    viz[k] = 1;
    coada.push(k);
    while (!coada.empty())
    {
        nr = start[coada.front()];
        cop = coada.front();
        viz[cop] = 0;
        fr[cop]++;
        if (fr[cop] >= n)
        {
            ok = 1;
            break;
        }
        while (nr != 0)
        {
            modificare_costuri(cop, nr);
            nr = t[1][nr];
        }
        coada.pop();
    }
    if (ok == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            if (cost[i] == 999999)
            {
                cout << "INF ";
            }
            else
            {
                cout << cost[i] << " ";
            }
        }
    }
    else
        cout << "Ciclu negativ";
    return 0;
}