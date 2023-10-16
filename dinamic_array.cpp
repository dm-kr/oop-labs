// массив 16 элементов, удвоить размер, если индекс за границей

#include <iostream>
#include <cstring>

class Array
{
public:
    int size;
    int* arr;
    Array()
        :size(16)
    {
        arr = (int*)malloc(size * sizeof(int));
    }

    int& operator[](int idx)
    {
        if (idx > (size - 1))
        {
            arr = (int*)realloc(arr, size * 2 * sizeof(int));
            int* tmp = arr + (size)*sizeof(int);
            for (int i = size; i < size*2; i++)
            {
                *tmp = 1;
                tmp++;
            }
        }
        int* ptr = arr;
        ptr += sizeof(int) * idx;
        return *ptr;
    }

    ~Array()
    {
        free(arr);
    }
};

int main()
{
    Array a;
    a[0] = 1;
    a[2] = 3;
    std::cout << "Values: " << a[0] << ", " << a[2] << ", " << a[18] << ", " << a[50] << std::endl;
}