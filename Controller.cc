#include "Controller.h"

Controller::Controller(Model& model, View& view) : model(model), view(view) { }

void Controller::run() {
    std::string input;

    //get dose players ma mayn
    std::cout << "Enter the number of players: ";
    int numPlayers;
    std::cin >> numPlayers;
    for (int i = 0; i < numPlayers; ++i) {
        std::cout << "Enter the name and game piece for player " << i + 1 << ": ";
        std::string name;
        char piece;
        std::cin >> name >> piece;
        model.setPlayers(name, piece);
    }

    //gameloop
    while (true) {
        std::cin >> input;
        if (input == "quit") break;
        if (input == "roll") {
            // call roll method in model
        } else if (input == "next") {
            // call next method in model
        } else if (input == "trade") {
            // call trade method in model
        } else if (input == "improve") {
            std::string buyOrSell;
            std::cin >> buyOrSell;
            if (buyOrSell == "buy") {
                // call buy improvement method in model
            } else if (buyOrSell == "sell") {
                // call sell improvement method in model
            }
        } else if (input == "mortgage") {
            // call mortgage method in model
        } else if (input == "unmortgage") {
            // call unmortgage method in model
        } else if (input == "bankrupt") {
            // call bankrupt method in model
        } else if (input == "assets") {
            // call assets method in model
        } else if (input == "all") {
            // call all method in model
        } else if (input == "save") {
            std::string filename;
            std::cin >> filename;
            // call save method in model with filename as argument
        }
    }
}
