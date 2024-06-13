#include <iostream>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <string.h>
#include <regex>
#include <fstream>
#include <sstream>
using namespace std;

unordered_set<string> AllMobNum;

bool isEmailValid(const string &email)
{
    const regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
bool isPhoneNumberValid(const string &phone)
{
    bool MobExist = false;
    if (AllMobNum.find(phone) != AllMobNum.end())
    {
        MobExist = true;
    }
    const regex pattern(
        "\\d{10}");
    if (MobExist == false && regex_match(phone, pattern))
        return true;
    else
        return false;
    // return regex_match(phone, pattern);
}

int sAccountNumberInitial = 0;
string sDematAccountNumber = "IN4521869595";
struct CAccountHolder
{
    short int m_nVersionNo = 1;
    short int m_nAccountNumber = 0;
    float m_fAccountBalance = 0;
    char m_strFirstName[25] = "";
    char m_strLastName[25] = "";
    char m_strCityName[25] = "";
    char m_strPhoneNumber[11] = "";
    char m_strEmail[25] = "";
    short int m_nActiveFlags = 0;
    enum Flags
    {
        m_bSavingsAccountFacility = 1 << 0,
        m_bLocker = 1 << 1,
        m_bPassbook = 1 << 2,
        m_bAvailDematFacility = 1 << 3,
        m_bAvailLifeInsurance = 1 << 4,
        m_bAvailMedicalInsurance = 1 << 5,
        m_bAvailFixedDeposit = 1 << 6,
        m_bAvailMutualFund = 1 << 7,
        m_bAvailNomination = 1 << 8,
        m_bAvailEstatement = 1 << 9,
        m_bAccountFlag = 1 << 10
    };
    short int m_nServiceFlags = 0;
    char m_strDematAccountNumber[17];

    struct stLifeInsurance
    {
        short int m_nLifeInsuranceCount;
        float m_fLifeInsuranceAmount;
    } m_stLifeInsurance;

    float m_fMedicalInsuranceCoverage;

    struct stFixedDeposit
    {
        short int m_nFixedDepositCount;
        float m_fFixedDepositAmount;
    } m_stFixedDeposit;

    float m_fMutualFundAmount;

    struct stNominee
    {
        short int m_nNomineeCount;
        char arrNomineeNames[3][25];
    } m_stNominee;

    void DeleteObject()
    {
        m_nVersionNo = 0;
        m_nAccountNumber = 0;
        m_fAccountBalance = 0;
        m_strFirstName[0] = '\0';
        m_strLastName[0] = '\0';
        m_strCityName[0] = '\0';
        m_strPhoneNumber[0] = '\0';
        m_strEmail[0] = '\0';
        m_nActiveFlags = 0;
        m_nServiceFlags = 0;
        m_strDematAccountNumber[0] = '\0';
        m_stLifeInsurance.m_nLifeInsuranceCount = 0;
        m_stLifeInsurance.m_fLifeInsuranceAmount = 0;
        m_fMedicalInsuranceCoverage = 0;
        m_stFixedDeposit.m_nFixedDepositCount = 0;
        m_stFixedDeposit.m_fFixedDepositAmount = 0;
        m_fMutualFundAmount = 0;
        m_stNominee.m_nNomineeCount = 0;

        for (int i = 0; i < 3; ++i)
        {
            m_stNominee.arrNomineeNames[i][0] = '\0';
        }
    }
};

map<int, CAccountHolder *> AllUsers;
unordered_map<int, CAccountHolder *> pAccountNum;
unordered_map<string, CAccountHolder *> pMobNum;