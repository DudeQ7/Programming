#include <iostream> 
#include <queue>
std::queue <int> nr_klienta;
int nr_zgloszenia = 0;
std::string u_input;
int main()
{
    while (u_input!="obsluz")
    {
        for(int i=0; i<150; i++)
        {
            std::cout<<"Zgloszenie: "<<i<<" dodane";
            nr_klienta.push(i);
            i++;
        }
        std::cout<<"Czy zgloszenie zostalo obsluzone? ";
        
    }
    
    return 0;
}