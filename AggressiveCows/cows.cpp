#include<bits/stdc++.h>
using namespace std;
 
int minDistance(vector<int> v, int C)
{
  std::vector<int> d;
  for (int i = 0; i < v.size()-1; i++)
  {
    d.push_back(v[i+1]-v[i]);
  }
 
  int l = *std::min_element(d.begin(), d.end());
  int h = std::accumulate(d.begin(), d.end(), 0);
 
  while (l < h) 
  {
    int allowedNo = 1;
    int x = (h+l)/2;
    int distance = 0;
    for (int i=0; i<d.size(); i++)
    {
      if (distance + d[i] <= x)
        distance = distance + d[i];
      else 
      {
        allowedNo++;
        distance = 0;
      }
    }
    if (allowedNo >= C)
      l = x + 1;
    else
      h = x;
  }
  return l;
}
 
int main() 
{
  int t, N, C, input, output;
  std::vector<int> o;
  cin>>t;
  while(t--)
  {
    cin>>N>>C;
    std::vector<int> v;
    while(N--)
    {
      cin>>input;
      v.push_back(input);
    }
    sort(v.begin(), v.end());
    output = minDistance(v, C);
    o.push_back(output);
  }
  for (int i=0; i<o.size(); i++) 
  {
    cout<<o[i]<<"\n";
  }
}