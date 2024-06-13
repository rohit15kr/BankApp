#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <string.h>
#include <regex>
#include "Structure.h"
#include <fstream>
#include <sstream>
using namespace std;

void setFlag(CAccountHolder &accountHolder, CAccountHolder::Flags flag)
{
    accountHolder.m_nServiceFlags |= flag;
    accountHolder.m_nActiveFlags++;
}
bool checkFlag(const CAccountHolder &accountHolder, CAccountHolder::Flags flag)
{
    return (accountHolder.m_nServiceFlags & flag) != 0;
}
void clearFlag(CAccountHolder &accountHolder, CAccountHolder::Flags flag)
{
    accountHolder.m_nServiceFlags &= ~flag;
    accountHolder.m_nActiveFlags--;
}

void SavingAccountService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your Saving Account is currently : " << endl;
    bool SavingAccountStatus = checkFlag(*Account, CAccountHolder::m_bSavingsAccountFacility);
    if (SavingAccountStatus == 1)
    {
        cout << "your Saving Account is Active :::: " << endl;
        cout << "How Much amount do you wish to deposit in savings account ????" << endl;
        float AmountForSaving;
        std::cin >> AmountForSaving;
        Account->m_fAccountBalance += AmountForSaving;
        AllUsers[AccountNumber] = Account;
    }
    if (!SavingAccountStatus)
    {
        cout << "Not Active" << endl
             << endl;
        cout << "Do YOu want to Avail the facility of Saving Account : " << endl;
        cout << "Press Y to Activate the Saving Account Facility \n Else Press N \n"
             << endl;
        char Options;
        std::cin >> Options;
        if (Options == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bSavingsAccountFacility);
            cout << "How Much amount do you wish to deposit in savings account ????" << endl;
            float AmountForSaving;
            std::cin >> AmountForSaving;
            Account->m_fAccountBalance += AmountForSaving;
            AllUsers[AccountNumber] = Account;
        }
    }
}
void LockerService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your Locker Facility is currently : " << endl;
    bool LockerStatus = checkFlag(*Account, CAccountHolder::m_bLocker);
    if (LockerStatus == 1)
    {
        cout << "Active" << endl;
    }
    else
    {
        cout << "Not Active" << endl;
    }
    if (!LockerStatus)
    {
        cout << "Do YOu want to Avail the facility of Locker : " << endl;
        cout << "Press Y to Activate the Locker Facility \n Else Press N \n"
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bLocker);
            AllUsers[AccountNumber] = Account;
        }
    }
}
void PassbookService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your Passbook Facility is currently : " << endl;
    bool PassbookStatus = checkFlag(*Account, CAccountHolder::m_bPassbook);
    if (PassbookStatus == 1)
    {
        cout << "Active" << endl;
    }
    else
    {
        cout << "Not Active" << endl;
    }
    if (!PassbookStatus)
    {
        cout << "Do YOu want to Avail the facility of Saving Account : " << endl;
        cout << "Press Y to Activate the Saving Account Facility \n Else Press N \n"
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bPassbook);
            AllUsers[AccountNumber] = Account;
        }
    }
}
void MedicalInsuranceService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your MedicalFacility Facility is currently : " << endl;
    bool MedicalFacilityStatus = checkFlag(*Account, CAccountHolder::m_bAvailMedicalInsurance);
    if (MedicalFacilityStatus == 1)
    {
        cout << "Active" << endl;
        cout << "Do You Wish to Add more Medical Insurance or Close this Service for your Account ??" << endl;
        cout << "Press 1 for Adding more medical insurance Or Press 2 for Closing this Medical Insurance Facility for Your Account" << endl;
        char Options;
        std::cin >> Options;
        if (Options == '1')
        {
            cout << "How Much Coverage Do you wish to have a Medical Insurance For ??? : " << endl;
            float AmountOfMedicalInsurance;
            std::cin >> AmountOfMedicalInsurance;
            while (AmountOfMedicalInsurance > Account->m_fAccountBalance)
            {
                cout << "You Don't have sufficient balance in your account to avail insurance for this amount !!!!!" << endl;
            }
            Account->m_fMedicalInsuranceCoverage += AmountOfMedicalInsurance;
            cout << "your total Coverage in Medical insurance is " << Account->m_fMedicalInsuranceCoverage << endl;
            AllUsers[AccountNumber] = Account;
        }
        else if (Options == '2')
        {
            cout << "Do You Wish to Close this medical Facility for your Account ???" << endl;
            cout << "press Y to close this facility Else Press N" << endl;
            char Options;
            std::cin >> Options;
            if (Options == 'Y')
            {
                clearFlag(*Account, CAccountHolder::m_bAvailMedicalInsurance);
                AllUsers[AccountNumber] = Account;
            }
        }
    }
    else
    {
        cout << "Not Active" << endl;
    }
    if (!MedicalFacilityStatus)
    {
        cout << "Do YOu want to Avail the facility of Medical Insurance : " << endl;
        cout << "Press Y to Activate the Medical Insurance Facility \n Else Press N \n"
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bAvailMedicalInsurance);
            cout << "How Much Coverage Do you wish to have a Medical Insurance For ??? : " << endl;
            float AmountOfMedicalInsurance;
            std::cin >> AmountOfMedicalInsurance;
            while (AmountOfMedicalInsurance > Account->m_fAccountBalance)
            {
                cout << "You Don't have sufficient balance in your account to avail insurance for this amount !!!!!" << endl;
                std::cin >> AmountOfMedicalInsurance;
            }
            Account->m_fMedicalInsuranceCoverage += AmountOfMedicalInsurance;
            AllUsers[AccountNumber] = Account;
        }
    }
}
void LifeInsuranceService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your Life INsurance Facility is currently : " << endl;
    bool LifeINsuranceFacility = checkFlag(*Account, CAccountHolder::m_bAvailLifeInsurance);

    if (LifeINsuranceFacility == 1)
    {
        cout << "Active" << endl;
        cout << "How Much Coverage Do you wish to have a Life Insurance For ??? : " << endl;
        float AmountOfLifeInsurance;
        std::cin >> AmountOfLifeInsurance;
        while (AmountOfLifeInsurance > Account->m_fAccountBalance)
        {
            cout << "You Don't have sufficient balance in your account to avail insurance for this amount !!!!!" << endl;
            std::cin >> AmountOfLifeInsurance;
        }
        Account->m_stLifeInsurance.m_fLifeInsuranceAmount += AmountOfLifeInsurance;
        Account->m_stLifeInsurance.m_nLifeInsuranceCount++;
        Account->m_fAccountBalance -= AmountOfLifeInsurance;
        AllUsers[AccountNumber] = Account;
        cout << "A Life INsurance for Rs." << AmountOfLifeInsurance << " has been created against your Account Number" << endl;
        cout << "Available balance in Your bank account is Rs." << Account->m_fAccountBalance << endl;
    }
    else
    {
        cout << "Do YOu want to Avail the facility of Life INsurance : " << endl;
        cout << "Press Y to Activate the Life INsurance Facility \n "
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bAvailLifeInsurance);
            cout << "How Much Coverage Do you wish to have a Medical Insurance For ??? : " << endl;
            float AmountOfLifeInsurance;
            std::cin >> AmountOfLifeInsurance;
            while (AmountOfLifeInsurance > Account->m_fAccountBalance)
            {
                cout << "You Don't have sufficient balance in your account to avail insurance for this amount !!!!!" << endl;
                std::cin >> AmountOfLifeInsurance;
            }
            Account->m_stLifeInsurance.m_fLifeInsuranceAmount += AmountOfLifeInsurance;
            Account->m_stLifeInsurance.m_nLifeInsuranceCount++;
            Account->m_fAccountBalance -= AmountOfLifeInsurance;
            AllUsers[AccountNumber] = Account;

            cout << "A medical INsurance for Rs." << AmountOfLifeInsurance << " has been created against your Account Number" << endl;
            cout << "Available balance in Your bank account is Rs." << Account->m_fAccountBalance << endl;
        }
    }
}

