//add all includes and do more
#include "Data.h"
#include "NonPurchase.h"
#include "Player.h"
#include "commands.h"
//#include "board.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>    
bool valid_property (std::string key, std::vector<std::string> properties) {
        return (std::count(properties.begin(), properties.end(), key));
        
    }
    
int main () {
	
        std::string s, tmp;
        std::vector <std::string> properties = {"AL","ML","MKV","ECH","PAS","HH","RCH","PAC","DWE","CPH","UWP","LHI","BMH","OPT","EV1","EV2","EV3","V1","PHYS","B1","CIF","B2","EIT","ESC","C2","REV","MC","DC"};
	while ( getline(std::cin, s))
    {
        int length = s.length();
        std::istringstream iss(s);
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> bString(begin, end);
        while(iss >> tmp)
        {
            if (tmp == "roll" && length == 4) {
		 	   
                }
            else if (tmp == "trade" && bString.size() == 4) {
                if (valid_property(bString[2], properties) && valid_property(bString[3], properties)) {
                        std::cout << "success";
                        //check is player is valid 
			//call trade function 
                    } 
                else {
                        std::cout << "no";
                    }
                    //std::cout << "mole"<<std::endl << length << std::end;
            }
	    else if (tmp == "next" && length == 4) {}
	    else if (tmp == "improve") {
		    if (valid_property(bString[1], properties) && (bString[2] =="true" ||bString[2] =="false" )) {
			    //call improve function
		    }
	    }
	    else if (tmp == "mortage") {
	    	if (valid_property(bString[1], properties)) {
			//call mortgage function
		}
	    }
	    else if (tmp == "unmortgage") {
		    if (valid_property(bString[1], properties)) {
                        //call unmortgage function
                }
	    }
	    else if (tmp == "bankrupt" && length == 8) {
		    // call bankrupt check if player is valid and if player has more money owed than they have in cash
	    }
	    else if (tmp == "assets" && length == 6) {
		    //call assets
	    }
	    else if (tmp == "all" && length == 3) {
		    //call all
	    }
	    else {
		    std::cout << "inavlid command";
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

