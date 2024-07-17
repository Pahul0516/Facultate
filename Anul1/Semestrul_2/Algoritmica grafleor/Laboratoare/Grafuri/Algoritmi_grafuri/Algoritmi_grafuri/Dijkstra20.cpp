#include <iostream>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

ifstream f("graf.txt");

struct ceva
{
    int nod, valoare;
};

int viz[100], cost[100];
vector<ceva> lista[100];

int main()
{
    int n, nod, x, y, p, nod_cur = -1, mini = 99999;
    f >> n >> nod;
    while (f >> x)
    {
        f >> y >> p;
        ceva a;
        a.nod = y;
        a.valoare = p;
        lista[x].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        cost[i] = 999999;
    cost[nod] = 0;

    while (true)
    {
        mini = 9999;
        for (int i = 1; i <= n; i++)
        {
            if (viz[i] == 0 && cost[i] < mini)
            {
                mini = cost[i];
                nod_cur = i;
            }
        }

        if (mini != 9999)
        {
            viz[nod_cur] = 1;
            for (int i = 0; i < lista[nod_cur].size(); i++)
            {
                int nod_vecin = lista[nod_cur][i].nod;
                int pondere = lista[nod_cur][i].valoare;
                if (viz[nod_vecin] == 0 && cost[nod_cur] + pondere < cost[nod_vecin])
                {
                    cost[nod_vecin] = cost[nod_cur] + pondere;
                }
            }
        }
        else
        {
            break;
        }

    }
    {
        if (cost[i] == 999999)
            cout << "-1";
        else
            cout << cost[i] << " ";
    }
    return 0;
}