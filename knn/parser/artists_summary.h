#pragma once
#include <unordered_map>
#include <map>

/**
   Created by flight 
   23.03.2024
*/

class ArtistsSummary {
private:
    std::unordered_map<int, std::string> idToArtist;
    std::map<std::string, int> artistToIdentifier;

public:
    ArtistsSummary();
    ArtistsSummary(std::unordered_map<int, std::string> idToArtist, std::map<std::string, int> artistToId);
    std::string findArtist(int id);
    int getId(std::string& artist);
};
