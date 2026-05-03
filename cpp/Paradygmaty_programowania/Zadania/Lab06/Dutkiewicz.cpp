#include <iostream>
#include <vector>
/*
Kod (projekt) w pliku tekstowym + sprawozdanie.
• Kod i sprawozdanie proszę nazwać swoim nazwiskiem.
• Prześlij pliki w niespakowanej formie.
*/
class cards{
    private:
        std::string name;
        std::string type;
        int price;
        bool isavailable;
    public:
        cards(std::string n,std::string t,int c)
        {
            name = n;
            type = t;
            price = c;
            isavailable = true;
        }
    void buy()
    {
        if(isavailable)
        {
            isavailable = false;
            std::cout<<"Kupiles: "<<name<<" za "<<price<<" PLN"<<std::endl;
        }
        else
        {
            std::cout<<"Niestety "<<name<<" jest niedostepna."<<std::endl;
        }
    }
    void show()
    {
        std::cout<<name<<" | Typ: "<<type<<" | Cena: "<<price<<" PLN | Dostepnosc: "<<(isavailable ? "Dostepna" : "Niedostepna")<<std::endl;
    }
    bool isAvailable()
    {
        return isavailable;
    }
};
class client
{
    private: 
        std::string name;
    public:
        client(std::string i)
        {
            name = i;
        }
        void show()
        {
            std::cout<<"Klient: "<<name<<std::endl;
        }
};
class shop
{
    private:
        std::vector<cards> card; 
        std::vector<client> clients;
    public:
        void addCard(cards c)
        {
            card.push_back(c);
        }    
        void addClient(client cl)
        {
            clients.push_back(cl);
        }
        void showCards()
        {
            std::cout<<"Lista kart: "<<std::endl;
            for(int i=0;i<card.size();i++)
            {
                std::cout<<i<<": "; 
                card[i].show();
            }
        }
        void buycard(int index)
        {
            if(index>=0 && index<card.size())
            {
                card[index].buy();
            }
            else
            {
                std::cout<<"Nieprawidlowy indeks karty."<<std::endl;
            }
        }
};
int main()
{
    std::cout<<"Witaj w moim sklepie z kartami Pokemon!"<<std::endl;
    shop myshop;
    myshop.addCard(cards("Eevee","Normalny",10));
    myshop.addCard(cards("Pikachu","Elektryczny",20));
    myshop.addCard(cards("Charizard","Ognisty/Latajacy",50));
    myshop.addClient(client("Jan Kowalski"));\
    myshop.showCards(); 
    std::cout<<"Zakup: "<<std::endl;
    myshop.buycard(0);
    myshop.buycard(1);
    myshop.buycard(2);
    std::cout<<"Stan po zakupie: "<<std::endl;
    myshop.showCards();
    return 0;
}