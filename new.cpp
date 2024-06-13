#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void ImportDataFromFile()
{
    ifstream Fin("User.dat", std::ios::binary);
    if (!Fin.is_open())
    {
        cout << "UNABLE TO OPEN Fin :::: !!!!!!!!!!!!!!!" << endl;
        return;
    }

    char buff[2480]; // Assuming the buffer size is enough for 10 CAccountHolder objects
    CAccountHolder arr[10];
    while (Fin.read(buff, sizeof(buff)))
    {
        memcpy(arr, buff, sizeof(buff));
        for (int i = 0; i < 10; ++i)
        {
            CAccountHolder* temp = new CAccountHolder(arr[i]);
            AllUsers[temp->m_nAccountNumber] = *temp;
            pAccountNum[temp->m_nAccountNumber] = &AllUsers[temp->m_nAccountNumber];
            pMobNum[temp->m_strPhoneNumber] = &AllUsers[temp->m_nAccountNumber];
            AllMobNum.insert(temp->m_strPhoneNumber);
        }
    }

    // Read remaining data if any
    size_t remainingBytes = Fin.gcount();
    if (remainingBytes > 0)
    {
        memcpy(arr, buff, remainingBytes);
        int remainingRecords = remainingBytes / sizeof(CAccountHolder);
        for (int i = 0; i < remainingRecords; ++i)
        {
            CAccountHolder* temp = new CAccountHolder(arr[i]);
            AllUsers[temp->m_nAccountNumber] = *temp;
            pAccountNum[temp->m_nAccountNumber] = &AllUsers[temp->m_nAccountNumber];
            pMobNum[temp->m_strPhoneNumber] = &AllUsers[temp->m_nAccountNumber];
            AllMobNum.insert(temp->m_strPhoneNumber);
        }
    }

    Fin.close();
}
int main(){
    
char b[5] ;
return 0;
}