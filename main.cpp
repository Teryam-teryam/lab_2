#include "modAlphaCipher.h"

#include <iostream>
using namespace std;
void check(const wstring& Text, const wstring& key)
{
 try {
 string cipherText;
 string decryptedText;
 modAlphaCipher cipher(key);
 cipherText = cipher.encrypt(Text);
 decryptedText = cipher.decrypt(cipherText);
 wcout<<L"ключ="<<key<<endl;
 wcout<<Text<<endl;
 wcout<<cipherText<<endl;
 wcout<<decryptedText<<endl;
 } catch (const cipher_error & e) {
 wcerr<<L"Ошибка: "<<e.what()<<endl;
 }
}
int main(int argc, char** argv)
{
    check(L"ЕХАЛГРЕКА","СИМПД");
    /*check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","");
    check("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG","ABCD123");
    check("The Quick Brown Fox Jumps Over The Lazy Dog","SUPER");
    check("123","ABCD");*/
    return 0;
}
