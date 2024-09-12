#include<iostream>
using namespace std;

//strategy interface
class paymentStrategy{
    public:
    virtual void pay(int amount)=0;//pure virutal function
};

//concrete strategy for credit card payment

class creditcardpayment : public paymentStrategy{
    public:
    void pay(int amount)override{
        cout<<"paid"<<amount<<"using a credit card"<<endl;
    }
};


//concrete strategy for paypal payment
class paypalPayment : public paymentStrategy{
    public:
    void pay(int amount) override{
        cout<<"paid"<<amount<<"using a paypal"<<endl;
    }
};



//context class
class PaymentClassContext{
    private:
    paymentStrategy* strategy;

    public:
    PaymentClassContext(paymentStrategy* strategy) : strategy(strategy){}

    void setStrategy(paymentStrategy*  newstrategy){
        strategy = newstrategy;
    }

    void makepayment(int amount){
        strategy->pay(amount);
    }
};
int main(){
    creditcardpayment sbi;
    paypalPayment paypay;

    PaymentClassContext context(&sbi);
    context.makepayment(100);

    context.setStrategy(&paypay);
    context.makepayment(200);
    return 0;
}