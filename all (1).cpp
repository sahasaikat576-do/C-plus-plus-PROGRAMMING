#include<iostream>

using namespace std;

// define a class defination for TemperatureConversion
class TemperatureConversion {
    private: 
    double celsius;
// constructor to initialize celsius temperature
    public: 
    TemperatureConversion(double celsiusinput) {
    celsius = celsiusinput;
    }
// Method to convert conversion result
    double toFahrenheit() {
        return (celsius * (9.0 / 5.0)) + 32;
    }

// Method to display the conversion result 
    void displayConversion() {
        double fahrenheit = toFahrenheit(); // Get Fahrenheit equivalent
        cout << celsius << " Celsius is " << fahrenheit << " Fahrenheit." << endl;
    }
};
int main() {
    TemperatureConversion c1(3.7);
     c1.displayConversion();
    return 0;
}