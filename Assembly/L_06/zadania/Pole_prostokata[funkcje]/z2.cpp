#include <iostream>
//pole prostokata o bokach A i B 
int a, b, pole;
extern "C" int iloczyn(int a,int b);

int main()
{
	std::cout << "Podaj wartosc boku A prostokata: ";
	std::cin >> a;
	std::cout << "Podaj wartosc boku B prostokata: ";
	std::cin >> b;
	int pole = iloczyn(a, b);
	std::cout << "Pole prostokata jest rowne: " << pole;
	return 0;
}