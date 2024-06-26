#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> 
#include <random>    
#include <iomanip>   
#include <ctime>     

using namespace std;
using namespace std::chrono;

// prototipe
void bubbleSort(vector<int>& arr);
void insertionSort(vector<int>& arr);
void selectionSort(vector<int>& arr);
void mergeSort(vector<int>& arr, int left, int right);
void merge(vector<int>& arr, int left, int mid, int right);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);

vector<int> generateRandomVector(int size) {
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);

    for (int i = 0; i < size; ++i) {
        vec[i] = dis(gen);
    }

    return vec;
}

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void measureSortingTime(const vector<int>& original, const string& algoName) {
    vector<int> arr = original; 

    auto start = high_resolution_clock::now();

    if (algoName == "Bubble Sort") {
        bubbleSort(arr);
    } else if (algoName == "Insertion Sort") {
        insertionSort(arr);
    } else if (algoName == "Selection Sort") {
        selectionSort(arr);
    } else if (algoName == "Merge Sort") {
        mergeSort(arr, 0, arr.size() - 1);
    } else if (algoName == "Quick Sort") {
        quickSort(arr, 0, arr.size() - 1);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << setw(15) << algoName << ": " << duration.count() << " microseconds" << endl;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int N;
    cout << "Masukkan Ukuran data :"<<endl;
    cin >> N;

    cout << "Ukuran data N = " << N << endl;

    vector<string> algorithms = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Merge Sort", "Quick Sort"};
    vector<int> randomData = generateRandomVector(N);

    cout << "Data acak:" << endl;
    for (auto& algo : algorithms) {
        measureSortingTime(randomData, algo);
    }
    cout << endl;

    sort(randomData.rbegin(), randomData.rend());

    cout << "Data terurut terbalik:" << endl;
    for (auto& algo : algorithms) {
        measureSortingTime(randomData, algo);
    }
    cout << endl;

    sort(randomData.begin(), randomData.end());

    cout << "Data sudah terurut:" << endl;
    for (auto& algo : algorithms) {
        measureSortingTime(randomData, algo);
    }
    cout << endl;

    return 0;
}