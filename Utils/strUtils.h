#ifndef STRUTILS_H
#define STRUTILS_H

#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

namespace bml {

/**
 * @brief toLower : get an lowercased string
 * @param str
 * @return a lowercased string
 */
std::string toLower(std::string& str) {
    std::string s(str);
    std::transform(
        s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::tolower(c); }
    );
    return s;
}

/**
 * @brief toUpper : get an uppercased string
 * @param str
 * @return an uppercased string
 */
std::string toUpper(std::string& str) {
    std::string s(str);
    std::transform(
        s.begin(), s.end(), s.begin(),
        [](unsigned char c) { return std::toupper(c); }
    );
    return s;
}

/**
 * @brief splitStr : split a string into a vector of string
 * @param str
 * @param sep : separator to use
 * @return a vector of strings
 */
std::vector<std::string> splitStr(const std::string str, const char sep=' ')
{
    std::string tempStr;
    std::vector<std::string> sv;
    std::stringstream iss(str);
    while (getline(iss,tempStr,sep))
        sv.push_back(tempStr);
    return sv;
}

/**
 * @brief leftPad : pad a string with char to length len
 * @param str : input string
 * @param len : desired length
 * @param pad : pad used for padding
 * @return the padded string
 */
std::string leftPad(const std::string &str, size_t len, const char pad=' ')
{
    if (str.length()>=len) return str;
    std::string paddedStr(len-str.size(), pad);
    return paddedStr+str;
}

/**
 * @brief rightPad : pad a string with char to length len
 * @param str : input string
 * @param len : desired length
 * @param pad : pad used for padding
 * @return the padded string
 */
std::string rightPad(const std::string &str, size_t len, const char pad=' ')
{
    if (str.length()>=len) return str;
    std::string paddedStr(len-str.size(), pad);
    return str+paddedStr;
}

/**
 * @brief trim : remove leading and trailing chars
 * @param str
 * @param chars : default to space char
 * @return
 */
std::string trim(std::string str, std::string chars=" ")
{
    std::string s(str);
    s.erase(str.find_last_not_of(chars) + 1);
    s.erase(0,str.find_first_not_of(chars));
    return s;
}

/**
 * @brief trimLeft : remove leading chars
 * @param str
 * @param chars : default to space char
 * @return
 */
std::string trimLeft(std::string str, std::string chars=" ")
{
    std::string s(str);
    s.erase(0,str.find_first_not_of(chars));
    return s;
}

/**
 * @brief trimRight: remove trailing chars
 * @param str
 * @param chars : default to space char
 * @return
 */
std::string trimRight(std::string str, std::string chars=" ")
{
    std::string s(str);
    s.erase(str.find_last_not_of(chars) + 1);
    return s;
}


} // Eof namespace

#endif // STRUTILS_H
