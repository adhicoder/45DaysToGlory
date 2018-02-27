#include<bits/stdc++.h>
using namespace std;

int minDistance(vector<int> v, int C)
{
  std::vector<int> d;
  for (int i = 0; i < v.size(); i++)
  {
    d.push_back(v[i+1]-v[i]);
  }

  int l = std::min_element(vec.begin(), vec.end());
  int h = std::accumulate(vector.begin(), vector.end(), 0);

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
  cin>>t;
  while(t--)
  {
    cin>>N>>C;
    std::vector<int> v;
    std::vector<int> o;
    while(N--)
    {
      cin>>input;
      v.push_back(input)
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