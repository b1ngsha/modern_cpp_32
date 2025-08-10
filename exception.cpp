#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <vector>

class matrix
{
private:
    float *data_;
    size_t nrows_;
    size_t ncols_;

public:
    matrix(size_t nrows, size_t ncols) : nrows_(nrows), ncols_(ncols)
    {
        data_ = new float[nrows * ncols];
    }

    ~matrix()
    {
        delete[] data_;
    }

    friend matrix operator*(const matrix &lhs, const matrix &rhs)
    {
        if (lhs.ncols_ != rhs.nrows_)
        {
            throw std::runtime_error("matrix sizes mismatch");
        }
        matrix result(lhs.nrows_, rhs.ncols_);
        // ...
        return result;
    }
};

int main()
{
    std::vector<int> v{1, 2, 3};
    std::cout << v[0] << std::endl;
    std::cout << v.at(0) << std::endl;
    std::cout << v[3] << std::endl;
    try
    {
        v.at(3);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}