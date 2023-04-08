#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 bool valid_property(std::string key) {
	 std::vector <std::string> properties = {"AL","ML","MKV","ECH","PAS","HH","RCH","PAC","DWE","CPH","UWP","LHI","BMH","OPT","EV1","EV2","EV3","V1","PHYS","B1","CIF","B2","EIT","ESC","C2","REV","MC","DC",};
        return (std::count(properties.begin(), properties.end(), key));

    }
int main () {
        std::string s;
        while (getline(std::cin, s)) {
            int length = s.length();
	    std::cout << s[0];    
	    /*if (s[0] == "roll" && length == 1)  {
                        //roll();
			std::cout << "roll";
                }
                else if (s[0] == "next" && length == 1) {
                        //next();
			std::cout << "next";
                }
                else if (s[0] == "trade" && valid_property(s[2]) && valid_property(s[3])) {
                        //trade (std::string name, std::string give, std::string receive);
			std::cout << s[0] << std::endl <<s[1] << std::endl << s[2] << std::endl << s[3] << std::endl;
                    
                }
                else if (s[0] == "improve" && valid_property(s[1])) {
                        //void improve(std::string property, bool buy);
			std::cout << s[0] << std::endl <<s[1] << std::endl;
                }
                else {
			std::cout << "invalid";
                    
                }
                else if () {}
                else if () {}
                else if () {}
                else if () {}
                else if () {}
                else if () {}
                else if () {}
                else if () {}*/
        }
}

