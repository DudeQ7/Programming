#include <chrono>
#include <iostream>
using namespace std::chrono;
/*
Do oddania - kody funkcji (tak dla sprawdzenia czy są ok) i sprawozdanie pod nazwą nazwisko.docx
*/
unsigned long long silnia_iter(unsigned int n )
{
    unsigned long long wynik = 1;
    for (unsigned int i = 2; i <= n; i++)
    {
        wynik *= i;
    }
    return wynik;
}
unsigned long long silnia_rek(unsigned int n)
{
    if (n<=1)
        return 1;
    return n * silnia_rek(n - 1);
}
unsigned int suma_iter(unsigned int n)
{
    unsigned int s = 0;
   while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}
unsigned int suma_rek(unsigned int n)
{
    if (n == 0)
        return 0;
    return (n % 10) + suma_rek(n / 10);
}
unsigned long long fibon_iter(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    unsigned long long a = 0, b = 1, c;
    for (unsigned int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
unsigned long long fibon_rek(unsigned int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibon_rek(n - 1) + fibon_rek(n - 2);
}

template<typename Func>
long long mierz(Func f, unsigned int n, unsigned int powtorzenia = 100000)
{
    auto start = high_resolution_clock::now();
    for (unsigned int i = 0; i < powtorzenia; i++)
    {
        f(n);
    }
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}
int main()
{
    int wartosci_n[]= {1,2,3,4,5,8,10,12,15,18,20};
    std::cout<<"n\t|\tSilnia Iter\t|\tSilnia Rek\t|\tSuma Iter\t|\tSuma Rek\t|\tFibon Iter\n";
    std::cout<<std::string(75,'-')<<std::endl;
    for(int n : wartosci_n)
    {
        long long si = mierz(silnia_iter, n);  
        long long sr = mierz(silnia_rek, n);  
        long long sui = mierz(suma_iter, n);  
        long long sur = mierz(suma_rek, n);  
        long long fi = mierz(fibon_iter, n);  
        long long fr = mierz(fibon_rek, n, n <= 30 ? 100000 : 100); // rek fib bardzo wolny!  
        std::cout << n << "\t| " << si << " us\t| " << sr << " us\t| " << sui << " us\t| " << sur << " us\t| " << fi << " us\t| " << fr << " us\n";
    }
    return 0;
}
