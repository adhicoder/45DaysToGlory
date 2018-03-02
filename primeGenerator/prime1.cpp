#include<bits/stdc++.h>
using namespace std;

void calculatePrimes(vector<unsigned int> &v, unsigned int m)
{
  v.push_back(2);
  unsigned int i = 3, j = 0;
  bool f;
  for (; i<=m; i++)
  {
    f = true;
    for(j=0; v[j] <= sqrt(i); j++)
    {
      if (i%v[j] == 0)
        {
          f = false;
          break;
        }
    }
    if(f)
      v.push_back(i);
  }
}

void limitPrimes(vector<unsigned int> &v, unsigned int m, unsigned int n)
{
  for(unsigned int i = 0; i<v.size(); i++)
  {
    if (v[i]>=m && v[i]<=n)
      cout<<v[i]<<"\n";
    else if (v[i]>n)
      break;
  }
  cout<<"\n";
}

void calculateLargePrimes(vector<unsigned int> &v, unsigned int m, unsigned int n)
{
  unsigned int i, j;
  bool f;
  for(i=m; i<=n; i++)
  {
    f = true;
    for(j=0; v[j]<=sqrt(i); j++)
    {
      if (i%v[j] == 0)
      {
        f = false;
        break;
      }
    }
    if (f && i!=1)
      cout<<i<<"\n";
  }
}

int main()
{
  std::vector<unsigned int> v;
  calculatePrimes(v, 31700);
  unsigned int T, m, n;
  cin>>T;
  while(T--)
  {
    cin>>m>>n;
    calculateLargePrimes(v, m, n);
    cout<<"\n";
  }
}