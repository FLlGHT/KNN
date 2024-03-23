#include "../parser/platform_summary.h"
#include "../parser/artists_summary.h"
#include "../algorithm/knn.h"

/**
   Created by flight 
   23.03.2024
*/

class KnnEngine {

private:
    PlatformSummary platformSummary;
    ArtistsSummary artistsSummary;
    Knn knn;

public:
    KnnEngine();
    void Start();

private:
    void ListenAndAnswer();
};
