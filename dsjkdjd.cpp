
#include <iostream>

using namespace std;
int bestfitvary(int);
int worstfitvary(int);
int bestfitfixed(int);
int worstfitfixed(int);
int blocks[5]={100,400,200,300,900};
int main()
{


        //
        int process[5]={210,417,312,817,544};
        //

        for(int i=0;i<4;++i)
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


int bestfitvary(int process)
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
        blocks[minblock]=blocks[minblock]-process;

    }

    return minblock;

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


int worstfitvary(int process)
{


    int maxblock=-1;
    int maxremain=0;

     for(int i=0;i<5;++i)
    {
            if(process<=blocks[i]&&maxremain<(blocks[i]-process))
            {
                maxblock=i;
                maxremain=blocks[i]-process;
            }
    }
    //



    if(maxblock!=-1)
    {
        blocks[maxblock]=blocks[maxblock]-process;

    }

    return maxblock;






}
int worstfitfixed(int process)
{


    int maxblock=-1;
    int maxremain=0;

     for(int i=0;i<5;++i)
    {
            if(process<=blocks[i]&&maxremain<(blocks[i]-process))
            {
                maxblock=i;
                maxremain=blocks[i]-process;
            }
    }
    //



    if(maxblock!=-1)
    {
        blocks[maxblock]=0;

    }

    return maxblock;






}
