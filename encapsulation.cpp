#include <iostream>
#include<string>
using namespace std;

class Student{
  
  private:
   string _name;
   int _age;
   
  public:
   void set(string name,int age){
     this->_name = name;
     this->_age = age;
   }
   void get(){
     cout<<"Name : "<<this->_name<<endl;
     cout<<"Age : "<<this->_age<<endl;
   }
};

int main()
{
  Student s1;
  s1.set("Sovan Payra",20);
  s1.get();
    return 0;
}