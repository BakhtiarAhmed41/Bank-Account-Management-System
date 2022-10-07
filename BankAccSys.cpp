//                             " Bank Account Management System "
/*
Account types:
    1.Saving Account
    2.Current Account
 
Features: 
    Account Creation
    Deposit
    Withdraw
    Balance
 
*/


#include<iostream>
#include<string>
using namespace std;


char acctype;    		//global variable

class account			//base class
{
private:
    string name;
    string accno;

public:
    void  getAccountDetails()
    {
        cout<<"\nEnter Customer Name : ";
        cin>>name;
        cout<<"Enter Account Number  : ";
        cin>>accno;
    }


    void displayDetails()
    {
        cout<<"\n\nCustomer Name : "<<name;
        cout<<"\nAccount Number  : "<<accno;

        if(acctype=='s' || acctype=='S'){
        cout<<"\nAccount Type    : Savings";}

    	if(acctype=='c' || acctype=='C'){
        cout<<"\nAccount Type    : Current";
		}
    }
};
class current_account : public account  		//derived class
{
private:
    double c_balance=0;
public:
    void c_display()
    {
        cout<<"\nBalance = Rs "<<c_balance<<endl;
    }
    void c_deposit()
    {
        double deposit;
        cout<<"\nEnter amount to Deposit :  ";
        cin>>deposit;
        c_balance = c_balance + deposit;
    }
    void c_withdraw()
    {
        double withdraw;
        cout<<"\n\nBalance = Rs "<<c_balance<<endl;
        cout<<"\nEnter amount to be withdraw : Rs ";
        cin>>withdraw;
        if(c_balance >= withdraw)
        {
            c_balance=c_balance-withdraw;
            cout<<"\nBalance Amount After Withdraw: "<<c_balance<<endl;
        }
        else
        {
            cout<<"\n Insufficient Balance"<<endl;
        }
 
    }
 
 
};
 
class saving_account : public account				//derived class
{
private:
    double s_balance=0;
public:
    void s_display()
    {
        cout<<"\nBalance = Rs "<<s_balance;
    }
    void s_deposit()
    {
        double deposit,interest;
        cout<<"\nEnter amount to Deposit : Rs ";
        cin>>deposit;
        s_balance = s_balance + deposit;
        interest=(s_balance*2)/100;      // 2% profit will be added in the balance
        s_balance=s_balance+interest;
    }
    void s_withdraw()
    {
        double withdraw;
        cout<<"\nBalance = Rs "<<s_balance<<endl;
        cout<<"\nEnter amount to be withdraw : Rs ";
        cin>>withdraw;
        if(s_balance >= withdraw)
        {
            s_balance=s_balance-withdraw;
            cout<<"\nBalance Amount After Withdrawl : Rs "<<s_balance<<endl;
        }
        else
        {
            cout<<"\n Insufficient Balance";
        }
    }
};
 
 
 
int main()
{
    current_account c1;
    saving_account s1;
    
    cout<<"\t\t\t\t---------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t             Bank Account Management System              "<<endl;
	cout<<"\t\t\t\t---------------------------------------------------------"<<endl;
	cout<<"\n";
	
	cout<<"Enter Account Type (S for Savings and C for Current)   : ";
    cin>>acctype;
    
	while(acctype!='s' & acctype!='S' & acctype!='c' & acctype!='C')
	{
   	    cout<<"Entered value is incorrect"<<endl;	
    	cout<<"\nEnter S for saving a/c customer and C for current a/c customer : ";
    	cin>>acctype;
	}


    int choice;
    
    if(acctype=='s' || acctype=='S' )
    {
        s1.getAccountDetails();
        while(true)
        {	cout<<"\n";
        	cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
            cout<<"\nChoose Your Choice"<<endl;
            cout<<"1)   Deposit"<<endl;
            cout<<"2)   Withdraw"<<endl;
            cout<<"3)   Display Balance"<<endl;
            cout<<"4)   Display Account Details"<<endl;
            cout<<"5)   Exit"<<endl;
            cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
            cout<<"\nEnter Your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1 :
                s1.s_deposit();
                break;
            case 2 :
                s1.s_withdraw();
                break;
            case 3 :
                s1.s_display();
                break;
            case 4 :
                s1.displayDetails();
                s1.s_display();
                break;
            case 5 :
                goto end;
            default:
                cout<<"\n\nEntered choice is invalid,\"TRY AGAIN\"";
            }
        }
    }
    else if(acctype=='c' || acctype=='C')
    {
        c1.getAccountDetails();
        while(true)
        {	cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
            cout<<"\nChoose Your Choice"<<endl;
            cout<<"1)   Deposit"<<endl;
            cout<<"2)   Withdraw"<<endl;
            cout<<"3)   Display Balance"<<endl;
            cout<<"4)   Display Account Details"<<endl;
            cout<<"5)   Exit"<<endl;
            cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
			cout<<"\n Enter Your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1 :
                c1.c_deposit();
                break;
            case 2 :
                c1.c_withdraw();
                break;
            case 3 :
                c1.c_display();
                break;
            case 4 :
                c1.displayDetails();
                c1.c_display();
                break;
            case 5 :
                goto end;
            default:
                cout<<"\n\nEntered choice is invalid, TRY AGAIN"<<endl;
            }
        }
    }
    else
    {
        cout<<"\nInvalid Account Selection";
    }

    end:
       cout<<"\nThank You for Banking with us...";
       return 0;
}
