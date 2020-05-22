
#include <iostream>

using namespace std;
int bestfitvary(int);
int worstfitvary(int);
int bestfitfixed(int);
int worstfitfixed(int);
int blocks[5]={100,300,200,400,500};
int main()
{


        //
        int process[5]={90,104,30,390,100};
        //

        for(int i=0;i<5;++i)
       {
        int blockassigned=worstfitvary(process[i]);

        if(blockassigned==-1)
        {
            cout<<"Block not assigned"<<endl;
        }
        else
        {
            cout<<"Block assigned:"<<blockassigned+1<<endl;
        }

       }

        return 0;
}



int bestfitfixed(int process)
{


    int minblock=-1;
    int minremain=10000;

    for(int i=0;i<5;++i)
    {
            if(process<=blocks[i]&&minremain>(blocks[i]-process))
            {
                minblock=i;
                minremain=blocks[i]-process;
            }
    }
    //



    if(minblock!=-1)
    {
        blocks[minblock]=0;

    }

    return minblock;

}


