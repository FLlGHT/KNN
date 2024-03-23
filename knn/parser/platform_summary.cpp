/**
   Created by flight 
   23.03.2024
*/
#include "platform_summary.h"

PlatformSummary::PlatformSummary(long users, long artists, std::vector<std::vector<int>> interactions)
        : users(users), artists(artists), interactions(std::move(interactions)) {}

long PlatformSummary::GetArtists() const {
    return artists;
}

long PlatformSummary::GetUsers() const {
    return users;
}

const std::vector<std::vector<int>> &PlatformSummary::GetInteractions() const {
    return interactions;
}

std::ostream &operator<<(std::ostream &outputStream, const PlatformSummary &summary) {
    outputStream << "artistsSummary: " << summary.artists
                 << " users: " << summary.users
                 << " interactions size: " << summary.interactions.size();

    return outputStream;
}

std::vector<std::vector<int>> PlatformSummary::GenerateInteractionMatrix() {
    std::vector<std::vector<int>> matrix(GetArtists() + 1, std::vector<int>(GetUsers() + 1));

    for (std::vector<int> item: interactions) {
        matrix[item[1]][item[0]] = item[2];
    }

    return matrix;
}

PlatformSummary::PlatformSummary() = default;


