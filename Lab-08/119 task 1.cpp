#include <bits/stdc++.h>
using namespace std;

class Account {
protected:
    int accountNo;
    string accountName;
    float balance;

public:
    Account(int accountPrefix, int nextAccountNo, string _accountName, float _balance){
        accountNo = accountPrefix * 1000 + nextAccountNo;
        accountName = _accountName;
        balance = _balance;
    }
    int getAccountNo(){
        return accountNo;
    }
    string getAccountName(){
        return accountName;
    }
    float getBalance(){
        return balance;
    }
    void setAccountNo(int _accountNo){
        accountNo = _accountNo;
    }
    void setAccountName(string _accountName){
        accountName = _accountName;
    }
    void setBalance(float _balance){
        balance = _balance;
    }
};

class CurrentAccount: public Account{
private:
    const static int serviceCharge;
    const static int accountPrefix;
    static int nextAccount;

public:
    CurrentAccount(string acName, float bal):
        Account(getAccountPrefix(), nextAccountNo(), acName, bal)
    { }
    const static int getServiceCharge(){
        return serviceCharge;
    }
    const static int getAccountPrefix(){
        return accountPrefix;
    }
    static int nextAccountNo(){
        nextAccount++;
        return nextAccount;
    }
    void description(){
        cout << "Current Account, You can deposit and withdraw anytime by any amount in this type of account" << endl;
    }
};

const int CurrentAccount::serviceCharge = 100;
const int CurrentAccount::accountPrefix = 100;
int CurrentAccount::nextAccount = 0;

class SavingsAccount : public Account
{
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix;
    static int nextAccount;

public:
    SavingsAccount(string acName, float bal, float _interestRate, float mda):
        Account(getAccountPrefix(), nextAccountNo(), acName, bal)
    {
        interestRate = _interestRate;
        monthlyDepositAmount = mda;
    }
    void setInterestRate (float _interestRate){
        interestRate = _interestRate;
    }
    void setMonthlyDepositAmount (float deposit){
        monthlyDepositAmount = deposit;
    }
    float getInterestRate (){
        return interestRate;
    }
    float getMonthlyDepositAmount (){
        return monthlyDepositAmount;
    }
    const static int getAccountPrefix (){
        return accountPrefix;
    }
    static int nextAccountNo(){
        nextAccount++;
        return nextAccount;
    }
    void description(){
        cout << "Savings Account, You can deposit your savings monthly in this type of account" << endl;
    }
};

const int SavingsAccount::accountPrefix = 200;
int SavingsAccount::nextAccount = 0;

class MonthlyDepositScheme : public Account
{
private :
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix;
    static int  nextAccount;
public :
    MonthlyDepositScheme(string acName, float bal, float _interestRate, float mda):
        Account(getAccountPrefix(), nextAccountNo(), acName, bal)
    {
        interestRate = _interestRate;
        monthlyDepositAmount = mda;
    }
    void setInterestRate (float interest){
        interestRate = interest;
    }
    void setMonthlyDepositAmount (float deposit){
        monthlyDepositAmount = deposit;
    }
    float getInterestRate (){
        return interestRate;
    }
    float getMonthlyDepositAmount (){
        return monthlyDepositAmount;
    }
    static int getAccountPrefix (){
        return accountPrefix;
    }
    static int nextAccountNo(){
        nextAccount++;
        return nextAccount;
    }
};

const int MonthlyDepositScheme::accountPrefix = 300;
int MonthlyDepositScheme::nextAccount = 0;

class LoanAccount : public Account
{
private :
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix;
    static int  nextAccount;

public :
    LoanAccount(string acName, float bal, float _interestRate, float mda):
        Account(getAccountPrefix(), nextAccountNo(), acName, bal)
    {
        interestRate = _interestRate;
        monthlyDepositAmount = mda;
    }
    void setInterestRate (float interest){
        interestRate = interest;
    }
    void setMonthlyDepositAmount (float deposit){
        monthlyDepositAmount = deposit;
    }
    float getInterestRate (){
        return interestRate;
    }
    float getmonthlyDepositAmount (){
        return monthlyDepositAmount;
    }
    static int getAccountPrefix (){
        return accountPrefix;
    }
    static int nextAccountNo(){
        LoanAccount::nextAccount++;
        return (LoanAccount::nextAccount);
    }
    void description(){
        cout << "Loan Account, You can take loan which you need to pay with a fixed amount of money each month" << endl;
    }
};

const int LoanAccount::accountPrefix = 900;
int LoanAccount::nextAccount = 0;


