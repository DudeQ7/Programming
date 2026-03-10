#include <iostream> 
#include <stack>
int main()
{
   std::stack <int> stos;
   stos.push(1);
   stos.push(2);
   stos.push(3);
   stos.top()=10;
   for(int i=0; i<3; i++)
   {
    std::cout<<stos.top()<<" ";
    stos.pop();
   }
}