#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
#include <queue>

using namespace std;

ifstream fi("graf.txt");
ofstream g("printare.txt");

struct structura{
	int lin;
	int col;
};
struct nod {
	int distanta;
};
struct ele {
	int nod, dis;
}a, coada2[1000], afis2[100];
structura dir[4] = {{1,0},{0,1},{-1,0},{0,-1}};
queue <structura> coada;

int matrice_adiacenta[100][100], matricea_inchiderii[100][100], mat[1000][1000], afis[1000][1000], viz2[100];


void problema1() {
	SetConsoleOutputCP(CP_UTF8);
	int n, nod1, nod2, i;
	fi >> n;
	while (fi >> nod1)
	{
		fi >> nod2;
		mat[nod1][nod2] = 1;
	}
	int lungime[100] = { 0 }, parinti[100] = {0};
	queue <int> coada;
	cout << "Da un nod: ";
	cin >> nod1;
	for (i = 1; i <= n; i++)
	{
		lungime[i] = 9999;
	}
	lungime[nod1] = 0;
	coada.push(nod1);
	while (!coada.empty())
	{
		for (i = 1; i <= n; i++)
		{
			if (mat[coada.front()][i] == 1)
			{
				if (lungime[i] == 9999)
				{
					parinti[i] = coada.front();
					lungime[i] = lungime[coada.front()] + 1;
					coada.push(i);
				}
			}
		}
		coada.pop();
	}
	for (int i = 1; i <= n; i++)
	{
		if (lungime[i] == 9999)
			cout << u8"∞ ";
		else
			cout << lungime[i] << " ";
	}
}
void copiere_matrice(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			matricea_inchiderii[i][j] = matrice_adiacenta[i][j];
		}
	}
}
void inchidere_tranzitiva(int n)//Roy-Warsall
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (matricea_inchiderii[i][j] == 0)
				{
					matricea_inchiderii[i][j] = (matricea_inchiderii[i][k] && matricea_inchiderii[k][j]);
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
		matricea_inchiderii[i][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << matricea_inchiderii[i][j] << " ";
		}
		cout << "\n";
	}
}
void problema2()
{
	int n, nod1, nod2;
	fi >> n;
	while (fi >> nod1)
	{
		fi >> nod2;
		matrice_adiacenta[nod1][nod2] = 1;
	}
	copiere_matrice(n);
	inchidere_tranzitiva(n);
}
void citire(int &is, int &js, int &ifin, int &jfin, int &lin, int &col, int labi)
{
	const char* nume_fisier = nullptr;
	lin = 0;
	col = 0;
	if (labi == 1)
		nume_fisier = "labirint_1.txt";
	else if (labi == 2)
		nume_fisier = "labirint_2.txt";
	else
		nume_fisier = "labirint_3.txt", col = 1000;
	FILE* file = fopen(nume_fisier, "r");
	char ch = 'a';
	int i = 1, j = 1;
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '1')
			mat[i][j++] = -1;
		if (ch == 'S')
		{
			mat[i][j] = 0;
			is = i;
			js = j;
			j++;
		}
		if (ch == 'F')
		{
			mat[i][j] == 0;
			ifin = i;
			jfin = j;
			j++;
		}
		if (ch == '\n')
		{
			if (col == 0)
				col = j;
			i++, j = 1;
		}
		if (ch == ' ')
		{
			mat[i][j] = 0;
			j++;
		}
	}
	lin = i;
}
void Traseu(int i, int j, int lg)
{
	if (mat[i][j] == 1)
	{
		cout << lg << "\n";
		afis[i][j] = 1;
	}
	else
	{
		int p = -1;
		for (int k = 0; k < 4 && p == -1; k++)
			if (mat[i][j] == mat[i + dir[k].lin][j + dir[k].col] + 1)
				p = k;
		Traseu(i + dir[p].lin, j + dir[p].col, lg + 1);
		afis[i][j] = 1;
	}
}
void problema3()
{
	int is, js, ifin, jfin, i, j, ii, jj, n, m, labi = 1;
	cout << "Ce labirint doresti: ";
	cin >> labi;
	is = js = ifin = jfin = 0;
	citire(is, js, ifin, jfin, n, m, labi);
	i = is;
	j = js;
	structura nod;
	nod.lin = is;
	nod.col = js;
	coada.push(nod);
	mat[is][js] = 1;
	mat[is - 1][js] = -1;
	mat[is - 1][js - 1] = -1;
	mat[is - 1][js + 1] = -1;
	mat[ifin + 1][jfin] = -1;
	mat[ifin + 1][jfin - 1] = -1;
	mat[ifin + 1][jfin + 1] = -1;
	while (!coada.empty())
	{
		i = coada.front().lin;
		j = coada.front().col;
		for (int t = 0; t <= 3; t++)
		{
			ii = i + dir[t].lin;
			jj = j + dir[t].col;
			if (mat[ii][jj] == 0)
			{
				mat[ii][jj] = mat[i][j] + 1;
				nod.lin = ii;
				nod.col = jj;
				coada.push(nod);
			}
		}
		coada.pop();
	}
	Traseu(ifin, jfin, mat[ifin][jfin]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (afis[i][j] != 0)
				g << afis[i][j];
			else
				g << " ";
		}
		g << "\n";
	}
}
void problema4()
{
	int n, nod1, nod2, i, nod;
	int viz[100];
	fi >> n;
	while (fi >> nod1)
	{
		fi >> nod2;
		mat[nod1][nod2] = 1;
	}
	cout << "Te rog sa imi dai un nod: ";
	cin >> nod;
	int start = 1, end = 1;
	for (int i = 1; i <= n; i++)
		viz[i] = 0, coada2[i].nod = coada2[i].dis = 0;
	a.nod = nod;
	a.dis = 0;
	viz[nod] = 1;
	coada2[1] = a;
	while (start <= end)
	{
		for (int i = 1; i <= n; i++)
		{
			if (mat[coada2[start].nod][i] == 1 && viz[i] == 0)
			{
				a.nod = i;
				a.dis = coada2[start].dis + 1;
				coada2[++end] = a;
				viz[i] = 1;
			}
		}
		start++;
	}
	cout << "Varfurile descoperite cu BFS impreuna cu distatele lor sunt: \n";
	for (int i = 1; i <= end; i++)
	{
		cout << coada2[i].nod << " " << coada2[i].dis << "\n";
	}
	cout << "Varfurile nedescoperite sunt: ";
	for (int i = 1; i <= n; i++)
	{
		if (viz[i]==0)
		{
			cout << i << " ";
		}				
	}
}
void dfs(int n, ele nod, int& con)
{
	viz2[nod.nod] = 1;
	afis2[con] = nod;
	for (int i = 1; i <= n; i++)
	{
		if (mat[nod.nod][i] == 1 && viz2[i] == 0)
		{
			ele a;
			a.dis = nod.dis + 1;
			a.nod = i;
			con++;
			dfs(n, a, con);
		}
	}
	
}
void problema5()
{
	int n, nod1, nod2, i, nod, con = 1;
	int viz[100];
	fi >> n;
	while (fi >> nod1)
	{
		fi >> nod2;
		mat[nod1][nod2] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		afis2[i].dis = afis2[i].nod = viz[i] = 0;
	}
	cout << "Te rog sa imi dai un nod: ";
	cin >> nod;
	ele a;
	a.nod = nod;
	a.dis = 0;
	dfs(n, a, con);
	cout << "Varfurile descoperite cu DFS impreuna cu distatele lor sunt: \n";
	for (int i = 1; i <= con; i++)
	{
		cout << afis2[i].nod << " " << afis2[i].dis << "\n";
	}
	cout << "Varfurile nedescoperite sunt: ";
	for (int i = 1; i <= n; i++)
	{
		if (viz2[i] == 0)
		{
			cout << i << " ";
		}
	}
}

int main()
{
	problema5();
}

