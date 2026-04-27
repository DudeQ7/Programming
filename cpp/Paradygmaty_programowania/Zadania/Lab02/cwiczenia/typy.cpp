#include <iostream>
#include <typeinfo>
/*
Uwzględnij co najmniej: 
short, unsigned short, int, unsigned int, long, long long, float, double, long double. 
Porównaj wyniki na różnych kompilatorach lub systemach. Kiedy wyniki są inne ?
*/
std::string ladna_nazwa(const char* kod) {  
    std::string s = kod;  
    if (s == "i") return "int";  
    if (s == "s") return "short";  
    if (s == "t") return "unsigned short";  
    if (s == "j") return "unsigned int";  
    if (s == "l") return "long";  
    if (s == "x") return "long long";  
    if (s == "f") return "float";  
    if (s == "d") return "double";  
    if (s == "e") return "long double";  
    return s; 
}
int moja_zmienna=0;

int main()
{
    std::cout<<"Nazwa typu: "<<ladna_nazwa(typeid(moja_zmienna).name())<<std::endl;
    std::cout<<"Rozmiar w bajtach typu: "<<std::endl;
    std::cout<<"Czy typ jest ze znakiem:"<<std::endl;   
    std::cout<<"Wartosc minimalna typu: "<<std::endl;      
    std::cout<<"Wartosc maksymalna typu:"<<std::endl;         
    return 0;
}