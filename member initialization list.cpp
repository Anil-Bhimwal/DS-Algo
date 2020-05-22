#include<iostream>
using namespace std;
#include "myclass.h"
myclass::myclass(int a,int b)
:regVar(a),constVar(b)
{
    cout<<regVar<<endl;
    cout<<constVar<<endl;

}

int main()
{
    myclass obj(11,22);
}
