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
	//txt bêdzie w formacie csv ³atwy w konwersji do excel do wykresów.
	dane.close();
}

void brute_force(int tablica[], int rozmiar)
{
}

void bucket_sort(int tablica[], int rozmiar)
{
}
