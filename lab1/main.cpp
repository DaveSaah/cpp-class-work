#include <iostream>
#include <cstring>
using namespace std;

class Car{
    private: 
        char* name;
        int size;

    public:
        Car(){};
        ~Car(){
           // cout<<"Destructor called with "<<name<<endl;
            delete [] name;
        }
        Car(const char *n){
            size =strlen(n);
            name = new char [size+1];
            strcpy(name,n);
            
        }

        void setName(const char *n){
            size =strlen(n);
            name = new char [size+1];
            strcpy(name,n);
        }

        void print(){
            cout<<name<<endl;
        }
    
};

int main(){

    Car c1;
    c1.setName("Ferrari");
    Car c2;
    c2.setName("Tayota");

    Car c3 = c2;

    c3 = c2;
    c2.print();
    c3.print();

    c2.setName("Kia");
   
    c2.print();
    c3.print();

    
    return 0;
}
