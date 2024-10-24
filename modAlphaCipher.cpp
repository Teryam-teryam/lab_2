#include "modAlphaCipher.h"

modAlphaCipher::modAlphaCipher(const std::wstring& skey)
{
    for(unsigned i = 0; i < numAlpha.size(); i++) {
        alphaNum[numAlpha[i]] = i;
    }
    key = convert(getValidKey(skey));
}

std::wstring modAlphaCipher::encrypt(const std::wstring& open_text)
{
    std::vector<int> work = convert(getValidOpenText(open_text));
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

std::wstring modAlphaCipher::decrypt(const std::wstring& cipher_text)
{
    std::vector<int> work = convert(getValidCipherText(cipher_text));
    for(unsigned i = 0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}

inline std::vector<int> modAlphaCipher::convert(const std::wstring& s)
{
    std::vector<int> result;
    for(auto c : s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline std::wstring modAlphaCipher::convert(const std::vector<int>& v)
{
    std::wstring result;
    for(auto i : v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
inline std::string modAlphaCipher::getValidKey(const std::wstring& s)
{
    if(s.empty())
        throw cipher_error("пустой ключ");
    std::string tmp(s);
    for(auto& c : tmp) {
        if(!isalpha(c))
            throw cipher_error(std::string("недопустимый ключ ") );//+ s
        if(islower(c))
            c = toupper(c);
    }
    return tmp;
}
inline std::string modAlphaCipher::getValidOpenText(const std::wstring& s)
{
    std::string tmp;
    for(auto c : s) {
        if(isalpha(c)) {
            if(islower(c))
                tmp.push_back(toupper(c));
            else
                tmp.push_back(c);
        }
    }
    if(tmp.empty())
        throw cipher_error("пустой вводимый текст ");
    return tmp;
}
inline std::string modAlphaCipher::getValidCipherText(const std::string& s)
{
    if(s.empty())
        throw cipher_error("пустой расшифровываемый текст ");
    for(auto c : s) {
        if(!isupper(c))
            throw cipher_error(std::string(L"недопустимый недопустимый текст ") );//+ s
    }
    return s;
}
