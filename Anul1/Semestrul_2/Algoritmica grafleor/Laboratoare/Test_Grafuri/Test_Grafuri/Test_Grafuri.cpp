#include <iostream>
#include <fstream>

using namespace std;

ifstream f("graf.txt");

int x[100][100], viz[100], mat_ver[100][100];

void dfs(int nod, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (x[nod][i] == 1 && viz[i] == 0)
        {
            mat_ver[nod][i] = mat_ver[i][nod] = 1;
            viz[i] = 1;
            dfs(i,n);
        }
    }
}

int main()
{
    int n, m, nod1, nod2;
    bool ok = true;
    f >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f  >> nod1 >> nod2;
        x[nod1][nod2] = x[nod2][nod1] = 1;
    }
    viz[1] = 1;
    dfs(1, n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mat_ver[i][j] != x[i][j])
                ok = false;
        }
    }
    if (ok == true)
        cout << "Da";
    else
        cout << "Nu";
}
