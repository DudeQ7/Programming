#include <iostream>
using namespace std; // bo std to sie dostaje jak uzywasz tego gowna
int main(int argc,char*argv[])
{
    for(int i = 1; i<argc; i++)
        cout << i << "argument to "<< argv[i] << endl;
    system("pause");
    return 0;
}