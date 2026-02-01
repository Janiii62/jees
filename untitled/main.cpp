#include <iostream>
#include <string>
using namespace std;


// luodaan pankkitiliu

class BankAcc{
protected:
    std::string owner;
    double balance;

public:
    BankAcc(const std::string& name)
        : owner(name), balance(0.0){
        std::cout << "Bank account created for " << owner << "\n";
    }

    virtual ~BankAcc() = default;

    double getBalance() const{
        return balance;
    }
// varmistetaan, että nostaja ei nosta mahdottomia summia
    virtual bool deposit(double amount){
        if(amount <= 0){
            return false;
        }

        balance += amount;
        std::cout << "Bank account: deposit " << amount << " completed\n";
        return true;
    }

    virtual bool withdrawn(double amount){
        if(amount <= 0){
            return false;
        }
        if(balance - amount < 0){
            return false;
        }
        balance -= amount;
        std::cout << "Bank account: withdrawal " << amount << " completed\n";
        return true;
    }
};

// luodaan luottotili

class CreditAcc : public BankAcc{

private:
    double creditLimit;

public:
    CreditAcc(const std::string& name, double limit) : BankAcc(name), creditLimit(limit) {
        balance = limit;
        std::cout << "Credit account created for " << owner << ", credit limit " << creditLimit << "\n";
    }

    bool withdrawn(double amount) override{
        if (amount <= 0){
            return false;
        }
        if (balance - amount < creditLimit){
            return false;
        }
        balance -= amount;
        std::cout << "Credit account: withdrawal " << amount << " completed, credit left " << balance << "\n";
        return true;
    }

    bool deposit(double amount) override{
        if(amount <= 0){
            return false;
        }
        if(balance + amount > 0){
            balance = 0;
        }
        else{
            balance += amount;
        }
        std::cout << "Credit account: payment " << amount << " completed\n";
        return true;
    }
};
// luodaan asiakas

class Customer{
private:
    std::string name;
    BankAcc bankAcc;
    CreditAcc creditAcc;

public:
    Customer(const std::string& n, double creditLimit) : name(n), bankAcc(n), creditAcc(n, creditLimit){

        std::cout << "Customer created: " << name << "\n";
    }

    std::string getName() const{
        return name;
    }

    void showBalance() const{
        std::cout << "Bank account balance: " << bankAcc.getBalance() << "e\n";
        std::cout << "Credit account balance: " << creditAcc.getBalance() << "e\n";
    }

    bool deposit(double amount){
        return creditAcc.deposit(amount);
    }

    bool withdrawn(double amount){
        return bankAcc.withdrawn(amount);
    }

    bool payCredit(double amount){
        return creditAcc.deposit(amount);
    }

    bool withdrawnCredit(double amount){
        return creditAcc.withdrawn(amount);
    }

    bool transfer(double amount, Customer& receiver){
        if(amount <=0){
            return false;
        std::cout << "Bank account: " << name << " transfers " << amount << " to " << receiver.name << "\n";
    }
        if(!bankAcc.withdrawn(amount)){
        return false;
            std::cout << name << " bank account: withdrawal " << amount << " completed\n";
        std::cout << receiver.name << " bank account: deposit " << amount << " completed\n";
        }
        return true;
    };
};

int main()
{

    Customer Nick("Nick Wilde", 1000);

    Nick.deposit(1000);
    Nick.withdrawnCredit(800);

    Nick.showBalance();
    std::cout << "\n";

    Customer Judy("Judy Hopps", 1000);

    std::cout << Nick.getName() << "\n";
    Nick.showBalance();

    Nick.transfer(100, Judy);

    std::cout << Judy.getName() << "\n";
    Judy.showBalance();

    return 0;
};