void MutualFundService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your MutualFund Facility is currently : " << endl;
    bool MutualFundStatus = checkFlag(*Account, CAccountHolder::m_bAvailMutualFund);
    if (MutualFundStatus == 1)
    {
        cout << "Active" << endl;
        cout << "How Much Money Do YOu wish to invest in Mutual Fund ??? ::::" << endl;
        float AmountMutualfund;
        std::cin >> AmountMutualfund;
        while (AmountMutualfund > Account->m_fAccountBalance)
        {
            cout << "you have " << Account->m_fAccountBalance << "to Invest this amount in the Mutual fund " << endl;
            cout << "you can invest less than this " << endl;
            std::cin >> AmountMutualfund;
        }
        Account->m_fAccountBalance -= AmountMutualfund;
        Account->m_fMutualFundAmount += AmountMutualfund;
        AllUsers[AccountNumber] = Account;
        cout << "A Mutual Fund for Rs." << AmountMutualfund << " has been created against your Account Number" << endl;
        cout << "Available balance in Your bank account is Rs." << Account->m_fAccountBalance << endl;
    }
    else
    {
        cout << "Not Active" << endl;
        cout << "Do YOu want to Avail the facility of Saving Account : " << endl;
        cout << "Press Y to Activate the Saving Account Facility \n Else Press N \n"
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bAvailMutualFund);
            cout << "How Much Money Do YOu wish to invest in Mutual Fund ??? ::::" << endl;
            float AmountMutualfund;
            std::cin >> AmountMutualfund;
            while (AmountMutualfund > Account->m_fAccountBalance)
            {
                cout << "you have " << Account->m_fAccountBalance << "to Invest this amount in the Mutual fund " << endl;
                cout << "you can invest less than this " << endl;
                std::cin >> AmountMutualfund;
            }
            Account->m_fAccountBalance -= AmountMutualfund;
            Account->m_fMutualFundAmount += AmountMutualfund;
            AllUsers[AccountNumber] = Account;
            cout << "A Mutual Fund for Rs." << AmountMutualfund << " has been created against your Account Number" << endl;
            cout << "Available balance in Your bank account is Rs." << Account->m_fAccountBalance << endl;
        }
    }
}
void FixedDepositService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your FixedDeposit Facility is currently : " << endl;
    bool FixedDepositStatus = checkFlag(*Account, CAccountHolder::m_bAvailFixedDeposit);
    if (FixedDepositStatus == 1)
    {
        cout << "Active" << endl;
        cout << "For how much Money do you wish to open this account ???? : " << endl;
        float AmountForFixedDeposit;
        std::cin >> AmountForFixedDeposit;
        while (AmountForFixedDeposit > Account->m_fAccountBalance)
        {
            cout << "You Don't have sufficient balance in your account to deposit This Amount !!!!!" << endl;
            std::cin >> AmountForFixedDeposit;
        }
        Account->m_fAccountBalance -= AmountForFixedDeposit;
        Account->m_stFixedDeposit.m_nFixedDepositCount++;
        Account->m_stFixedDeposit.m_fFixedDepositAmount += AmountForFixedDeposit;
        cout << "You have A total of Rs." << Account->m_stFixedDeposit.m_fFixedDepositAmount << " in your Fixed Deposit Account" << endl;
        AllUsers[AccountNumber] = Account;
    }
    else
    {
        cout << "Not Active" << endl;
    }
    if (!FixedDepositStatus)
    {
        cout << "Do YOu want to Avail the facility of Saving Account : " << endl;
        cout << "Press Y to Activate the Saving Account Facility \n Else Press N \n"
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bAvailFixedDeposit);
            cout << "For how much Money do you wish to open this account ???? : " << endl;
            float AmountForFixedDeposit;
            std::cin >> AmountForFixedDeposit;
            while (AmountForFixedDeposit > Account->m_fAccountBalance)
            {
                cout << "You Don't have sufficient balance in your account to deposit This Amount !!!!!";
            }
            Account->m_fAccountBalance -= AmountForFixedDeposit;
            Account->m_stFixedDeposit.m_nFixedDepositCount++;
            Account->m_stFixedDeposit.m_fFixedDepositAmount += AmountForFixedDeposit;
            cout << "You have A total of Rs." << Account->m_stFixedDeposit.m_fFixedDepositAmount << " in your Fixed Deposit Account" << endl;
            AllUsers[AccountNumber] = Account;
        }
    }
}
void DematAccountService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your DematAccount Facility is currently : " << endl;
    bool DematAccountStatus = checkFlag(*Account, CAccountHolder::m_bAvailDematFacility);
    if (DematAccountStatus == 1)
    {
        cout << "Active" << endl;
    }
    else
    {
        cout << "Not Active" << endl;
    }
    if (!DematAccountStatus)
    {
        cout << "Do YOu want to Avail the facility of Saving Account : " << endl;
        cout << "Press Y to Activate the Saving Account Facility \n Else Press N \n"
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bAvailDematFacility);
            strncpy(Account->m_strDematAccountNumber, (sDematAccountNumber + to_string(Account->m_nAccountNumber)).c_str(), sizeof(Account->m_strDematAccountNumber) - 1);
            Account->m_strDematAccountNumber[sizeof(Account->m_strDematAccountNumber) - 1] = '\0'; // Null-terminate the string

            cout << "your Demat Account Number is " << Account->m_strDematAccountNumber << endl
                 << endl;
            AllUsers[AccountNumber] = Account;
        }
    }
}
void NominationService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your Nomination Facility is currently : " << endl;
    bool NominationStatus = checkFlag(*Account, CAccountHolder::m_bAvailNomination);
    if (NominationStatus == 1)
    {
        cout << "Active" << endl;
        cout << "you have a total of " << Account->m_stNominee.m_nNomineeCount << " Nominees for your Account" << endl;
        cout << "Do you wish to add More Nominee !!!!!!!!!" << endl;
        cout << "Press Y to add " << endl;
        char ch;
        std::cin >> ch;
        if (ch == 'Y')
        {

            cout << "enter the first name of nominee " << endl;
            string FirstNameOfNominee;
            std::cin >> FirstNameOfNominee;

            cout << "enter the Last name of nominee " << endl;
            string LastNameOfNominee;
            std::cin >> LastNameOfNominee;
            string NameOfNominee = FirstNameOfNominee + " " + LastNameOfNominee;
            strncpy(Account->m_stNominee.arrNomineeNames[Account->m_stNominee.m_nNomineeCount], NameOfNominee.c_str(), sizeof(Account->m_stNominee.arrNomineeNames[0]) - 1);
            Account->m_stNominee.arrNomineeNames[Account->m_stNominee.m_nNomineeCount][sizeof(Account->m_stNominee.arrNomineeNames[0]) - 1] = '\0'; // Null-terminate the string

            Account->m_stNominee.m_nNomineeCount++;
        }
    }
    else
    {
        cout << "Not Active" << endl;
    }
    if (!NominationStatus)
    {
        cout << "Do YOu want to Avail the facility of Nomination : " << endl;
        cout << "Press Y to Activate the Nomination Facility \n Else Press N \n"
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bAvailNomination);
            cout << "Do You Wish to Add Nominee Details :  " << endl;
            cout << "Enter Y if you Want \n Else Enter N " << endl;
            char EnterOption;
            std::cin >> EnterOption;
            if (EnterOption == 'Y')
            {
                cout << "Disclamer ::: You Can Add maximum of three Nominees For your bank Account :::" << endl;

                if (std::cin.fail())
                {
                    // Clear the error state
                    std::cin.clear();

                    // Ignore any remaining characters in the input buffer up to a newline
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    // Output an error message
                    std::cout << "Invalid input. Please enter an integer." << std::endl;
                }

                string NameOfNominee;
                cout << "enter the first name of nominee " << endl;
                string FirstNameOfNominee;
                std::cin >> FirstNameOfNominee;

                cout << "enter the Last name of nominee " << endl;
                string LastNameOfNominee;
                std::cin >> LastNameOfNominee;
                NameOfNominee = FirstNameOfNominee + " " + LastNameOfNominee;
                strncpy(Account->m_stNominee.arrNomineeNames[Account->m_stNominee.m_nNomineeCount], NameOfNominee.c_str(), sizeof(Account->m_stNominee.arrNomineeNames[0]) - 1);
                Account->m_stNominee.arrNomineeNames[Account->m_stNominee.m_nNomineeCount][sizeof(Account->m_stNominee.arrNomineeNames[0]) - 1] = '\0'; // Null-terminate the string

                Account->m_stNominee.m_nNomineeCount++;
            }
            AllUsers[AccountNumber] = Account;
        }
    }
}
void EStatementService(CAccountHolder *Account, int AccountNumber)
{
    cout << "your EStatement Facility is currently : " << endl;
    bool EStatementStatus = checkFlag(*Account, CAccountHolder::m_bAvailEstatement);
    if (EStatementStatus == 1)
    {
        cout << "Active" << endl;
    }
    else
    {
        cout << "Not Active" << endl;
    }
    if (!EStatementStatus)
    {
        cout << "Do YOu want to Avail the facility of Saving Account : " << endl;
        cout << "Press Y to Activate the Saving Account Facility \n Else Press N \n"
             << endl;
        char c;
        std::cin >> c;
        if (c == 'Y')
        {
            setFlag(*Account, CAccountHolder::m_bAvailEstatement);
            AllUsers[AccountNumber] = Account;
        }
    }
}
bool StringToBool(string s)
{
    if (s == "Yes")
        return 1;
    else
        return 0;
}

