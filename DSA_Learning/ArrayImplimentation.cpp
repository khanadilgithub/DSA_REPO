
#include <iostream>
//Array implimentation in cpp 
//Similar to the one present in STL
template <typename T, size_t S >//using template to support all data type & provide size at compile time
class Array
{
public:
T& operator[] (int index)//index operator overloading 
{
  return m_Data[index];
}
const T& operator[] (size_t index)const//index operator overloading fo cont array
{
  return m_Data[index];
}
size_t size() {return S;}//return size of array
private:
T m_Data[S];
};

int main() {
Array<std::string,2> arr;
arr[0]="Adil";
arr[1]="CPP";
for (int i=0; i<arr.size(); i++)
{
  std::cout<<arr[i]<<std::endl;
}
} 
