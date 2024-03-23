/**
   Created by flight 
   23.03.2024
*/
#include <vector>
#include <iostream>
#include "matrix_utils.h"

std::vector<std::vector<int>> MatrixUtils::Transpose(std::vector<std::vector<int>> &matrix) {
    std::vector<std::vector<int>> transposed(matrix[0].size(), std::vector<int>(matrix.size()));

    for (int row = 0; row < matrix.size(); ++row) {
        for (int column = 0; column < matrix[0].size(); ++column) {
            transposed[column][row] = matrix[row][column];
        }
    }

    return transposed;
}

// slowly, just for example
std::vector<std::vector<int>> MatrixUtils::BruteForceMultiply(
        std::vector<std::vector<int>> &matrix1,
        std::vector<std::vector<int>> &matrix2) {

    std::vector<std::vector<int>> matrix = std::vector(matrix1.size(), std::vector<int>(matrix2[0].size()));
    for (int row = 0; row < matrix.size(); ++row) {
        for (int column = 0; column < matrix[0].size(); ++column) {
            for (int inner = 0; inner < matrix2.size(); ++inner) {
                matrix[row][column] += (matrix1[row][inner] * matrix2[inner][column]);
            }
        }
        std::cout << "Parsed " << row << " row \n";
    }

    return matrix;
}

// optimized sparse matrix multiplication
std::vector<std::vector<int>> MatrixUtils::Multiply(
        std::vector<std::vector<int>> &matrix1,
        std::vector<std::vector<int>> &matrix2) {

    std::vector<std::vector<int>> temp(matrix1[0].size(), std::vector<int>());
    for (int row = 0; row < matrix1[0].size(); ++row) {
        for (int column = 0; column < matrix2[0].size(); ++column) {
            if (matrix2[row][column] != 0)
                temp[row].push_back(column);
        }
    }

    std::vector<std::vector<int>> result(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));
    for (int row = 0; row < matrix1.size(); ++row) {
        for (int column = 0; column < matrix1[0].size(); ++column) {
            if (matrix1[row][column] != 0) {
                for (int inner: temp[column]) {
                    result[row][inner] += matrix1[row][column] * matrix2[column][inner];
                }
            }
        }
    }

    return result;
}


