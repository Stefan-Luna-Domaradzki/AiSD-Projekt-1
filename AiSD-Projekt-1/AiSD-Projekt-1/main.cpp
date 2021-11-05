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

void wypelnij(int tablica[], int rozmiar);
void wypisz(int tablica[], int rozmiar, double czas, string algorytm);


void brute_force(int tablica[], int rozmiar);
void bucket_sort(int tablica[], int rozmiar);

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

void wypelnij(int tablica[], int rozmiar)
{
	srand(time(NULL));
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = rand()% rozmiar + 1;
	}
}

void wypisz(int tablica[], int rozmiar, double czas, string algorytm)
{
	for (int i = 0; i < rozmiar; i++)
	{
		cout << tablica[i] << setw(5);
	}

	ofstream dane;
	dane.open("dane.txt", ios::app);
	dane << algorytm << ", " << rozmiar << "," << czas << endl;
	//txt b�dzie w formacie csv �atwy w konwersji do excel do wykres�w.
	dane.close();
}

void brute_force(int tablica[], int rozmiar)
{
}

void bucket_sort(int tablica[], int rozmiar)
{
}
