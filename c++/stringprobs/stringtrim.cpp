#include <iostream>
#include <string>
#include <algorithm>

int main(void)
{
    std::string astring("[[[Test]]");
    astring.erase(std::remove(astring.begin(),astring.end(), '['), astring.end());
    astring.erase(std::remove(astring.begin(),astring.end(), ']'), astring.end());
    std::cout << astring << std::endl;
    return 0;
}
