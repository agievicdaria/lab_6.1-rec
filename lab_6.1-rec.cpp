#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 20;
const int LOWER_BOUND = -20;
const int UPPER_BOUND = 50;

void generateArray(int arr[], int size, int lower, int upper, int i)
{
    arr[i] = lower + rand() % (upper - lower + 1);
    if (i < size - 1)
    {
        generateArray(arr, size, lower, upper, i + 1);
    }
}

void printArray(int a[], int size, int index = 0) {
    if (index < size) {
        cout << setw(6) << a[index] << " ";
        printArray(a, size, index + 1);
    } else {
        cout << endl;
    }
}

void calculateSumAndChangeToZero(int arr[], int size, int index, int &count, int &sum)
{
    if (index >= size)
    {
        return;
    }

    if (arr[index] > 0 && !(index % 5 == 0))
    {
        count++;
        sum += arr[index];
        arr[index] = 0;
    }

    calculateSumAndChangeToZero(arr, size, index + 1, count, sum);
}

int main()
{
    srand((unsigned)time(NULL));

    int array[ARRAY_SIZE];
    generateArray(array, ARRAY_SIZE, LOWER_BOUND, UPPER_BOUND, 0);

    cout << "Оригінальний масив: ";
    printArray(array, ARRAY_SIZE);
    cout << endl;

    int count = 0;
    int sum = 0;
    calculateSumAndChangeToZero(array, ARRAY_SIZE, 0, count, sum);

    cout << "Кількість елементів, які задовольняють критерії: " << count << endl;
    cout << "Сума елементів, які задовольняють критерії: " << sum << endl;

    cout << "Модифікований масив: ";
    printArray(array, ARRAY_SIZE);
    cout << endl;

    return 0;
}
