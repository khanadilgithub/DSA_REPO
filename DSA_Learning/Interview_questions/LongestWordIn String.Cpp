/*
Have the function LongestWord(sen) take the sen parameter being passed and return the longest word in the string.
If there are two or more words that are the same length, return the first word from the string with that length.
Ignore punctuation and assume sen will not be empty. Words may also contain numbers, for example "Hello world123 567"
*/


#include <iostream>
#include<vector>
#include<string>
using namespace std;

string LongestWord(string& sen) 
{
  string LngstWord, CurrentWrld;
  for (int i=0; i<sen.length(); i++)
  {
    while(i <sen.length())
    {
      if (isalnum(sen[i]))
      {
        CurrentWrld+=sen[i];
        i++;
      }
      else break;
    }
    if (CurrentWrld.length()>LngstWord.length())
    {
      LngstWord=CurrentWrld;
      CurrentWrld.clear();
    }
  }
  return LngstWord;
}

int main(void)
{
  string Sentense="Test String Working";
  cout << LongestWord(Sentense);
  return 0;
    
}
