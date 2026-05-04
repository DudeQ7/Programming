#include <iostream>
class device
{
private:
    /* data */
public:
    std::string name;
    std::string serial_number;
};
class Laptop: public device
{
    public:
        std::string RAM_memory;
        std::string OS;
};
class Smartphone: public device
{
    public:
        std::string Playstore_version;
};
//This method needs to be modified in order to be inherited by the derived classes, otherwise it will be hidden and not accessible from the derived classes.
//Correction #1
//nevermind everything is correct 
void showinfo(const device& di )
{
    device d = di; 
    d.name = "Laptop";
    d.serial_number = "12459069PL";
    std::cout<<"Nazwa urzadzenia: "<<d.name<<std::endl;
    std::cout<<"Numer seryjny: "<<d.serial_number<<std::endl;
}
int main()
{
    
    showinfo(device());
    return 0;
}