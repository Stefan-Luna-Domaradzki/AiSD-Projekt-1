// Projekt na "Algorytmy i Struktury Danych" 
// 166642 Stefan Domaradzki 
// Temat: Dla zadanej tablicy liczb ca�kowitych o rozmiarze n zawieraj�cej warto��i z przedzia�u [1,n]
//		  znajd� element powtarzaj�cy si�.

#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iomanip>

using namespace std;

void wypelnij(int tab[], int rozmiar);
void wypisz(int tab[], int rozmiar, double czas, string algorytm);


void brute_force(int tab[], int rozmiar);
void bucket_sort(int tab[], int rozmiar);

int main(){
	
	int rozmiar;
	int *tablica;
	clock_t start, stop;

	cout << "Podaj rozmiar tablicy: "; cin >> rozmiar;
	tablica = new int [rozmiar];
	
	wypelnij(tablica, rozmiar);
	

	start = clock();
	//jaki� sort
	//czy inny algorytm
	stop = clock();
	double czas = (stop - start) / CLOCKS_PER_SEC;

	wypisz(tablica, rozmiar,czas, "brak");

	cout << endl << "Algorytm zaj��: " << czas;
    cout << "s. Przy rozmiarze tablicy: " << rozmiar << "." << endl;


	system("Pause");
	return 0;

 

}

void wypelnij(int tab[], int rozmiar)
{
	srand(time(NULL));
	for (int i = 0; i < rozmiar; i++)
	{
		tab[i] = rand()% rozmiar + 1;
	}
}

void wypisz(int tab[], int rozmiar, double czas, string algorytm)
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tab[i] << setw(5);
	}

	ofstream dane;
	dane.open("dane.txt", ios::app);
	dane << algorytm << ", " << rozmiar << "," << czas << endl;
	//txt b�dzie w formacie csv �atwy w konwersji do excel do wykres�w.
	dane.close();
}

void brute_force(int tab[], int rozmiar)
{
	int szukaj;
	int porownaj;

	for (int i = 0; i < rozmiar; i++)
	{
		szukaj = tab[i];
		porownaj = 0;

		for (int j = 0; j < rozmiar; j++)
		{
			if (tab[j] == szukaj) porownaj++;

			if (porownaj == 2)
			{
				cout << "liczba kt�ra sie powtarza to: " << szukaj << ". \n";
				break;
			}
			
		}

	}
}

void bucket_sort(int tab[], int rozmiar)
{
	//z za�o�enia �e liczby s� z przedzia�u 1 do n (rozmiar) 
	//tablica wymagana do sortowania kube�kowego powinna by� rozmiaru n
	//pozycja zerowa nowej tablicy zawsze pozostanie pusta i b�dzie ignorowana

	int* buckets = new int[rozmiar + 1];
	buckets = { 0 };

	for (int i = 0; i < rozmiar; i++)
	{
		buckets[tab[i]]++;

		if (buckets[tab[i]] = 2) 
		{
			cout << "liczba kt�ra sie powtarza to: " << tab[i] << ". \n";
			break;
		}

	}


}
