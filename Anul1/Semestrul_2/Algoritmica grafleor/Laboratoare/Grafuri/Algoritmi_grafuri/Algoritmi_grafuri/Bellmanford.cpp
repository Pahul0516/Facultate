#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

ifstream f("graf2.txt");
ofstream g("bellmanford.out");

queue <int> coada;
int viz[50001], cost[50001], start[50001], t[3][250001], fr[50001];

void generare_vector_cost(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cost[i] = 999999;
    }
    cost[1] = 0;
}

void modificare_costuri(int primul_element, int indice_vecin)
{
    intant;
    if (cost[primul_element] + t[2][indice_vecin] < cost[t[0][indice_vecin]])
    {
        cost[t[0][indice_vecin]] = cost[primul_element] + t[2][indice_vecin];
        if (viz[t[0][indice_vecin]] == 0)
        {
            coada.push(t[0][indice_vecin]);
            viz[t[0][indice_vecin]] = 1;
        }
    }
}

int main()
{
    int n, m, a, b, c, z = 0, nr, cop, mini = 999999;
    bool ok = 0;
    f >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        f >> a >> b >> c;
        z++;
        t[2][z] = c;
        t[0][z] = b;
        t[1][z] = start[a];
        start[a] = z;
    }
    generare_vector_cost(n);
    coada.push(1);
    viz[1] = 1;
    while (coada.empty() == 0)
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
        /// cresc fr[cop]++;
        /// if fr[cop]>=n break;
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
            cout << cost[i] << " ";
        }
    }
    else
    {
        g << "Ciclu negativ!";
    }
    return 0;
}