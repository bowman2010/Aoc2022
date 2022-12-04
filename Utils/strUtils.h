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
std::string toLower(const std::string& str) {
  std::string lower_str(str.size(), ' ');
  std::transform(str.begin(), str.end(), lower_str.begin(), tolower);
  return lower_str;
}

/**
 * @brief toUpper : get an uppercased string
 * @param str
 * @return an uppercased string
 */
std::string toUpper(const std::string& str) {
  std::string upper_str(str.size(), ' ');
  std::transform(str.begin(), str.end(), upper_str.begin(), toupper);
  return upper_str;
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

} // Eof namespace

#endif // STRUTILS_H
