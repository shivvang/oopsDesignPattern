#include<iostream>
using namespace std;;

//component interface
class Coffee{
    public:
    virtual string getDescription()const=0;// A pure virtual function declaration that forces derived classes to provide an implementation.
    virtual double getCost() const =0;//A const pure virtual function, ensuring that it doesn't modify the state of the object.
    virtual ~Coffee(){}
};

//concrete component basic coffee
class BasicCoffee : public Coffee{
   public:
    string getDescription() const override{
        return "Basic Coffee";
    }

    double getCost() const override{
        return 5.0;
    }
};

class coffeeDecorator : public Coffee{
    protected:
    Coffee* coffee; // reference to the wrapped component

    public:
    coffeeDecorator(Coffee* c):coffee(c){}

    string getDescription()const override{
        return coffee->getDescription();
    }

    double getCost() const override{
        return coffee->getCost();
    }

    virtual ~coffeeDecorator(){
        delete coffee;
    }
};

//concrete decorator milk
class MilkDecorator : public coffeeDecorator{
public:
MilkDecorator(Coffee* c) : coffeeDecorator(c){};
string getDescription()const  override{
    return coffee->getDescription() + ", Milk"; 
}
double getCost() const  override{
    return coffee->getCost() + 1.5;
}
};

class SugarDecorator  : public coffeeDecorator{
public:
SugarDecorator (Coffee* c) : coffeeDecorator(c){};
string getDescription()const  override{
    return coffee->getDescription() + ", Sugar"; 
}
double getCost() const  override{
    return coffee->getCost() + 0.5;
}
};

int main(){
    Coffee* myCoffee = new BasicCoffee();                   // Basic coffee
    myCoffee = new MilkDecorator(myCoffee);                 // Add milk
    myCoffee = new SugarDecorator(myCoffee);                // Add sugar

    std::cout << "Description: " << myCoffee->getDescription() << std::endl;
    std::cout << "Cost: $" << myCoffee->getCost() << std::endl;

    delete myCoffee; 
    return 0;
}