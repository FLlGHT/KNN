/**
   Created by flight 
   23.03.2024
*/

class MatrixUtils {

public:
    static std::vector<std::vector<int>> Transpose(std::vector<std::vector<int>>& matrix);
    static std::vector<std::vector<int>> BruteForceMultiply(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2);
    static std::vector<std::vector<int>> Multiply(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2);
};
