#include<iostream>
using namespace std;
class Transaction {
public:
    int balance;
    int amount;
    int n;
    Transaction() {
        balance=0;
        amount=0;
        n=0;
    }
    void depositdetails() {
        cout<<"============TRANSACTIONS==========="<<endl;
        cout<<"How many transaction do you want for depositing money?"<<endl;
        cin>>n;
        Transaction user[n];

        for(int i=0; i<n; i++) {
            cout<<"Enter your balance:"<<endl;
            cin>>user[i].balance;
            cout<<"Enter amount for depositing:"<<endl;
            cin>>user[i].amount;
        }
        for(int i=0; i<n; i++) {
            cout<<"your recent deposit transaction details:"<<endl;
            cout<<user[i].balance<<" "<<endl;
            cout<<user[i].amount<<" "<<endl;
            cout<<"now your balance is:"<<user[i].balance+user[i].amount<<endl;
        }
    }
    void withdrawdetails() {
        cout<<"How many transaction do you want for withdraw money?"<<endl;
        cin>>n;
        Transaction user[n];

        for(int i=0; i<n; i++) {
            cout<<"Enter your balance:"<<endl;
            cin>>user[i].balance;
            cout<<"Enter amount for withdrawing:"<<endl;
            cin>>user[i].amount;
            if(user[i].balance>0 && user[i].amount<=user[i].balance) {
                user[i].balance-=user[i].amount;
            } else {
                cout<<"Insufficient balance"<<endl;
            }
        }
        for(int i=0; i<n; i++) {
            cout<<"your recent withdraw transaction details:"<<endl;
            cout<<user[i].balance<<" "<<endl;
            cout<<user[i].amount<<" "<<endl;
            cout<<"now your balance is:"<<user[i].balance<<endl;
        }
    }
    ~Transaction() {
        cout<<"obj deleted…"<<endl;
    }
};
class Account {
private:
    int accountnumber;
    double balance;
    string accountType;
    int amount;
    Transaction t1;
    int n;
public:
    Account() {
        accountnumber=0;
        balance=0;
        accountType=" ";
        amount=0;
        n=0;
    }
    void createaccount() {
        cout<<"Enter your accountnumber:"<<endl;
        cin>>accountnumber;
    }
    void depositwithdraw() {
        cout<<"=============DEPOSIT & WITHDRAW============"<<endl;
        cout<<"Enter balance:"<<endl;
        cin>>balance;
        cout<<"Enter amount for depositing:"<<endl;
        cin>>amount;
        balance+=amount;
        cout<<"your current balance is:"<<balance<<endl;
        if(balance>0 && balance>=amount) {
            cout<<"Enter amount for withdraw:"<<endl;
            cin>>amount;
            balance=balance-amount;
            cout<<"your current balance is:"<<balance<<endl;
            cout<<"withdrawn amount is:"<<amount<<endl;
        } else {
            cout<<"Insufficient balance"<<endl;
        }
    }
    void deposwithdraw() {
        t1.depositdetails();
        t1.withdrawdetails();
    }
    ~Account() {
        cout<<"obj deleted…"<<endl;
    }
};
class Customer {
public:
    string customerID;
    string name;
    string phoneNumber;
    string address;
    Account a1;
    int n;
    Customer() {
        customerID="";
        name="";
        phoneNumber="";
        address="";
    }
    void createCustomer() {
        cout<<"=============BANKING SYSTEM============="<<endl;
        cout<<"=============CREATING CUSTOMER==========="<<endl;
        Customer customer[1];
        for(int i=0; i<1; i++) {
            cout<<"Enter your name:"<<endl;
            getline(cin,customer[i].name);

            cout<<"Enter your phoneNumber:"<<endl;
            getline(cin,customer[i].phoneNumber);

            cout<<"Enter your address:"<<endl;
            getline(cin,customer[i].address);

            cout<<"Enter customerID:"<<endl;
            getline(cin,customer[i].customerID);
        }
        for(int i=0; i<1; i++) {
            cout<<"your name is:"<<customer[i].name<<endl;

            cout<<"your phoneNumber is:"<<customer[i].phoneNumber<<endl;
            cout<<"your address is:"<<customer[i].address<<endl;
            cout<<"your customerID is:"<<customer[i].customerID<<endl;
            cout<<"your accounts is created successfully."<<endl;
        }
    }

    void accountdetails() {
        a1.createaccount();
        a1.depositwithdraw();
        a1.deposwithdraw();
    }
    ~Customer() {
        cout<<"customer obj deleted..."<<endl;
    }
};
int main() {
    Customer c1;
    c1.createCustomer();

    c1.accountdetails();

    return 0;
}