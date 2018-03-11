#include<bits/stdc++.h>
using namespace std;

int numberSteps(int x, int y)
{
  int sum = x+y;
  if (x == y)
  {
    if(sum % 4 == 0)
      return sum;
    else 
      return sum-1; 
  } 
  else if (x == y + 2)
  {
    if(sum % 4 == 2)
      return sum;
    else 
      return sum-1;
  }
  else return -1;
}

int main()
{
  int t, x, y, num;
  cin>>t;
  while(t--)
  {
    cin>>x>>y;
    num = numberSteps(x, y);
    if (num == -1)
      cout<<"No Number";
    else
      cout<<num;
    cout<<"\n";
  }
}