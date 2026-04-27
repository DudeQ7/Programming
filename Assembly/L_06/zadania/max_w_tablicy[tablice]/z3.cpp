#include <iostream>
extern "C" int max(int*arr,int size);
int main()
{
	int tablica[] = { 1,3,4,6,8,4,9 };
	int N = 7; //liczba elementow tablicy 
	int liczba = max(tablica, N); //koncowy max
	int aktualny_max = tablica[0];
	for (int i = 0; i < N; i++)
	{
		if (tablica[i] > aktualny_max)
		{
			aktualny_max = tablica[i]; // warunek potrzebny do realizacji funkcji aktualny max to
		}
		std::cout << "Liczba nr: " << i << " to: " << tablica[i] << " aktualny max to: " << aktualny_max << std::endl;
	}
	std::cout <<std::endl<< "Wynik koncowy: Najwiekszy elemenent to: " << liczba << std::endl;
	return 0;
}
