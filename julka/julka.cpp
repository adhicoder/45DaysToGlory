#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
namespace mp = boost::multiprecision;

int main()
{
  mp::cpp_int a, b;
  int t=10;
  while(t--){
		cin>>a>>b;
    cout<<(a+b)/2<<"\n";
    cout<<(a-b)/2<<"\n";
	}
}