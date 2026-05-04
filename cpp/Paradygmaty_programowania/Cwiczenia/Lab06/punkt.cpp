#include <iostream>
class punkt
{
    public:
        int x;
        int y;
        void wyswietl()
        {
            std::cout<<"Value of x: "<<x<<std::endl;
            std::cout<<"Value of y: "<<y;
        };
};

int main()
{
    punkt moj_punkt;
    moj_punkt.x =5;
    moj_punkt.y=10;
    moj_punkt.wyswietl();
    return 0;
}
