#include<iostream>
using namespace std;

int wrt=1;
int mutex=1;
int readcnt=0;
bool wait(int wrt){
    if(!wrt){
        return false;
    }
wrt=~wrt;
return true;
}

void signal(int wrt){
wrt=~wrt;
}

//writers code

do{
   if(wait(wrt)){

    //perform writing

    signal(wrt);
   }
}while(true);

//Readers process

do{
    wait(mutex);
    readcnt++;
    if(readcnt==1){
        wait(wrt);
    }

    signal(mutex);
     //perform reading
    wait(mutex);
    if(readcnt==0){
        wait(wrt);
    }
    readcnt--;

    signal(mutex);
}while(true);
int main(){
return 0;}
