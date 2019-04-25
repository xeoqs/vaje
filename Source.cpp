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

	//ozdzadje
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tab[i][j] = ' ';
	

	for (int i = n - 1; i > n / 2 - 1; i--)
		for (int j = n- 1; j > i-1; j--)
			tab[i][j] = '1';


		
	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < i + 1; j++)
		{
			tab[i][n-j-1] = '1';
		}
		



	for (int i = n - 1; i > n / 2 - 1; i--)
		for (int j = n - 1; j > i - 1; j--)
			tab[j][i] = '0';



	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < i + 1; j++)
		{
			tab[n - j - 1][i] = '0';
		}



	for (int i = n - 1; i > n / 2 - 1; i--)
		for (int j = n - 1; j > i - 1; j--)
			tab[i][n - j- 1] = '2';



	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < i + 1; j++)
		{
			tab[i][j] = '2';
		}


	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < i + 1; j++)
		{
			tab[j][i] = '3';
		}



	for (int i = 0; i < n / 2; i++)
		for (int j = 0; j < i + 1; j++)
		{
			tab[j][n-i-1] = '3';
		}


	//diagonale

	for (int i = 0; i < n; i++)
	{
		tab[i][i] = 'z';
		tab[i][n - i-1] = 'x';

	}





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
