#include <iostream>
#include <cstdlib>
#include <cmath>

int foo(int a, int b);
int bar(int a, int b);
double baz(double x);

class doubleArray {
private:
    double *_arr;
    int _size = 0;

public:
    doubleArray(int newSize) {
        _arr = new double[newSize];
        _size = newSize;
    }

    ~doubleArray(){
        delete [] _arr;
    }

    int size() {
        return _size;
    } // getter size

    double& operator[](int ii) {
        if (ii < _size) {
            return _arr[ii];
        }  else {
            return _arr[_size - 1];
        }
    } // getter array object

    doubleArray& operator+ (double num) {
        for (int ii = 0; ii < size(); ii++)
        {
            _arr[ii] += num;
        }
        return *this;
    }

    doubleArray& operator- (double num) {
        for (int ii = 0; ii < size(); ii++)
        {
            _arr[ii] -= num;
        }
        return *this;
    }

    void empty() {
        _arr = new double[_size];
    } // empty the array
};

void print_array(doubleArray data, int size);
void assignArrayDouble(doubleArray array);

int main(int argc, char **argv)
{
    int ii = 0;
    int jj = -1;

    foo(ii, jj);
    foo(jj, ii);
    baz(25.9);

    const int NX = 2;
    const int NY = 3;
    const int NZ = 4;


    doubleArray x(NX);
    doubleArray y(NY);
    doubleArray z(NZ);

    assignArrayDouble(x);
    assignArrayDouble(y);
    assignArrayDouble(z);

    ii = 0;
    jj = 0;
    int kk = 0;

    print_array(x, NX);
    print_array(y, NY);
    print_array(z, NZ);
    std::cout << std::endl;

    for (ii = 0; ii < NX; ++ii)
    {
        x[jj] = ii;
    }
    print_array(x, NZ);
    print_array(y, NY);
    print_array(z, NZ + NY);
    std::cout << std::endl;
    for (jj = 0; jj < NY; ++jj)
    {
        x[jj] = ii;
        y[jj] = jj;
    }
    print_array(x - NY, NY);
    print_array(y - NZ, NZ);
    print_array(z + NZ + NY, NX);
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

int foo(int a, int b)
{
    if (a != 0 && b != 0) {
        try {
            return a / b + b / bar(a, b) + b / a;
        }
        catch(...) {
            return 0;
       }
    }
    return 0;
}

int bar(int a, int b)
{
    unsigned int c = a;
    return c + a - b;
}

double baz(double x)
{
    if (x == 0)
        return 0;
    double v = 1 - (x + 1);
    return std::sqrt(x);
}

void print_array(doubleArray data, int size)
{
    std::cout << std::endl;
    for (int ii = 0; ii < ((data.size() > size) ? size : data.size()); ++ii)
    {
        std::cout << data[ii] << "  ";
    }
}

void assignArrayDouble(doubleArray array) {
    for (int ii = 0; ii < array.size(); ii++)
    {
        array[ii] = 0;
    }
}