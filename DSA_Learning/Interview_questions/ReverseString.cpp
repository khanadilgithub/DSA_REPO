#include<iostream>
#include<cstring>
void ReverseString(std::string& S)
{ 
  int len=S.length();
  for (int i =len; i>=0; i--)
  {
    std::cout<<S[i];
  }
}

int main()
{
  std::string S="ADILCPP";
  ReverseString(S);
  return 0;
}
