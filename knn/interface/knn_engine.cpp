/**
   Created by flight 
   23.03.2024
*/

#include "knn_engine.h"
#include "../parser/interactions_parser.h"
#include "../parser/artists_parser.h"
#include "../collections/collections_utils.h"
#include "../parser/string_utils.h"
#include <iostream>
#include <vector>
#include <string>

KnnEngine::KnnEngine() = default;

void KnnEngine::Start() {
    platformSummary = InteractionsParser::Parse();
    artistsSummary = ArtistsParser::Parse();

    knn = Knn(platformSummary.GenerateInteractionMatrix());
    ListenAndAnswer();
}

void KnnEngine::ListenAndAnswer() {
    std::cout << platformSummary << "\n";

    while (true) {
        std::string name;
        std::cout << "\n\n" << "Enter the full name of the artist you are interested in: " << "\n";
        std::getline(std::cin, name);

        if (name == "Enough")
            break;

        int artistIndex = artistsSummary.getId(name);
        std::vector<int> nearestArtists = knn.getNearest(artistIndex, 10);

        std::cout << "Top similar artists to " << name << ": \n";

        for (const auto &similarArtistIndex: nearestArtists) {
            if (similarArtistIndex == artistIndex)
                continue;

            auto similarArtistName = artistsSummary.findArtist(similarArtistIndex);
            std::cout << similarArtistName << " ";
        }
    }
}



