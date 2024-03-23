/**
   Created by flight 
   23.03.2024
*/
#include "artists_summary.h"
#include <string>
#include <utility>
#include "unordered_map"

ArtistsSummary::ArtistsSummary(std::unordered_map<int, std::string> idToArtist,
                               std::map<std::string, int> artistToId) :
        idToArtist(std::move(idToArtist)),
        artistToIdentifier(std::move(artistToId)) {}

std::string ArtistsSummary::findArtist(int id) {
    auto artistEntry = idToArtist.find(id);
    return artistEntry->second;
}

int ArtistsSummary::getId(std::string& artist) {
    auto artistEntry = artistToIdentifier.find(artist);
    return artistEntry->second;
}

ArtistsSummary::ArtistsSummary() = default;
