#include <iostream>
#include <vector>
#include <string>

class Car {
private:
    std::string model;
    double dailyRentalRate;
    bool isAvailable;

public:
    // Constructor
    Car(std::string m, double rate) : model(m), dailyRentalRate(rate), isAvailable(true) {}

    // Getter for the model
    std::string getModel() const {
        return model;
    }

    // Getter for the rental rate
    double getDailyRentalRate() const {
        return dailyRentalRate;
    }

    // Method to rent the car
    bool rentCar() {
        if (isAvailable) {
            isAvailable = false;
            return true;
        }
        return false;
    }

    // Method to return the car
    void returnCar() {
        isAvailable = true;
    }

    // Method to check availability status
    bool checkAvailability() const {
        return isAvailable;
    }

    // Display car information
    void displayCarInfo() const {
        std::cout << "Model: " << model << "\n";
        std::cout << "Daily Rental Rate: $" << dailyRentalRate << "\n";
        std::cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << "\n";
    }
};

class CarRentalCompany {
private:
    std::vector<Car> cars;

public:
    // Add a car to the rental fleet
    void addCar(const std::string& model, double rate) {
        cars.push_back(Car(model, rate));
    }

    // Rent a car based on the model
    bool rentCar(const std::string& model) {
        for (auto& car : cars) {
            if (car.getModel() == model && car.checkAvailability()) {
                if (car.rentCar()) {
                    std::cout << "You have successfully rented the " << model << " car.\n";
                    return true;
                }
            }
        }
        std::cout << "Sorry, the " << model << " car is not available.\n";
        return false;
    }

    // Return a car based on the model
    void returnCar(const std::string& model) {
        for (auto& car : cars) {
            if (car.getModel() == model && !car.checkAvailability()) {
                car.returnCar();
                std::cout << "You have successfully returned the " << model << " car.\n";
                return;
            }
        }
        std::cout << "The " << model << " car was not rented.\n";
    }

    // Display all available cars
    void displayCars() const {
        std::cout << "Available Cars:\n";
        for (const auto& car : cars) {
            if (car.checkAvailability()) {
                car.displayCarInfo();
                std::cout << "----------------------------\n";
            }
        }
    }
};

int main() {
    CarRentalCompany rentalCompany;

    // Add some cars to the fleet
    rentalCompany.addCar("Toyota Corolla", 30.0);
    rentalCompany.addCar("Honda Civic", 35.0);
    rentalCompany.addCar("Ford Mustang", 50.0);

    // Display available cars
    rentalCompany.displayCars();

    // Rent a car
    rentalCompany.rentCar("Honda Civic");

    // Display available cars after renting
    rentalCompany.displayCars();

    // Return a car
    rentalCompany.returnCar("Honda Civic");

    // Display available cars after returning
    rentalCompany.displayCars();

    // Try to rent a non-available car
    rentalCompany.rentCar("Ford Mustang");

    return 0;
}
