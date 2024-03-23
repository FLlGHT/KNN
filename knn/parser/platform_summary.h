#pragma once
#include <vector>
#include <ostream>

/**
   Created by flight 
   23.03.2024
*/

class PlatformSummary {

private:
    long artists{};
    long users{};
    std::vector<std::vector<int>> interactions;

public:
    PlatformSummary();
    PlatformSummary(long users, long artists, std::vector<std::vector<int>> interactions);

    std::vector<std::vector<int>> GenerateInteractionMatrix();

    friend std::ostream &operator<<(std::ostream &os, const PlatformSummary &summary);

private:

    const std::vector<std::vector<int>> &GetInteractions() const;

    long GetArtists() const;

    long GetUsers() const;
};
