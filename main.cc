//add all includes and do more
#include "Data.h"
#include "NonPurchase.h"
#include "Player.h"
#include "commands.h"
//#include "board.h"
#include <iostream>
#include <string>
#include <vectors>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
int main () {
        std::string s, tempstring;
    /*vector <string> properties = {"AL","ML","MKV","ECH","PAS","HH","RCH","PAC","DWE","CPH","UWP","LHI","BMH","OPT","EV1","EV2","EV3","V1","PHYS","B1","CIF","B2","EIT","ESC","C2","REV","MC","DC",};
    bool valid_property(std::string key) {
        return (std::count(properties.begin(), properties.end(), key));

    }*/
    while ( getline(std::cin, s))
    {
        int length = s.length();
        std::istringstream iss(s);
        while(iss >> tempstring)
        {
            if (tempstring == "roll" && length == 1) {
                std::cout << "troll" << std::endl;
                }
                else {
                    std::cout << "mole"<<std::endl << length << std::endl;


                }

    }
}


                /*if (s[0] == "roll" && length == 1)  {
                        //roll();
                        cout << "roll";
                }
                else if (s[0] == "next" && length == 1) {
                        //next();
                        cout << "next";
                }
                else if (s[0] == "trade" && valid_property(s[2]) && valid_property(s[3])) {
                        //trade (std::string name, std::string give, std::string receive);
                        cout << s[0] << endl <<s[1] << endl << s[2] << endl<< s[3] << endl;

                }
                else if (s[0] == "improve" && valid_property(s[1])) {
                        //void improve(std::string property, bool buy);
                        cout << s[0] << endl <<s[1] << endl;
                }
                else {
                    cout << "invalid";

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