void AccountUpdateServices()
{
    std::cout << "Enter your Account Number: " << std::endl;
    int AccountNumber;
    std::cin >> AccountNumber;
    while (AllUsers.find(AccountNumber) == AllUsers.end())
    {
        std::cout << "The Account Number you entered Does Not Exist !!!!!!" << std::endl;
        std::cout << "Please Enter Correct Account Number" << std::endl;
        std::cin >> AccountNumber;
    }
    CAccountHolder *Account = AllUsers[AccountNumber];
    std::cout << "\nAll Details of this user\n";
    std::cout << "This Account Belongs to " << Account->m_strFirstName << " " << Account->m_strLastName << std::endl;
    std::cout << "City: " << Account->m_strCityName << std::endl;
    std::cout << "Email Id: " << Account->m_strEmail << std::endl;
    std::cout << "Phone Number: " << Account->m_strPhoneNumber << std::endl;
    std::cout << "What do YOU want to modify: " << std::endl;
    std::cout << "1. First Name" << std::endl;
    std::cout << "2. Last Name" << std::endl;
    std::cout << "3. City" << std::endl;
    std::cout << "4. Mobile Number" << std::endl;
    std::cout << "5. Email Id" << std::endl;
    std::cout << "6. Other Services" << std::endl;
    std::cout << "Select Options between 1 and 6: " << std::endl;
    int option;
    std::cin >> option;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer." << std::endl;
    }
    switch (option)
    {
    case 1:
    {
        std::cout << "Previous First Name: " << Account->m_strFirstName << std::endl;
        std::cout << "New First Name: " << std::endl;
        std::string strNewFirstName;
        std::cin >> strNewFirstName;
        std::strcpy(Account->m_strFirstName, strNewFirstName.c_str());
    }
    break;
    case 2:
    {
        std::cout << "Previous Last Name: " << Account->m_strLastName << std::endl;
        std::cout << "New Last Name: " << std::endl;
        std::string NewLastName;
        std::cin >> NewLastName;
        std::strcpy(Account->m_strLastName, NewLastName.c_str());
    }
    break;
    case 3:
    {
        std::cout << "Previous City Name: " << Account->m_strCityName << std::endl;
        std::cout << "New City Name: " << std::endl;
        std::string NewCityName;
        std::cin >> NewCityName;
        std::strcpy(Account->m_strCityName, NewCityName.c_str());
    }
    break;
    case 4:
    {
        std::cout << "Previous PhoneNumber: " << Account->m_strPhoneNumber << std::endl;
        string prevPhoneNumber = Account->m_strPhoneNumber;
        std::cout << "New PhoneNumber: " << std::endl;
        std::string NewPhoneNumber;
        std::cin >> NewPhoneNumber;
        std::strcpy(Account->m_strPhoneNumber, NewPhoneNumber.c_str());
        pMobNum[NewPhoneNumber] = AllUsers[AccountNumber];
        pMobNum.erase(prevPhoneNumber);
        AllMobNum.erase(prevPhoneNumber);
        AllMobNum.insert(NewPhoneNumber);
    }
    break;
    case 5:
    {
        std::cout << "Previous Email: " << Account->m_strEmail << std::endl;
        std::cout << "New Email: " << std::endl;
        std::string NewEmail;
        std::cin >> NewEmail;
        std::strcpy(Account->m_strEmail, NewEmail.c_str());
    }
    break;
    case 6:
    {
        cout << "services You want to avail : " << endl;
        cout << "1. Saving Account : " << endl;
        cout << "2. Locker Facility : " << endl;
        cout << "3. Passbook Facility : " << endl;
        cout << "4. Medical Insurance : " << endl;
        cout << "5. Life Insurance :  " << endl;
        cout << "6. Mutual Fund : " << endl;
        cout << "7. Fixed Deposit : " << endl;
        cout << "8. Demat : " << endl;
        cout << "9. Nomination : " << endl;
        cout << "10. Estatement : " << endl;
        int ServiceOptions;
        std::cin >> ServiceOptions;
        if (std::cin.fail())
        {
            // Clear the error state
            std::cin.clear();

            // Ignore any remaining characters in the input buffer up to a newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Output an error message
            std::cout << "Invalid input. Please enter an integer." << std::endl;
        }
        switch (ServiceOptions)
        {
        case 1:
        {
            SavingAccountService(Account, AccountNumber);
        }
        break;
        case 2:
        {
            LockerService(Account, AccountNumber);
        }
        break;
        case 3:
        {
            PassbookService(Account, AccountNumber);
        }
        break;
        case 4:
        {
            MedicalInsuranceService(Account, AccountNumber);
        }
        break;
        case 5:
        {
            LifeInsuranceService(Account, AccountNumber);
        }
        break;
        case 6:
        {
            MutualFundService(Account, AccountNumber);
        }
        break;
        case 7:
        {
            FixedDepositService(Account, AccountNumber);
        }
        break;
        case 8:
        {
            DematAccountService(Account, AccountNumber);
        }
        break;
        case 9:
        {
            NominationService(Account, AccountNumber);
        }
        break;
        case 10:
        {
            EStatementService(Account, AccountNumber);
        }
        break;
        default:
            break;
        }
    }
    }
}
void CreateUserAccount()
{
    string m_strFirstName,
        m_strLastName,
        m_strCityName,
        m_strEmail,
        m_strPhoneNumber;
    printf("Enter the first name:\n");
    std::cin >> m_strFirstName;
    printf("Enter the last name:\n");
    std::cin >> m_strLastName;
    printf("Enter the city name:\n");
    std::cin >> m_strCityName;

    printf("Enter the Phone Number :\n");
    std::cin >> m_strPhoneNumber;
    while (!isPhoneNumberValid(m_strPhoneNumber))
    {
        cout << "Write Correct Phone Number !!!!!!" << endl;
        std::cin >> m_strPhoneNumber;
    }

    cout << "Enter Your Email :" << endl;
    std::cin >> m_strEmail;
    while (!isEmailValid(m_strEmail))
    {
        cout << "Write Correct Email !!!!!!" << endl;
        std::cin >> m_strEmail;
    }
    CAccountHolder *NewUser;

    NewUser->m_nAccountNumber = (sAccountNumberInitial + AllUsers.size() + 1);

    std::strcpy(NewUser->m_strFirstName, m_strFirstName.c_str());
    std::strcpy(NewUser->m_strLastName, m_strLastName.c_str());
    std::strcpy(NewUser->m_strCityName, m_strCityName.c_str());
    std::strcpy(NewUser->m_strPhoneNumber, m_strPhoneNumber.c_str());
    std::strcpy(NewUser->m_strEmail, m_strEmail.c_str());

    AllUsers[NewUser->m_nAccountNumber] = NewUser;
    // pAccountNum[NewUser->m_nAccountNumber] = AllUsers[NewUser->m_nAccountNumber];
    pMobNum[NewUser->m_strPhoneNumber] = AllUsers[NewUser->m_nAccountNumber];

    cout << endl
         << "Account Successfully Created with the following details " << endl
         << endl;
    cout << "Your Account Number \t ::: \t" << NewUser->m_nAccountNumber << endl;
    cout << "Your First name     \t ::: \t" << NewUser->m_strFirstName << endl;
    cout << "Your Last name      \t ::: \t" << NewUser->m_strLastName << endl;
    cout << "Your City name      \t ::: \t" << NewUser->m_strCityName << endl;
    cout << "Your Phone Number   \t ::: \t" << NewUser->m_strPhoneNumber << endl;
    cout << "Your Email Id       \t ::: \t" << NewUser->m_strEmail << endl;
    cout << endl
         << endl;
    cout << "Do YOu wish to Update Details and Add Services :::: Press Y if Yes else Press N" << endl;
    char option;
    std::cin >> option;
    if (option == 'Y')
    {
        AccountUpdateServices();
    }
}
void DeleteUserAccount()
{
    cout << "Enter the Account Number You want to delete : " << endl;
    int lAccountNumber;
    std::cin >> lAccountNumber;

    AllUsers[lAccountNumber]->DeleteObject();
}
void DisplayUsersAccount()
{
    for (auto it : AllUsers)
    {
        if (it.second->m_strFirstName == "")
        {
            cout << "Account Number is " << it.first << endl;
            cout << "This Account has been deleted" << endl;
            cout << "========================================================================" << endl;
        }
        else
        {
            cout << "Account Number is : " << it.first << endl
                 << "   and all other details like " << endl
                 << "first name is " << it.second->m_strFirstName << endl
                 << " Second Name is " << it.second->m_strLastName << endl
                 << " city of User is  " << it.second->m_strCityName << endl
                 << " Email Id of User is  " << it.second->m_strEmail << endl
                 << " Phone Number of User is  " << it.second->m_strPhoneNumber << endl;
            cout << "=======================================================================" << endl;
            cout << "Numbers of active flags are " << it.second->m_nActiveFlags << endl;
        }
    }
}
void ForgotAccountNumber()
{
    cout << "Enter Your Mobile Number:::" << endl;
    string str_MobNum;
    cin >> str_MobNum;
    CAccountHolder temp;
    temp = *pMobNum[str_MobNum];
    cout << "Account Number is : " << temp.m_nAccountNumber << endl
         << "   and all other details like " << endl
         << "first name is " << temp.m_strFirstName << endl
         << " Second Name is " << temp.m_strLastName << endl
         << " city of User is  " << temp.m_strCityName << endl
         << " Email Id of User is  " << temp.m_strEmail << endl
         << " Phone Number of User is  " << temp.m_strPhoneNumber << endl;
    cout << "=======================================================================" << endl;
}

