#include<bits\stdc++.h>

#define current 0
#define savings 1

using namespace std;

class BankAccount{
private :
    int AC_No;
    string AC_Name;
    bool AC_Type;
    float Curr_Balance;
    float Min_Balance;

public :
    BankAccount()
    {}
    BankAccount (int ac_no, string ac_name, bool ac_type, float curr_balance, float min_balance){
        AC_No = ac_no;
        AC_Name = ac_name;
        AC_Type = ac_type;
        Curr_Balance = curr_balance;
        Min_Balance = min_balance;
    }
    void setInfo(int ac_no, string ac_name, bool ac_type, float curr_balance, float min_balance){
        AC_No = ac_no;
        AC_Name = ac_name;
        AC_Type = ac_type;
        Curr_Balance = curr_balance;
        Min_Balance = min_balance;
    }
    void showInfo(){
        cout << "Account No     : " << AC_No << endl;
        cout << "Account Name   : " << AC_Name << endl;
        if(!AC_Type)
            cout << "Account Type   : Current"<< endl;
        else
            cout << "Account Type   : Savings"<< endl;
        cout << "Current Balance: " << Curr_Balance << endl;
        cout << "Minimum Balance: " << Min_Balance << endl << endl;
    }
    void showBalance(){
        cout << "Current Balance: " << Curr_Balance << endl;
    }
    void deposit(float amount){
        if(amount >= 0)
            Curr_Balance += amount;
        else
            cout << "Deposit amount can not be less than 0" << endl;
    }
    void withdraw(float amount){
        if(amount >= 0 && Curr_Balance >= amount){
            Curr_Balance = amount;
        }
        else if(Curr_Balance < amount)
            cout << "Current balance is less than the withdrawal amount" << endl;
        else
            cout << "Withdrawal amount can not be less than 0" << endl;
    }
    void giveInterest(float percentage = 2.5){
        deposit(Curr_Balance*(percentage/100) - (Curr_Balance*(percentage/100))*0.1);
    }
    ~BankAccount(){
        cout << "Account of " << AC_Name << " with account no " << AC_No
            << " is destroyed with a balance BDT " << Curr_Balance << endl;
    }
};

int main()
{
    BankAccount a1(1234, "Mr. X", current, 5000, 2000);
    a1.showInfo();

    a1.deposit(2000);
    a1.showInfo();

    a1.withdraw(3000);
    a1.showInfo();

    a1.giveInterest(5);
    a1.showInfo();
    return 0;
}
