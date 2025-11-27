#include<iostream>
#include <string>
 int rozmiar = 150;
char dzien=0;
int rok =0,ile_rok=0;
int u_input,poczatkowy_numer = 0,indeks=0,indeks_plus=0;  // deklaracja liczb na pesel
std::string tab[150]={"53082806059","10292395111","85111779283","86080941169","89011129700","10312354816","62092569090","03231851995","88120262427","07222118171","74121108598","67112966668","89010737704","52101156863","91032272651","75032006098","55110906690","67103111042","77072919805","92022716243","83041812338","86072032543","71110410883","73070871368","74040249598","85052135674","70053179170","89021468413","64040919575","66100294134","63102092944","89040205480","74123184206","02221524198","70032057433","89081421445","66113183995","00271228512","78103188695","88080601948","71093058856","64022301455","65102086116","68112117597","70101195486","77111084850","78123189018","79110673709","74120284541","00260911665","86070630583","63122755182","90112004373","54043010088","01211235469","84051294894","00261521669","71112677514","89040633348","90053120136","75123199317","73112328551","85031079443","85052568643","55022153432","83041947282","86081443325","59110570565","66063014631","67120749923","89081519801","70120794633","76121186303","72031096705","61100157652","79012564484","88111094545","89040876453","89120952161","59083036077","61121020469","89040185241","88080416256","61032479116","54020837137","87072724289","88103032931","59042989686","91023191330","59031152059","84112185145","60102890107","84050694367","89041133472","82072219267","57102202414","55123128973","86070511185","81101148770","87071164662","51011153311","89052085069","50102636355","10292395111","53122299121","75113162747","89102588171","89022379914","09211585933","50101111305","89042620494","51102573842","89021697637","63092608644","78102945963","86061995325","78011115028","89042750933","89112466825","89020265394","66100651663","65062892381","69030626134","67113048790","84051840149","57073163051","81081010863","89062644823","52110446139","50021011352","65092056892","85052605175","89032143350","71123061643","73103000844","89012630357","73010399576","87070895372","60061144469","76043169949","79101146737","76043054555","89082608599","76122752028","77120835871","89010293604","89091482250","58122188027","89052295172","79070627831"};
void ile()
{
    //liczba osob z danego roku lub mlodszych  
    //cyferka numer 1-2
    indeks = 0;
    indeks_plus =1;
    for(int i =0; i<rozmiar; i++)
    {
        if((tab[i].find(indeks))==rok) //or nie dzialal
        {
            std::cout<<"Indeks o numerze: "<<i<<"jest z roku: "<<rok;
            ile_rok++;
        }
        else if((tab[i].find(indeks_plus))==rok)
         {
            std::cout<<"Indeks o numerze: "<<i<<"jest z roku: "<<rok;
            ile_rok++;
        }
        else
        {
            std::cout<<"Indeks o numerze: "<<i<<" nie jest z roku: "<<rok<<std::endl;

        }
    }
}
/*
bool sprawdz(int tab[rozmiar])
{
    for(int i=0; i<rozmiar; i++)
    {

    }
}
*/
// void dzien(int tab[rozmiar])
// {//dzien to jest cyferka od 5 do 6 
//      for(int i=0; i<rozmiar; i++)
//     {   
//         char c = tab[5];
//         for(char c:tab[i])
//         {

//         }
//     }
// }
int main()
{
    std::cout<<"Menu: \n 1.Sprawdz pesel \n 2.Suma \n 3.Dzien \n 4. ile kobiet || ile mezczyzn \n 5.ile osob urodzonych w danym roku lub mlodszych\n Twoj wybor:  ";
std::cin>>u_input;
switch (u_input)
{
case 1:
    std::cout<<"Wybrales opcje numer1: "<<std::endl; 
    break;
case 2:
    std::cout<<"Wybrales opcje numer2: "<<std::endl; 
    break;
case 3:
    std::cout<<"Wybrales opcje numer3: "<<std::endl; 
    std::cout<<"Jaki dzien chcesz sprawdzic(forma 1-31)";
    std::cin>>dzien;
    indeks =5;
    int ilosc_osob;
    int match,not_match;
    for(int i=0; i<rozmiar; i++)
    {
        ilosc_osob =0;
        match =0;
        not_match =0;
      if((tab[i].find(indeks,6)==dzien))
      {
        std::cout<<"Indeks o numerze: "<<i<<" jest matchem"<<std::endl;
        ilosc_osob ++; //zwiekszamy ilosc osob jesli znalezlezlismy match 
        match++;
       }
       else
       {
        std::cout<<"Indeks o numerze: "<<i<<" nie jest matchem"<<std::endl;
        not_match++;
       }
       i++; //przejscie do kolejnej osoby
    }
    std::cout<<"\nJest tyle osob z tego dnia: "<<match;
    break;
case 4:
    std::cout<<"Wybrales opcje numer4: "<<std::endl; 
    break;
case 5:
    std::cout<<"Wybrales opcje numer5: "<<std::endl;
    std::cout<<"Ktory rok chcesz sprawdzic(podaj w formacie 25 lub 5): ";
    std::cin>>rok; 
    ile();
    break;

default:
    std::cout<<"Podales liczbe spoza zakresu";
    break;
}
return 0;
};
