/**
   Created by flight 
   23.03.2024
*/
#include <queue>
#include "collections_utils.h"
#include "element.h"

std::vector<int> CollectionsUtils::findTopKIndices(const std::vector<int> &vector, int count) {
    auto comparator = [](const Element &a, const Element &b) {
        return a.GetValue() < b.GetValue();
    };
    std::priority_queue<Element, std::vector<Element>, decltype(comparator)> elements(comparator);

    for (int index = 0; index < vector.size(); ++index) {
        elements.emplace(index, vector[index]);
    }

    std::vector<int> topKIndices;
    for (int position = 0; position < count && !elements.empty(); ++position) {
        Element element = elements.top(); elements.pop();
        topKIndices.push_back(element.GetIndex());
    }

    return topKIndices;
}