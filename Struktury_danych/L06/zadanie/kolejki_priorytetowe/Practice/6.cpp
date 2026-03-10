#include <iostream>
#include <list>
int main()
{
    std::list<int>lista={1,1,1};
    //lista.resize(5); 
    //lista.assign({1,1,1,2,2,2}); 
    lista = {1,1,1,2,2,2};
    for(int x : lista)
    {
        std::cout << x << " ";
    }
    
    
  return 0;
}