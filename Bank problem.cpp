#include<iostream>
#include<iomanip>
using namespace std;

class Bank {
    public :
    
    void calculateinterest(double loan_amount, int tenure){
        float tenureInFloat = tenure; 
        double interest_rate = 0.0 ;
        if(tenure>=1 && 5>=tenure){
            interest_rate = 0.07 ;}
        else if(tenure>=6 && 10>=tenure){
            interest_rate= 0.085 ;}
        else {
            interest_rate = 0.010 ;}
    
            double interest = static_cast<double>(loan_amount * interest_rate * tenureInFloat);
        cout << fixed << setprecision(2) << "Interest: " << interest << endl;
    }
};

int main(){
    Bank customer;
    
    double loan_amount;
    int tenure;
    cin>> loan_amount>>tenure;
    customer.calculateinterest(loan_amount,tenure);
    return 0;
}