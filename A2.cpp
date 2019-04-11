#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

void Isci(char niz[], int zapbeseda);
void abeceda(char niz[]); 
void bsort(char niz[]);
void lookup(char niz[]);

int main() 
{
	char niz[41];
	gets_s(niz);// gets() ne deluje, ker je tretiran kot nevaren zaradi buffer overflow, in v C11 in dalje, ga nadomesti gets_s()
	Isci(niz, 3);
	abeceda(niz);
	bsort(niz);
	lookup(niz);





	return 0;
}

void Isci(char niz[], int zapbeseda)
{
	int stpresledkov = 0;
	char beseda[41];
	int j = 0;
	for (int i = 0; i < strlen(niz); i++)
	{
		if (niz[i] == ' ')
			stpresledkov++;

		if (stpresledkov == zapbeseda-1)
		{
			beseda[j] = niz[i+1];
			j++;
		}
	}
	beseda[j] = '\0';
	cout << zapbeseda << ". beseda je ";
	puts(beseda);
}


void abeceda(char niz[])
{
	bool najden = 0;
	for (int i = 0; i < strlen(niz) && !najden; i++)
		if (niz[i - 1] == ' ' && ((niz[i] == 'A' && niz[i + 1] == 'B') || (niz[i] == 'A' && niz[i + 1] == 'b') || (niz[i] == 'a' && niz[i + 1] == 'B') || (niz[i] == 'a' && niz[i + 1] == 'b')))
		{
			najden = 1;
			cout << "ta beseda se začne na mestu " << i << "\n";
		}
}

void bsort(char niz[])
{
	for (int i = 0; i < strlen(niz); i++)
		for (int j = 0; j < strlen(niz) - i - 1; j++)
			if (niz[j] < niz[j - 1])
			{
				int temp = niz[j - 1];
				niz[j - 1] = niz[j];
				niz[j] = temp;
			}

	puts(niz);
}

void lookup(char niz[])
{
	int max = strlen(niz), min = 0, mid;

	char iskani;
	cout << "vpišite iskani znak: ";
	cin >> iskani;

	do
	{
		mid = (max + min) / 2;
		if (niz[mid] == iskani)
			cout << "iskani je na mestu: " << mid+1<<"\n";
		if (iskani < niz[mid])
			max = mid - 1;
		if (iskani > niz[mid])
			min = mid + 1;
	} while (niz[mid] != iskani && min < max);
}
