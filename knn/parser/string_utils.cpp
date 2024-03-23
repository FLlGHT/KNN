/**
   Created by flight 
   23.03.2024
*/
#include "string_utils.h"
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> StringUtils::SplitString(const std::string &rawString, const char& delimiter) {
    std::istringstream stringStream(rawString);
    std::vector<std::string> tokens;

    std::string token;
    while (std::getline(stringStream, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }

    return tokens;
}

std::string & StringUtils::Trim(std::string & string)
{
    return LeftTrim(RightTrim(string));
}

std::string & StringUtils::LeftTrim(std::string & str)
{
    auto it2 =  std::find_if( str.begin() , str.end() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
    str.erase( str.begin() , it2);
    return str;
}

std::string & StringUtils::RightTrim(std::string & str)
{
    auto it1 =  std::find_if( str.rbegin() , str.rend() , [](char ch){ return !std::isspace<char>(ch , std::locale::classic() ) ; } );
    str.erase( it1.base() , str.end() );
    return str;
}