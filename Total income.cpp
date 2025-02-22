#include<iostream>
using namespace std;

class Income {
    private :
    int salary; // data member of class Income
    int bonus ; // data member of class Income
    
    public :
    Income(int inputsalary,int inputbonus){// creating a constructor to intialize salary and bonus
        salary = inputsalary ;
        bonus  = inputbonus  ;
    }
    // Method / Member function to calculate the total Income
    
    double compute_income(){
        return(salary + bonus);
    }
    // Member function to display salary, bonus, and total income
     
    void displayincome(){
       double Totalincome = compute_income();
        cout<<"The salary is INR"<< salary <<"and bonus is INR"<< bonus<<"Hence Total Income is INR ___"<< Totalincome<<endl;

    }
};
 int main(){
     Income I1( 34563456.678, 2354667.5678);// Create an object T1 of class Income
     I1.displayincome(); // Display income details using displayincome() member function
     return 0;
 }