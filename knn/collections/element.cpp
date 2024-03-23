/**
   Created by flight 
   23.03.2024
*/
#include "element.h"

Element::Element(int index, int value) : index(index), value(value) {}

int Element::GetIndex() const {
    return index;
}

int Element::GetValue() const {
    return value;
}
