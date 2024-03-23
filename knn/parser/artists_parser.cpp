/**
   Created by flight 
   23.03.2024
*/
#include "artists_parser.h"
#include "string_utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

ArtistsSummary ArtistsParser::Parse() {
    std::cout << "Start parsing artists summary... \n";

    std::map<std::string, int> artistToId;
    std::unordered_map<int, std::string> idToArtist;

    std::fstream fileStream;
    fileStream.open("../knn/data/spotify/artists.csv");

    for (std::string line; std::getline(fileStream, line);) {
        std::istringstream stringStream(line);

        std::vector<std::string> row = StringUtils::SplitString(line, ',');
        std::string firstValue = row[0];
        int artistId = std::atoi(StringUtils::Trim(firstValue).c_str());
        std::string name = StringUtils::Trim(row[1]);
        idToArtist[artistId] = name;
        artistToId[name] = artistId;
    }

    return {idToArtist, artistToId};
}
