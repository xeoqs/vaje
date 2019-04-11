#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

void vpis(char tab[][10], int n);
void izpis(char tab[][10], int n);
int stsamog(char tab[][10], int n);
int najmanjsi(char tab[][10], int n);
void razl(char tab[][10], int n);
void randindex(char tab[][10]);

void bsort(char tab[][10], int n, int vrst);
void najv(char tab[][10], int n);

int main()
{
	srand(time(NULL));

	char tab[10][10];

	vpis(tab, 10);
	izpis(tab, 10);
	cout << "V temu stolpcu je " << stsamog(tab, 10) << " samoglasnikov\n";
	randindex(tab);
	razl(tab, 10);
	najv(tab, 10);


	return 0;
}

void vpis(char tab[][10], int n)
{
	//vse Q
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tab[i][j] = 'Q';


	// !
	for (int i = 0; i < n ; i++)
		for(int j = n-i ; j < n ; j++)
			tab[j][i] = '!';



	//A
	for (int i = 1; i < n; i++)
		tab[i][n - i] = 'A';


	//E
	for (int i = 0; i < n-1; i++)
		tab[i][n - i-2] = 'E';

	//x

	for (int i = 0; i < n; i++)
		tab[i][i] = char('9'-i);
	//cdef
	for (int i = 0; i < n; i++)
		tab[i][n-i-1] = 'c' + i;
}

void izpis(char tab[][10], int n) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << fixed << setw(2) << tab[i][j];
		cout << "\n";
	}
}

int stsamog(char tab[][10], int n)
{
	int stolpec;
	int stsam = 0;
	cout << "vnesite stevilko stolpca, katerega sevilo samoglasnikov zelite presteti: ";

	do
	{
			cin >> stolpec;
	} while (stolpec < 1 || stolpec > n);

	for (int i = 0; i < n ; i++)
		switch (tab[i][stolpec-1]) 
		{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			stsam++;
		}
	return stsam;
}

void randindex(char tab[][10])
{
	int i = rand() % 10;
	int j = rand() % 10;
	if(tab[i][j] == 3*(i+j))
		cout << "(" <<i<<","<<j<<")\n";
}

int najmanjsi(char tab[][10], int n)
{
	int najm = tab[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (tab[i][j] < najm)
				najm = tab[i][j];
	return najm;
}


void razl(char tab[][10], int n)
{
	int stevilo = 0;
	int najm = najmanjsi(tab, n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (tab[i][j] - najm == 10)
				stevilo++;
	cout << "Takih stevil je " << stevilo << "\n";
}

	

void najv(char tab[][10], int n)
{
	int najv = tab[0][0];
	int najvs = 0;
	for (int i = 0; i < n; i++)
		if (tab[i][i] > najv)
		{
			najv = tab[i][i];
			najvs = i;
		}
	bsort(tab, n, najvs);
	izpis(tab, n);
}


void bsort(char tab[][10], int n, int vrst)
{
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n - i; j++)
			if (tab[vrst][j] < tab[vrst][j - 1])
			{
				int temp = tab[vrst][j];
				tab[vrst][j] = tab[vrst][j - 1];
				tab[vrst][j - 1] = temp;
			}
}
