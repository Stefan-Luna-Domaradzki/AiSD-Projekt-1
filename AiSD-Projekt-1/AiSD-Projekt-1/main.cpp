// Projekt na "Algorytmy i Struktury Danych" 
// 166642 Stefan Domaradzki 
// Temat: Dla zadanej tablicy liczb ca³kowitych o rozmiarze n zawieraj¹cej wartoœæi z przedzia³u [1,n]
//		  znajdŸ element powtarzaj¹cy siê.

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
	//jakiœ sort
	//czy inny algorytm
	stop = clock();
	double czas = (stop - start) / CLOCKS_PER_SEC;

	wypisz(tablica, rozmiar,czas, "brak");

	cout << endl << "Algorytm zaj¹³: " << czas;
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
	//txt bêdzie w formacie csv ³atwy w konwersji do excel do wykresów.
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
				cout << "liczba która sie powtarza to: " << szukaj << ". \n";
				break;
			}
			
		}

	}
}

void bucket_sort(int tab[], int rozmiar)
{
	//z za³o¿enia ¿e liczby s¹ z przedzia³u 1 do n (rozmiar) 
	//tablica wymagana do sortowania kube³kowego powinna byæ rozmiaru n
	//pozycja zerowa nowej tablicy zawsze pozostanie pusta i bêdzie ignorowana

	int* buckets = new int[rozmiar + 1];
	buckets = { 0 };

	for (int i = 0; i < rozmiar; i++)
	{
		buckets[tab[i]]++;

		if (buckets[tab[i]] = 2) 
		{
			cout << "liczba która sie powtarza to: " << tab[i] << ". \n";
			break;
		}

	}


}
