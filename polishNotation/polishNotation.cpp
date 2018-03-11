#include<bits/stdc++.h>
using namespace std;

string polishConvert(string input)
{
  string output = "";
  stack<char> symbols;
  for(int i = 0; i < input.size(); i++)
  {
    if (!(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '(' || input[i] == ')'))
      output.push_back(input[i]);
    else if (input[i] == '(')
      symbols.push(input[i]);
    else if (input[i] == ')')
    {
      while(symbols.top() != '(')
      {
        output.push_back(symbols.top());
        symbols.pop();
      }
      symbols.pop();
    }
    else 
    {
      symbols.push(input[i]);
    }
  }
  return output;
}

int main()
{
  string input, output;
  int t;
  cin>>t;
  t++; //Incremented because getline needs a newline delimiter to read last string
  while(t--)
  {
    getline(cin, input);
    output = polishConvert(input);
    cout<<output<<"\n";
  }
}

// Note: This is not a complete implementation because the input in this case is
// well paranthesized. In a general case, priorities of operators have to be accounted
// for in the stack pushing and popping