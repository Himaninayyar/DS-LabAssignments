#include<iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] > arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void printheap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify_min(int arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] < arr[smallest])
        smallest = left;

    if (right <= n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify_min(arr, n, smallest);
    }
}

void heapify_max(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
        largest = left;

    if (right <= n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify_max(arr, n, largest);
    }
}

void heapsort_increasing(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--)
        heapify_max(arr, n, i);

    int size = n;

    while (size > 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify_max(arr, size, 1);
    }
}

void heapsort_decreasing(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--)
        heapify_min(arr, n, i);

    int size = n;

    while (size > 1) {
        swap(arr[1], arr[size]);
        size--;
        heapify_min(arr, size, 1);
    }
}

int main() {

    int arr1[6] = {-1, 54, 53, 55, 52, 50};
    int arr2[6] = {-1, 54, 53, 55, 52, 50};

    int n = 5;

    heapsort_increasing(arr1, n);

    cout << "Increasing order: ";
    for (int i = 1; i <= n; i++)
        cout << arr1[i] << " ";
    cout << endl;

    heapsort_decreasing(arr2, n);

    cout << "Decreasing order: ";
    for (int i = 1; i <= n; i++)
        cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
