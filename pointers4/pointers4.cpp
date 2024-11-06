#include <iostream>
#include <vector>

void distributeElements(int* arr, int size, int*& posArr, int& posSize, int*& negArr, int& negSize, int*& zeroArr, int& zeroSize) {
    posSize = 0;
    negSize = 0;
    zeroSize = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) posSize++;
        else if (arr[i] < 0) negSize++;
        else zeroSize++;
    }
    posArr = new int[posSize];
    negArr = new int[negSize];
    zeroArr = new int[zeroSize];

    int posIndex = 0, negIndex = 0, zeroIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) posArr[posIndex++] = arr[i];
        else if (arr[i] < 0) negArr[negIndex++] = arr[i];
        else zeroArr[zeroIndex++] = arr[i];
    }
}

int main() {
    int arr[] = { 1, -2, 0, 5, -3, 0, 7 };
    int size = 7;

    int* posArr, * negArr, * zeroArr;
    int posSize, negSize, zeroSize;

    distributeElements(arr, size, posArr, posSize, negArr, negSize, zeroArr, zeroSize);

    std::cout << "Array + ";
    for (int i = 0; i < posSize; ++i) {
        std::cout << posArr[i] << " ";
    }
    std::cout << "\nArray - ";
    for (int i = 0; i < negSize; ++i) {
        std::cout << negArr[i] << " ";
    }
    std::cout << "\n0 ";
    for (int i = 0; i < zeroSize; ++i) {
        std::cout << zeroArr[i] << " ";
    }

    delete[] posArr;
    delete[] negArr;
    delete[] zeroArr;
    return 0;
}
