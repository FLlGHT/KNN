/**
   Created by flight 
   23.03.2024
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include "interactions_parser.h"

PlatformSummary InteractionsParser::Parse() {
    std::cout << "Start parsing interactions... \n";

    std::fstream fileStream;
    fileStream.open("../knn/data/spotify/user_info.csv");

    std::vector<std::vector<int>> interactions;
    std::unordered_set<int> artists;
    std::unordered_set<int> users;

    for (std::string line; std::getline(fileStream, line);) {
        std::istringstream stringStream(line);

        std::vector<int> row;
        std::string value;

        for (int index = 0; std::getline(stringStream, value, ','); ++index) {
            int interaction = std::stoi(value);
            row.push_back(interaction);

            if (index == 0)
                users.insert(interaction);
            else if (index == 1)
                artists.insert(interaction);
        }
        interactions.push_back(row);
    }

    return {(long) users.size(), (long) artists.size(), interactions};
}
