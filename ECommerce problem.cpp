#include<iostream>
using namespace std;

class Ecommerce {
    private :
    static double  totalamountspentbyauser;
    
    public:
    static const double salestaxrate;
    
    void calculateTotalBill(int item,double itemprice){
        double total = item * itemprice ;
        double tax   = total * salestaxrate ;
        double totalbill = total + tax ;
        totalamountspentbyauser += totalbill;
        cout << totalamountspentbyauser<<endl;
    }
};

double Ecommerce :: totalamountspentbyauser = 0.0;
const double Ecommerce :: salestaxrate = 0.05;

int main () {
    Ecommerce customer;
    double itemprice;
    int item ;
    cin>> item >> itemprice ;
    customer.calculateTotalBill(item,itemprice);
    return 0 ;
}