#include <vector>

/**
   Created by flight 
   23.03.2024
*/

class StringUtils {

public:
    static std::vector<std::string> SplitString(const std::string &rawString, const char& delimiter);
    static std::string & Trim(std::string & string);
    static std::string & LeftTrim(std::string & str);
    static std::string & RightTrim(std::string & str);
};
