#include <iostream>
#include <queue>
int main()
{
    std::string s1 = "1a2b3c4d";
    int a=0;
    for(char c: s1) {
        if(c-'0' <= 9 && c-'0' >=0) {
            a++;
        }
    }
    std::cout << a;
return 0;
}