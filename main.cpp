#include <iostream>
#include <random>
using namespace std;

void menu(int** arr, int* size);
void distribution(int** arr, int* size);
void initialization(int* arr, int size);
void print(int* arr, int size);
void _delete(int*& arr);
void add_element_in_end(int** arr, int* size, int element);
void paste_element_in_index(int** arr, int* size, int element, int index);
void delete_element_in_index(int** arr, int* size, int index);

int main() {
    int* arr = nullptr;
    int size = 0;
    menu(&arr, &size);
    if (arr != nullptr) {
        _delete(arr);
    }
    return 0;
}

void menu(int** arr, int* size) {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Create array\n";
        cout << "2. Initialize array\n";
        cout << "3. Print array\n";
        cout << "4. Add element at the end\n";
        cout << "5. Insert element at index\n";
        cout << "6. Delete element at index\n";
        cout << "7. Delete arr and exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

        switch (choice) {
        case 1:
            distribution(arr, size);
            break;
        case 2:
            if (*arr == nullptr) {
                cout << "Array not created. Please create the array first.\n";
            }
            else {
                initialization(*arr, *size);
            }
            break;
        case 3:
            if (*arr == nullptr) {
                cout << "Array not created. Please create the array first.\n";
            }
            else {
                print(*arr, *size);
            }
            break;
        case 4: {
            if (*arr == nullptr) {
                cout << "Array not created. Please create the array first.\n";
            }
            else {
                int element;
                cout << "Enter element to add: ";
                cin >> element;
                add_element_in_end(arr, size, element);
            }
            break;
        }
        case 5: {
            if (*arr == nullptr) {
                cout << "Array not created. Please create the array first.\n";
            }
            else {
                int element, index;
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter index: ";
                cin >> index;
                paste_element_in_index(arr, size, element, index);
            }
            break;
        }
        case 6: {
            if (*arr == nullptr) {
                cout << "Array not created. Please create the array first.\n";
            }
            else {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                delete_element_in_index(arr, size, index);
            }
            break;
        }
        case 7:
            _delete(*arr);
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

void distribution(int** arr, int* size) {
    if (*arr != nullptr) {
        delete[] * arr;
    }
    cout << "Enter the size of the array: ";
    cin >> *size;
    *arr = new int[*size];
}

void initialization(int* arr, int size) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
}

void print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void _delete(int*& arr) {
    delete[] arr;
    arr = nullptr;
}

void add_element_in_end(int** arr, int* size, int element) {
    int* new_arr = new int[*size + 1];
    for (int i = 0; i < *size; i++) {
        new_arr[i] = (*arr)[i];
    }
    new_arr[*size] = element;
    delete[] * arr;
    *arr = new_arr;
    *size += 1;
}

void paste_element_in_index(int** arr, int* size, int element, int index) {
    if (index < 0 || index > *size) {
        cout << "Index out of range.\n";
        return;
    }
    int* new_arr = new int[*size + 1];
    for (int i = 0; i < index; i++) {
        new_arr[i] = (*arr)[i];
    }
    new_arr[index] = element;
    for (int i = index + 1; i < *size + 1; i++) {
        new_arr[i] = (*arr)[i - 1];
    }
    delete[] * arr;
    *arr = new_arr;
    *size += 1;
}

void delete_element_in_index(int** arr, int* size, int index) {
    if (index < 0 || index >= *size) {
        cout << "Index out of range.\n";
        return;
    }
    int* new_arr = new int[*size - 1];
    for (int i = 0; i < index; i++) {
        new_arr[i] = (*arr)[i];
    }
    for (int i = index; i < *size - 1; i++) {
        new_arr[i] = (*arr)[i + 1];
    }
    delete[] * arr;
    *arr = new_arr;
    *size -= 1;
}
