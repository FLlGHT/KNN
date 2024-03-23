/**
   Created by flight 
   23.03.2024
*/
#include "knn.h"
#include "../matrix/matrix_utils.h"
#include "../collections/collections_utils.h"

#include <utility>

Knn::Knn(std::vector<std::vector<int>> interactions): interactions(std::move(interactions)) {
    compute();
}

void Knn::compute() {
    std::vector<std::vector<int>> transposed = MatrixUtils::Transpose(interactions);
    std::vector<std::vector<int>> multiplied = MatrixUtils::Multiply(interactions, transposed);
    result = multiplied;
}

std::vector<int> Knn::getNearest(int from, int count) {
    std::vector<int> vector = result[from];
    return CollectionsUtils::findTopKIndices(vector, count);
}

Knn::Knn() = default;
