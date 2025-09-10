#include <iostream>
#include <vector>

void insertValues(std::vector<std::vector<int>> &matrix, int x, int y){
    int val = 0;
    for (int i = 0; i < x; i++)    {
        for (int j = 0; j < y; j++)        {
            std::cout << "matrix[" << i + 1 << "][" << j + 1 << "] = ";
            std::cin >> val;
            matrix[i][j] = val;
        }
    }
}

void printmatrix(const std::vector<std::vector<int>> &matrix){
    std::cout << "\nMatrix" << std::endl;
    for (const auto &row : matrix)    {
        for (int val : row)        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int* findValue(const std::vector<std::vector<int>> &matrix, int value) {
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] == value) {
                int* pos = new int[2];
                pos[0] = i;
                pos[1] = j;
                return pos;
            }
        }
    }
    return nullptr;
}

std::vector<std::vector<int>> matrixMul(const std::vector<std::vector<int>> &matrix1, const std::vector<std::vector<int>> &matrix2) {
    size_t rows1 = matrix1.size();
    size_t cols1 = matrix1[0].size();
    size_t rows2 = matrix2.size();
    size_t cols2 = matrix2[0].size();

    if (cols1 != rows2) {
        std::cout << "Can't multiply matrix" << std::endl;
        return std::vector<std::vector<int>>();
    }

    std::vector<std::vector<int>> result(rows1, std::vector<int>(cols2, 0));
    for (size_t i = 0; i < rows1; ++i) {
        for (size_t j = 0; j < cols2; ++j) {
            for (size_t k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    std::cout << "Multipled matrices" << std::endl;
    return result;
}

int main(){
    int x = 0, y = 0;
    std::cout << "Enter no. of rows : ";
    std::cin >> x;
    std::cout << "Enter no. of cols : ";
    std::cin >> y;

    std::vector<std::vector<int>> matrix(x, std::vector<int>(y, 0));
    insertValues(matrix, x, y);
    printmatrix(matrix);

    int find;
    std::cout << "Enter the value you want to find in matrix : ";
    std::cin >> find;
    int* res = findValue(matrix,find);

    if(res == nullptr){
        std::cout << find << " not found in matrix" << std::endl;
    } else {
        std::cout << find << " found at index : (" << res[0] << "," << res[1] << ")\n";
    }
    int a = 0,b = 0;
    std::cout << "Enter no. of rows for second matrix : ";
    std::cin >> a;
    std::cout << "Enter no. of cols for second matrix : ";
    std::cin >> b;

    std::vector<std::vector<int>> matrix2(a, std::vector<int>(b, 0));
    insertValues(matrix2, a, b);
    printmatrix(matrix2);

    std::vector<std::vector<int>> res2 = matrixMul(matrix,matrix2);
    printmatrix(res2);

    return 0;
}