class TwoYearMDS : public MonthlyDepositScheme
{
private :
    float maximumInterest;

public :
    TwoYearMDS(string acName, float bal, float _interestRate, float mda, float maxInterest):
        MonthlyDepositScheme(acName, bal, _interestRate, mda)
    {
        maximumInterest = maxInterest;
    }
    void setMaximumInetrest (float interest){
        maximumInterest = interest;
    }
    float getMaximumInterest (){
       return maximumInterest;
    }
    void description(){
        cout << "Two Year Monthly Deposit Scheme, You need to deposit a fixed amount of money each month" << endl;
    }
};

class FiveYearMDS : public MonthlyDepositScheme
{
private :
    float maximumInterest;

public :
    FiveYearMDS(string acName, float bal, float _interestRate, float mda, float maxInterest):
        MonthlyDepositScheme(acName, bal, _interestRate, mda)
    {
        maximumInterest = maxInterest;
    }
    void setMaximumInterest (float interest){
        maximumInterest = interest;
    }
    float getMaximumInterest (){
       return maximumInterest;
    }
    void description(){
        cout << "Five Year Monthly Deposit Scheme, You need to deposit a fixed amount of money each month" << endl;
    }
};

class InitialDepositMDS : public MonthlyDepositScheme
{
private :
    float maximumInterest;
    float initialDepositAmount;

public :
    InitialDepositMDS(string acName, float bal, float _interestRate, float mda, float maxInterest, float initDeposit):
        MonthlyDepositScheme(acName, bal, _interestRate, mda)
    {
        maximumInterest = maxInterest;
        initialDepositAmount = initDeposit;
    }
    void setMaximumInterest (float interest){
        maximumInterest = interest;
    }
    float getMaximumInterest (){
       return maximumInterest;
    }
    void setInitialDepositAmount (float amount){
        initialDepositAmount = amount;
    }
    float getInitialDepositAmount (){
        return initialDepositAmount;
    }
    void description(){
        cout << "Initial Deposit Scheme, You need to deposit an initial amount from which you get fixed amount of money each month" << endl;
    }
};

int main()
{
    CurrentAccount c1("user1", 10000);
    cout << "Current Account Info:"
        "\nAccount No: " << c1.getAccountNo() <<
        "\nAccount Name: " << c1.getAccountName() << "\n\n";

    SavingsAccount s1("user2", 5000, 10, 1000);
    cout << "Savings Account Info:"
        "\nAccount No: " << s1.getAccountNo() <<
        "\nAccount Name: " << s1.getAccountName() <<
        "\nInterest Rate: " << s1.getInterestRate() << "%"
        "\nMonthly Deposit Amount: " << s1.getMonthlyDepositAmount() << "\n\n";

    LoanAccount l1("user3", 6000, 15, 1000);
    cout << "Loan Account Info:"
        "\nAccount No: " << l1.getAccountNo() <<
        "\nAccount Name: " << l1.getAccountName() <<
        "\nInterest Rate: " << l1.getInterestRate() << "%"
        "\nMonthly Deposit Amount: " << s1.getMonthlyDepositAmount() << "\n\n";

    TwoYearMDS t1("user4", 7000, 7, 800, 15);
    cout << "TwoYearMDS Account Info:"
        "\nAccount No: " << t1.getAccountNo() <<
        "\nAccount Name: " << t1.getAccountName() <<
        "\nInterest Rate: " << t1.getInterestRate() << "%"
        "\nMonthly Deposit Amount: " << t1.getMonthlyDepositAmount() <<
        "\nMaximum Interest: " << t1.getMaximumInterest() << "%\n\n";

    FiveYearMDS f1("user5", 15000, 12, 1500, 20);
    cout << "FiveYearMDS Account Info:"
        "\nAccount No: " << f1.getAccountNo() <<
        "\nAccount Name: " << f1.getAccountName() <<
        "\nInterest Rate: " << f1.getInterestRate() << "%"
        "\nMonthly Deposit Amount: " << f1.getMonthlyDepositAmount() <<
        "\nMaximum Interest: " << f1.getMaximumInterest() << "%\n\n";

    InitialDepositMDS i1("user6", 25000, 8, 2000, 10, 30000);
    cout << "InitialDepositMDS Account Info:"
        "\nAccount No: " << i1.getAccountNo() <<
        "\nAccount Name: " << i1.getAccountName() <<
        "\nInterest Rate: " << i1.getInterestRate() << "%"
        "\nMonthly Deposit Amount: " << i1.getMonthlyDepositAmount() <<
        "\nMaximum Interest: " << i1.getMaximumInterest() << "%"
        "\nInitial Deposit Amount: " << i1.getInitialDepositAmount() << "\n";
    return 0;
}
