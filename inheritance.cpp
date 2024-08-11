#include <iostream>
#include<string>
using namespace std;

class Phone{
  private:
   string _screen;
   string _battery;
   string _weight = "200 grams";
  public:
   void setScreen(string screen){this->_screen = screen;}
   string getScreen(){return this->_screen;}
   void setBattery(string battery){this->_battery = battery;}
   string getBattery(){return this->_battery;}
   void setWeight(string weight){this->_weight = weight;}
   string getWeight(){return this->_weight;}
};

class Iphone: public Phone{
  public:
   string _brand = "Apple";
   void print(){
       cout<<"Brand : "<<_brand<<endl;
       cout<<"Screen : "<<getScreen()<<endl;
       cout<<"Battery : "<<getBattery()<<endl;
       cout<<"Weight : "<<getWeight()<<endl;
   }
};


int main()
{
    Iphone i1;
    i1.setScreen("6.12 Inches");
    i1.setWeight("150 grams");
    i1.setBattery("5020 Mah");
    i1.print();
    return 0;
}