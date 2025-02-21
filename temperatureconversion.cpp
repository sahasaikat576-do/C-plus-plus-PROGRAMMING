#include <iostream>
using namespace std;

// Class definition for TemperatureConversion
class TemperatureConversion {
private:
    double celsius; // Data member to store temperature in Celsius

public:
    // Constructor to initialize Celsius temperature
    TemperatureConversion(double celsiusInput) {
        celsius = celsiusInput;
    }

    // Method to convert Celsius to Fahrenheit
    double toFahrenheit() {
        return (celsius * 9.0/5.0) + 32;
    }

    // Method to display the temperature conversion result
    void displayConversion() {
        double fahrenheit = toFahrenheit(); // Get Fahrenheit equivalent
        cout << celsius << " Celsius is " << fahrenheit << " Fahrenheit." << endl;
    }
};

// Main function
int main() {
    double celsiusTemp;

    // Take the Celsius temperature input from the user
    cout << "Enter temperature in Celsius: ";
    cin >> celsiusTemp;

    // Create an object of TemperatureConversion class
    TemperatureConversion tempConverter(celsiusTemp);

    // Display the conversion result
    tempConverter.displayConversion();

    return 0;
}
