#include <iostream>

const int size = 3;

template <typename T>
void swap(T *arr, const int size) {
    for(int i = 0, j = size - 1; i < size / 2; i++, j--) {
        T x = arr[i];
        arr[i] = arr[j];
        arr[j] = x;
    }
}



int main(int argc, char const *argv[])
{


    int arr[] = {1, 2, 3};
    const int arrSize = sizeof(arr) / sizeof(int);
    swap(arr, arrSize);

    char str[] = {"456"};
    const int strSize = sizeof(str) / sizeof(char);
    swap(str, strSize);

    for(int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << std::endl;
    }
    std::cout << std::endl;

    for(int i = 0; i < strSize; i++) {
        std::cout << str[i] << std::endl;
    }
    std::cout << std::endl;
    

    system("pause");
    return 0;
}
