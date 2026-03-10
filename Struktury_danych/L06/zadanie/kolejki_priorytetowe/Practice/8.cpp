#include <iostream>
#include <deque>
int main()
{
    std::deque<int>dwa;
    std::deque<int>::reverse_iterator rit;
    for(int i=2; i<=7; i=i+2)
    dwa.push_back(i);
    rit=dwa.rbegin();
    std::cout<<*rit;
    return 0;
}