void ImportDataFromFile()
{
    ifstream Fin("User.dat", std::ios::binary);
    if (!Fin.is_open())
    {
        cout << "UNABLE TO OPEN File :::: !!!!!!!!!!!!!!!" << endl;
    }
    else
    {

        Fin.seekg(0, ios::end);
        int NumberOfRecords = Fin.tellg() / sizeof(CAccountHolder);
        Fin.seekg(0, ios::beg);

        while (NumberOfRecords != 0)
        {
            int index = min(10,NumberOfRecords);
            CAccountHolder *accountHolder = new CAccountHolder[index];
            Fin.read((char *)accountHolder, sizeof(CAccountHolder) * index);
            for (int nIndex = 0; nIndex < index; nIndex++)
            {
                AllUsers[accountHolder[nIndex].m_nAccountNumber] = &accountHolder[nIndex];
                pMobNum[accountHolder[nIndex].m_strPhoneNumber] = &accountHolder[nIndex];
            }
            NumberOfRecords -= index;
        }

        // CAccountHolder *accountHolder = new CAccountHolder();
        // while (Fin.read(reinterpret_cast<char *>(accountHolder), sizeof(*accountHolder)))
        // {
        //     AllUsers[accountHolder->m_nAccountNumber] = accountHolder;
        //     // pAccountNum[accountHolder->m_nAccountNumber] = AllUsers[accountHolder->m_nAccountNumber];
        //     pMobNum[accountHolder->m_strPhoneNumber] = AllUsers[accountHolder->m_nAccountNumber];
        //     AllMobNum.insert(accountHolder->m_strPhoneNumber);
        // }
    }
}

