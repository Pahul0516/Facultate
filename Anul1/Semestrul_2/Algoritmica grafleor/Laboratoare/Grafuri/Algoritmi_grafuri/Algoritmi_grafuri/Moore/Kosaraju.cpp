#include <iostream>
#include <fstream>
#include <cstring>
#include <Windows.h>
#include <queue>

using namespace std;

ifstream fi("graf3.txt");
ofstream g("printare.txt");

struct structura {
	int lin;
	int col;
};
struct nod {
	int distanta;
};
struct ele {
	int nod, dis;
}a, coada2[1000], afis2[100];
structura dir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
queue <structura> coada;

int matrice_adiacenta[100][100], matricea_inchiderii[100][100], mat[1000][1000], afis[1000][1000], viz2[100];

void problema1() {
	int n, nod1, nod2, i;
	fi >> n;
	while (fi >> nod1)
	{
		fi >> nod2;
		mat[nod1][nod2] = 1;
	}
	int lungime[100] = { 0 }, parinti[100] = { 0 };
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
			cout << u8"? ";
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

int main()
{
	problema1();
}

