#include<iostream>
using namespace std;

class Box {
    private :
    static int length;
    static int breadth;
    static int height;
    
    public :
    static void print(){
        cout <<"The value of length :"<<length<<endl;
        cout <<"The value of breadth : "<<breadth<<endl;
        cout << " The value of height :"<<height<<endl;
    }
};

// Initialize the static data members
int Box :: length = 10;
int Box :: breadth = 20;
int Box :: height = 30 ;

// Driver code 
int main(){
    Box b;
    cout<<"Static member is called through Object name :"<<endl;
    b.print();
    cout<<"Static member function is called through Class name"<< endl;
    Box :: print();
    return 0;
}