int main()
{
    CAccountHolder new2;
    cout << sizeof(new2) << endl;
    ImportDataFromFile();
    while (1)
    {
        cout << "\n1. Create User Account\n";
        cout << "2. Edit Account Details and Update Services\n";
        cout << "3. Delete Account\n";
        cout << "4. Show all Clients\n";
        cout << "9. Exit and Save Details\n";
        int SelectedOption;
        std::cin >> SelectedOption;
        switch (SelectedOption)
        {
        case 1:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            CreateUserAccount();
        }
        break;
        case 2:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            AccountUpdateServices();
        }
        break;
        case 3:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            DeleteUserAccount();
        }
        break;

        case 4:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            DisplayUsersAccount();
        }
        break;
        case 5:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ForgotAccountNumber();
        }
        break;
        case 9:
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::ofstream outFile("User.dat", std::ios::binary);

            if (!outFile)
            {
                std::cerr << "Error opening file for writing!" << std::endl;
            }

            for (const auto &accountHolder : AllUsers)
            {
                CAccountHolder *temp;
                temp = accountHolder.second;
                outFile.write(reinterpret_cast<const char *>(temp), sizeof(CAccountHolder));
            }

            outFile.close();

            return 0;
        }
        break;
        default:
            if (std::cin.fail())
            {
                // Clear the error state
                std::cin.clear();

                // Ignore any remaining characters in the input buffer up to a newline
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                // Output an error message
                std::cout << "Invalid input. Please enter an integer." << std::endl;
            }
        }
    }
    return 0;
}