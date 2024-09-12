#include<iostream>
using namespace std;

// Product Interface
class Vehicle {
public:
    virtual void createVehicle() = 0; // Pure virtual function to create the vehicle
    virtual ~Vehicle() {}             // Virtual destructor for proper cleanup
};


// Concrete Product 1: Car
class Car : public Vehicle {
public:
    void createVehicle() override {
        std::cout << "Car created!" << std::endl;
    }
};

// Concrete Product 2: Bike
class Bike : public Vehicle {
public:
    void createVehicle() override {
        std::cout << "Bike created!" << std::endl;
    }
};


// Creator Interface
class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0; // Factory method to create vehicles
    virtual ~VehicleFactory() {}
};


// Concrete Creator 1: Car Factory
class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car(); // Creates and returns a Car object
    }
};

// Concrete Creator 2: Bike Factory
class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Bike(); // Creates and returns a Bike object
    }
};


int main(){
        // Creating a car using the CarFactory
    VehicleFactory* carFactory = new CarFactory();
    Vehicle* myCar = carFactory->createVehicle();
    myCar->createVehicle(); // Output: Car created!

    // Creating a bike using the BikeFactory
    VehicleFactory* bikeFactory = new BikeFactory();
    Vehicle* myBike = bikeFactory->createVehicle();
    myBike->createVehicle(); // Output: Bike created!

    // Clean up
    delete myCar;
    delete myBike;
    delete carFactory;
    delete bikeFactory;

    return 0;
}