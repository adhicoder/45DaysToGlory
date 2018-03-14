#include<bits/stdc++.h>
using namespace std;

unsigned long int maxMoney(unsigned long int a, std::map<unsigned long int, unsigned long int> array)
{
  if (array[a]!=0)
    return array[a];
  if (a == 1)
    {
      array[a] = 1;
      return 1;
    }
  if (a == 0)
  {
    array[a] = 0;
    return 0;
  }
  else
    {
      unsigned long int split = max(maxMoney(a/2, array) + maxMoney(a/3, array) + maxMoney(a/4, array), a);
      array[a] = split;
      return split;
    }  
}

int main()
{
  unsigned long int x = 0;
  std::map<unsigned long int, unsigned long int> array;
  while(cin>>x)
  {
    cout<<maxMoney(x, array);
  }
}