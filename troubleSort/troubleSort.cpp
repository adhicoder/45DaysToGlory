#include<bits/stdc++.h>
using namespace std;

int troubleSort(vector<unsigned int> v, vector<unsigned int> thread1, vector<unsigned int> thread2)
{
  unsigned int flag = 4000000000;
  for(unsigned int i=0; i<v.size(); i++)
  {
    if(!(i%2)) thread1.push_back(v[i]);
    else thread2.push_back(v[i]);
  }
  std::sort(thread1.begin(), thread1.end());
  std::sort(thread2.begin(), thread2.end());
  for(unsigned int i=0; i<thread2.size(); i++)
  {
    if (thread1[i] > thread2[i])
    {
      flag = 2*i;
      break;
    } else if (i+1<thread1.size() && thread1[i+1] < thread2[i])
    {
      flag = 2*i + 1;
      break;   
    }
  }
  thread1.clear();
  thread2.clear();
  return flag;
}

int main()
{
  std::vector<unsigned int> v, thread1, thread2;
  int t, count=0;
  unsigned int N, flag, num, i;
  cin>>t;
  while(t--)
  {
    count++;
    cin>>N;
    for(i=0; i<N; i++)
    {
      cin>>num;
      v.push_back(num);
    }
    flag = troubleSort(v, thread1, thread2);
    v.clear();
    cout<<"Case #"<<count<<": ";
    if (flag == 4000000000)
      cout<<"OK"<<"\n";
    else
      cout<<flag<<"\n";
  }
}