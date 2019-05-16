//pogram, ki preberi podatke za 10 živali,
// ime, starost, z binarnim iskanem poišči žival s prebranim imenom

#include <iostream>
#include <cstdio>
#include <stdio.h>

using namespace std;

struct oseba
{
	char ime[21];
	int starost;
};



void vpis(struct oseba x[], int n);
void bsort(struct oseba x[], int n);
void bsearch(struct oseba x[], int n);

int main()
{
	struct oseba tab[10];

	vpis(tab, 10);
	bsort(tab, 10);
	bsearch(tab, 10);

	return 0;
}


void vpis(struct oseba x[], int n)
{
	for (int i = 0; i < n; i++)
	{
		fflush(stdin);
		cout << "\n ime: ";
		gets_s(x[i].ime);
		cout << "\n starost: ";
		cin >> x[i].starost;
	}
}

void bsort(struct oseba x[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (strcmp(x[j].ime, x[j - 1].ime) < 0)
			{
				char tempi[21];
				strcpy_s(tempi, x[j - 1].ime);
				strcpy_s(x[j - 1].ime, x[j].ime);
				strcpy_s(x[j].ime, tempi);

				int temps = x[j - 1].starost;
				x[j - 1].starost = x[j].starost;
				x[j].starost = temps;
			}
}

void bsearch(struct oseba x[], int n)
{
	int zac = 0, kon = n - 1, sred;
	char iskana[21];

	cout << "Vnesite iskano ime: ";
	fflush(stdin);
	gets_s(iskana);

	do
	{
		sred = (zac + kon) / 2;
		if (strcmp(iskana, x[sred].ime) == 0)
			cout << "najden je: " << x[sred].ime << "\n star: " << x[sred].starost << "let";

		else if (strcmp(iskana, x[sred].ime) < 0)
			kon = sred;
		else
			zac = sred;

	} while (zac <= kon && strcmp(iskana, x[sred].ime) != 0);
}
