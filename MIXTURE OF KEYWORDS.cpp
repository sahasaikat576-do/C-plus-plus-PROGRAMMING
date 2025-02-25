#include<iostream>
using namespace std;

class Example{
    private :  // Acess specefier
    int x1,y1,Side,side; //  data members
    public :
    Example(){     // Default constructor
        Side = 89;
        side =10 ;
    }
    Example(int x,int y){      // Paramitarized constructor
        x1 = x; 
        y1 = y;
        
    }
    Example(Example &number){    // Copy Constructor
        x1 = number.x1;
        y1 = number.y1;
    }
    void display(){    // Method to calculate  the values of x1 and x2
        cout << x1 <<" "<<y1;
    }
    
    void data();                  // Declaring method outside class
    };
    // defining method outside the class
    void Example :: data (){       
       cout << Side<<"\n"<<side;
   }

int main() {
    int num1, num2;
    cin >> num1 >> num2;
    
    Example o1(num1, num2);  // Create object o1 with parameters
    Example o2(o1);  // Create o2 by copying o1
    Example o3;
    
    o2.display();  // Display values from o2
    o1.display();  // Display values from o1
    o3.data();     // Display Side and side from o3
    
    return 0;
}