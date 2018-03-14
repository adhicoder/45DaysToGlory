#include<bits/stdc++.h>
using namespace std;

int lastDigit(int a, unsigned long int b)
{
  int cycle = 0;
  int lastDigit = a%10;
  int powerMod = -1;
  int iterator = a;
  while(powerMod != lastDigit)
  {
    cycle++;
    iterator *= a;
    powerMod = iterator%10;
  }
  if (b==0)
	return 1;
  if (cycle == 1)
	return lastDigit;
  else if(b%cycle==0)
	return ((int)(pow(a, cycle))%10);
  else
	return ((int)(pow(a, b%cycle))%10);
}

int main()
{
  int t, a;
  unsigned long int b;
  cin>>t;
  while(t--)
  {
    cin>>a>>b;
    cout<<lastDigit(a, b)<<"\n";
  }
}