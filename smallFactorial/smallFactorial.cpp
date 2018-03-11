#include<bits/stdc++.h>
using namespace std;

vector<int> multiply(vector<int> A, int B)
{
  vector<int> product, sumArray;
  vector<int> multiplicand1 = A;
  vector<int> multiplicand2 = A;
  int units = B%10;
  int tens = B/10;
  int carry = 0;
  int temp = 0;
  multiplicand1.push_back(0);
  for (int i = multiplicand1.size()-1, j=multiplicand2.size()-1; i > -1; i--, j--)
  {
    if (j >= 0) 
      temp = multiplicand1[i]*tens + multiplicand2[j]*units + carry;
    else
      temp = multiplicand1[i]*tens + carry;
    sumArray.insert(sumArray.begin(),1, temp%10);
    carry = temp/10;
  }
  if (carry != 0)
    sumArray.insert(sumArray.begin(),1, carry);
  return sumArray;
}

std::string operator+(std::string &a, int b)
{
  std::ostringstream oss;
  oss << a << b;
  return oss.str();
}

string convertToString(vector<int> x)
{
  string s = "";
  for (int i = 0; i < x.size(); i++)
    s = s + x[i];
  return s;
}

string smallFactorial(int n)
{
  int tens = n/10;
  int units = n%10;
  int flag = 0;
  std::vector<int> factorial, smallFactorial;
  factorial.push_back(tens);
  factorial.push_back(units);
  for (int i = n-1; i > 1; i--)
    factorial = multiply(factorial, i);
  //This segment is to remove the leading zeroes in the answer
  for (int i = 0; i < factorial.size(); i++)
  {
    if (flag == 0 && factorial[i] != 0)
      flag = 1;
    if (flag == 1)
      smallFactorial.push_back(factorial[i]);
  }
  return convertToString(smallFactorial);
}

int main()
{
  int t, n;
  cin>>t;
  while(t--)
  {
    cin>>n;
    cout<<smallFactorial(n)<<"\n";
  }
}