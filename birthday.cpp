#include<iostream>
using namespace std;
class birthday{
public:
    birthday(int m,int d,int y)
    :month(m),date(d),year(y)
    {

    }
    void printdate()
    {
        cout<<month<<" "<<date<<" "<<year<<endl;
    }
private:
    int month,date,year;

    };

    class person{
public:
    person(string n,birthday b)
    :name(n),bd(b)
    {

    }
    void printinfo()
    {
        cout<<name<<endl;
        bd.printdate();
    }
private:
    string name;
    birthday bd;
    };
    int main()
    {
        birthday bd(10,07,1999);
        person p("anil bhimwal",bd);
        p.printinfo();
    }
