#include <iostream>
#include <limits>
#include <iomanip>
#include <type_traits>
#include <climits>
/*
używając biblioteki limits i polecenia numeric_limits napisz program limity.cpp, 
 w którym użytkownik wybiera typ danych (minimum 10) a program wyświetli: 
- minimalną wartość jaką może przyjąć zmienna tego typu, 
- maksymalną wartość jaką może przyjąć zmienna tego typu, 
- czy ten typ obsługuje znak minus, 
- ile bitów jest przeznaczone dla tego typu.
*/
template<typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type
print_limits(const char* name)
{
    std::cout<<name <<":\n";
    if(std::numeric_limits<T>::is_signed)
    {
        std::cout<<"min  ="<<static_cast<long long>(std::numeric_limits<T>::min())<<"\n";
        std::cout<<"max  ="<<static_cast<long long>(std::numeric_limits<T>::max())<<"\n";
    }
    else
    {
        std::cout<<"min  ="<<static_cast<unsigned long>(std::numeric_limits<T>::min())<<"\n";
        std::cout<<"max  ="<<static_cast<unsigned long>(std::numeric_limits<T>::max())<<"\n";
    }
    std::cout<<"is signed: "<<std::boolalpha<<std::numeric_limits<T>::is_signed<<"\n";
    std::cout<<"bits: "<<sizeof(T) * CHAR_BIT <<"\n\n";
}
template<typename T>
typename std::enable_if<std::is_floating_point<T>::value,void>::type
print_limits(const char* name)
{
    std::cout<<name <<":\n";
    std::cout<<std::setprecision(10);
    std::cout<<"min(lowest): "<<std::numeric_limits<T>::lowest()<<"\n";
    std::cout<<"max: "<<std::numeric_limits<T>::max()<<"\n";
    std::cout<<"is_signed: "<<std::boolalpha<<std::numeric_limits<T>::is_signed<<"\n";
    std::cout<<"bits: "<<sizeof(T) *CHAR_BIT <<"\n\n";
}
int main()
{
    int choice =0;
    std::cout<<"Wybierz typ danych(podaj numer): ";
    std::cout<<"1.bool,\n2.short\n3.unsigned short\n4.int\n5.unsigned int\n6.long\n7.long long\n8.float\n9.double\n10.long double\nTwoj wybor: ";
    std::cin>>choice;
    switch(choice)
    {
        case 1:
            print_limits<bool>("bool");
            break;
        case 2:
            print_limits<short>("short");
            break;
        case 3:
            print_limits<unsigned short>("unsigned short");
            break;
        case 4:
            print_limits<int>("int");
            break;
        case 5:
            print_limits<unsigned int>("unsigned int");
            break;
        case 6:
            print_limits<long>("long");
            break;
        case 7:
            print_limits<long long>("long long");
            break;
        case 8:
            print_limits<float>("float");
            break;
        case 9:
            print_limits<double>("double");
            break;
        case 10:
            print_limits<long double>("long double");
            break;
        default:
            std::cout<<"Podales liczbe spoza zakresu!";
            break;
    }
    return 0;
}