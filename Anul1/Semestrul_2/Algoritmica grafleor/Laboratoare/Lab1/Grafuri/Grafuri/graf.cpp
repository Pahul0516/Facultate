#include <iostream>
#include <fstream>

using namespace std;

ifstream f("in.txt");

struct ele{
	int nod, dis;
}a, coada[1000];

int matrice_adiaceanta[100][100], lista_adiacenta[100][100], viz[100], distante[100][100];

void distanta(int n, int nod)
{
	int start = 1, end = 1;
	for (int i = 1; i <= n; i++)
		viz[i] = 0, coada[i].nod = coada[i].dis = 0;
	viz[nod] = 1;
	a.nod = nod;
	a.dis = 0;
	viz[nod] = 1;
	coada[1] = a;
	while (start <= end)
	{
		for (int i = 1; i <= n; i++)
		{
			if (matrice_adiaceanta[coada[start].nod][i] == 1 && viz[i]==0)
			{
				a.nod = i;
				a.dis = coada[start].dis + 1;
				coada[++end] = a;
				viz[i] = 1;
			}
		}
		start++;
	}
}

int main()
{
	int n;
	int mu1, mu2;
	f >> n;
	f >> mu1;
	while (f >> mu2)
	{
		matrice_adiaceanta[mu1][mu2] = 1;
		matrice_adiaceanta[mu2][mu1] = 1;
		f >> mu1;
	}

	cout << "Matricea de adiacenta\n";
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << matrice_adiaceanta[i][j] << " ";
		}
		cout << "\n";
	}
	int con;
	for (int i = 1; i <= n; i++)
	{
		con = 0;
		for (int j = 1; j <= n; j++)
		{
			if (matrice_adiaceanta[i][j] == 1)
			{
				lista_adiacenta[i][++con] = j;
			}
		}
	}
	cout << "Lista de adiacenta \n";
	for (int i = 1; i <= n; i++)
	{
		cout << i << ": ";
		for (int j = 1; j <= n; j++)
		{
			if (lista_adiacenta[i][j]!=0)
			{
				cout << lista_adiacenta[i][j]<<" ";
			}
			else
			{
				continue;
			}
		}
		cout << "\n";
	}


	bool ver;
	for (int i = 1; i <= n; i++)
	{
		ver = true;
		for (int j = 1; j <= n; j++)
		{
			if (matrice_adiaceanta[i][j] == 1)
				ver = false;
		}
		if (ver == true)
		{
			cout << "Nodul " << i << " e izolat\n";
		}
		else
		{
			cout << "Nodul " << i << " nu e izolat\n";
		}
	}


	int sum1 = 0, sum2 = 0;
	bool ok = true;
	for (int i = 1; i <= n; i++)
	{
		sum1+= matrice_adiaceanta[1][i];
	}
	for (int i = 2; i <= n; i++)
	{
		sum2 = 0;
		for (int j = 1; j <= n; j++)
		{
			sum2 = sum2 + matrice_adiaceanta[i][j];
		}
		if (sum1 != sum2)
			ok = false;
	}
	if (ok == false)
	{
		cout << "Graful nu e regulat\n";
	}
	else
	{
		cout << "Graful e regulat\n";
	}

	for (int i = 1; i <= n; i++)
	{
		distanta(n, i);
		for (int j = 1; j <= n; j++)
		{
			distante[i][coada[j].nod] = coada[j].dis;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << distante[i][j] << " ";
		}
		cout << "\n";
	}

	bool verificare_finala = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				if (distante[i][j] == 0)
					verificare_finala = false;
			}
		}
	}
	if (verificare_finala == false)
		cout << "Graful nu e conex";
	else
		cout << "Graful e conex";
	return 0;
}