#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Observer Interface
class Observer {
public:
    virtual void update(float temperature, float humidity) = 0; // Pure virtual function
};

// Subject Interface
class Subject {
public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

// Concrete Subject: Weather Station
class WeatherStation : public Subject {
private:
    vector<Observer*> observers; // List of observers
    float temperature;
    float humidity;

public:
    void addObserver(Observer* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity);
        }
    }

    // Method to set new weather data
    void setWeatherData(float newTemperature, float newHumidity) {
        temperature = newTemperature;
        humidity = newHumidity;
        notifyObservers(); // Notify all observers when data changes
    }
};

// Concrete Observer: Phone Display
class PhoneDisplay : public Observer {
private:
    string deviceName;

public:
    PhoneDisplay(const string& name) : deviceName(name) {}

    void update(float temperature, float humidity) override {
        cout << deviceName << " Display - Temperature: " << temperature 
             << "°C, Humidity: " << humidity << "%" << endl;
    }
};

// Concrete Observer: Computer Display
class ComputerDisplay : public Observer {
private:
    string deviceName;

public:
    ComputerDisplay(const string& name) : deviceName(name) {}

    void update(float temperature, float humidity) override {
        cout << deviceName << " Display - Temperature: " << temperature 
             << "°C, Humidity: " << humidity << "%" << endl;
    }
};

// Example usage
int main() {
    WeatherStation station; // Subject

    PhoneDisplay phone("Phone");
    ComputerDisplay computer("Computer");

    station.addObserver(&phone);    // Adding observers
    station.addObserver(&computer); // Adding observers

    station.setWeatherData(25.0, 60.0); // Setting new weather data
    station.setWeatherData(28.5, 55.0); // Setting new weather data

    station.removeObserver(&phone); // Removing an observer

    station.setWeatherData(30.0, 50.0); // Setting new weather data

    return 0;
}
