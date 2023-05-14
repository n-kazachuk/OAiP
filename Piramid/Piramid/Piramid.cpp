#include <iostream>
#include <vector>

using namespace std;

// Функция, которая реализует пирамиду
void heapify(vector<int>& arr, int n, int i)
{
    int largest = i;  // инициализируем наибольший элемент как корень
    int l = 2 * i + 1;  // левый потомок
    int r = 2 * i + 2;  // правый потомок

    // Если левый потомок больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый потомок больше, чем наибольший элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // Если наибольший элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);
        // Рекурсивно создаем пирамиду для измененной поддерева
        heapify(arr, n, largest);
    }
}

// Основная функция, которая реализует сортировку пирамидой
void heapSort(vector<int>& arr)
{
    int n = arr.size();

    // Создаем пирамиду (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = { 12, 11, -2, 13, 5, 6, 7, -5, 20, 6, 19, 3 };
    heapSort(arr);
    cout << "Отсортированный массив: \n";
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
}
