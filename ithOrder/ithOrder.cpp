#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int low, int high)
{
  int pivot = v[high];
  int i=low-1;
  int j=low;
  while(j<high)
  {
    if (v[j] <= pivot)
    {
      i++;
      std::swap(v[j], v[i]);
    }
    j++;
  }
  i++;
  std::swap(v[high], v[i]);
  return i;
}

int ithOrder(vector<int> &v, int l, int h, int i)
{
  if (i>0 && i<=h-l+1)
  {
    int p = partition(v, l, h);
    if (p-l == i-1)
      return v[p];
    else if (p-l > i-1)
      return ithOrder(v, l, p-1, i);
    else     
    return ithOrder(v, p+1, h, i-p+l-1);
  }
  return -1;
}

void quicksort(vector<int> &v, int low, int high)
{
  if (low < high) 
  {
    int p = partition(v, low, high);
    cout<<p<<"\n";
    quicksort(v, low, p-1);
    quicksort(v, p+1, high);
  }
}

int main()
{
  int N, i, input;
  std::vector<int> v;
  cout<<"Enter the number of elements in the array: ";
  cin>>N;
  cout<<"\nEnter the elements: ";
  for(i=0; i<N; i++)
  {
    cin>>input;
    v.push_back(input);
  }
  cout<<"\nEnter the order i: ";
  cin>>i;
  cout<<"\nIth Order statistic is: "<<ithOrder(v, 0, N-1, i)<<"\n";
}