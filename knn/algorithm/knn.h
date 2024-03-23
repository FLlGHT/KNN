#pragma once
#include <vector>

/**
   Created by flight 
   23.03.2024
*/

class Knn {

private:
    std::vector<std::vector<int>> interactions;
    std::vector<std::vector<int>> result;
    void compute();
public:
    Knn();
    explicit Knn(std::vector<std::vector<int>> interactions);
    std::vector<int> getNearest(int from, int count);
};
