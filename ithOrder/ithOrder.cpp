#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int pivot, int low, int high)
{
  int i=low-1;
  int j=low;
  int temp;
  while(j<high)
  {
    // cout<<j;
    if (j!= pivot && v[j] < v[pivot])
    {
      i++;
      std::iter_swap(v.begin()+low+j, v.begin()+low+i);
      // temp = v[j];
      // v[j] = v[++i];
      // v[i] = temp;
    }
    j++;
  }
  i++;
  std::iter_swap(v.begin()+low+pivot, v.begin()+low+i);
  // temp = v[pivot];
  // v[pivot] = v[++i];
  // v[i] = temp;
  return i;
}

int ithOrder(vector<int> &v, int n, int i)
{
  if (n == 1) 
    return v[0]; 
  else 
  {
    int pivot = rand()%v.size();
    // cout<<pivot<<" ";
    int p = partition(v, pivot, 0, v.size());
    if (p == i)
      return v[p];
    else if (p > i)
      {
        v.erase(v.begin()+p, v.end());
        return ithOrder(v, p-1, i);
      }
    else
      {
        v.erase(v.begin(), v.begin()+p);
        return ithOrder(v, n-p, i-p);
      }
  }
}

void quicksort(vector<int> &v, int low, int high)
{
  if (low < high) 
  {
    int pivot = high-1;
    int p = partition(v, pivot, low, high);
    cout<<"Partition for pivot "<<pivot<<" is "<<p<<"\n";
    quicksort(v, low, p);
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
  // cout<<partition(v, 1, 0, 2)<<"\n";
  cout<<"\nEnter the order i: ";
  cin>>i;
  cout<<"\nIth Order statistic is: "<<ithOrder(v, N, i-1)<<"\n";
}