#include <iostream>
#include <iomanip>

using namespace std;

void vpis(char tab[][10], int n);
void izpis(char tab[][10], int n);

int main()
{
	char tab[10][10];

	vpis(tab, 10);

	izpis(tab, 10);

	return 0;
}



void vpis(char tab[][10], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tab[i][j] = 'Q';


	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			tab[j][i] = '!';

for (int i = 0; i < n ; i++)
		for (int j = 0; j < n-i-1; j++)
			tab[i][j] = 'Q';

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
