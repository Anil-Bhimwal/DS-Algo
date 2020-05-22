#include <iostream>
using namespace std;

void fun()
{
  static int i = 10;
  i++;
  cout << i;
}

int main()
{
 // cout<<sizeof(long float)<<endl;
  cout<<sizeof(double)<<endl;
  cout<<sizeof(float)<<endl;
  return 0;
}

