#include<bits/stdc++.h>
using namespace std;

int swapNumber (unsigned int D, vector<int> v, std::string sequence)
{
  int cCount = 0, swapCount=0, size;
  unsigned int power;
  for(int i=0; i<sequence.length(); i++)
  {
    if(sequence[i] == 'S')
      v.push_back(cCount);
    else cCount++;
  }
  size = v.size();
  if(size > D)
    return -1;
  else {
    while(true)
    {
      std::sort(v.begin(), v.end());
      power = 0;
      for(int i=0; i<size; i++)
      {
        power+=pow(2, v[i]);
      }
      if (power <= D) break;
      v[size-1] -= 1;
      swapCount++;
    }
  }
  return swapCount;
}

int main()
{
  std::string sequence;
  vector<int> v;
  unsigned int D;
  int t, swaps, count=0;
  cin>>t;
  while(t--)
  {
    count++;
    cin>>D>>sequence;
    swaps = swapNumber(D, v, sequence);
    cout<<"Case #"<<count<<": ";
    if(swaps == -1) cout<<"IMPOSSIBLE";
    else cout<<swaps;
    cout<<"\n";
    v.clear();
  }
}