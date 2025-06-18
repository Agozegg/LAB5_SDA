#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Problema 1
int *array = NULL;
int size = 0;

void initialize_array(int n) {
    srand(time(NULL));
    size = n;
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;
    }
    printf("Array initialized with %d random elements.\n", size);
}

void display_array() {
    if (array == NULL) {
        printf("Array has not been initialized.\n");
        return;
    }
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void free_memory() {
    free(array);
    array = NULL;
    size = 0;
    printf("Memory has been freed.\n");
}

void linear_search(int number) {
    if (array == NULL) {
        printf("Array has not been initialized.\n");
        return;
    }
    clock_t start = clock();
    for (int i = 0; i < size; i++) {
        if (array[i] == number) {
            clock_t end = clock();
            double duration = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Number %d found at position %d in %.10f seconds (linear search).\n", number, i, duration);
            return;
        }
    }
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Number %d not found in %.10f seconds (linear search).\n", number, duration);
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void binary_search(int number) {
    if (array == NULL) {
        printf("Array has not been initialized.\n");
        return;
    }

    qsort(array, size, sizeof(int), compare);

    clock_t start = clock();
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == number) {
            clock_t end = clock();
            double duration = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Number %d found at position %d in %.10f seconds (binary search).\n", number, mid, duration);
            return;
        }
        if (array[mid] < number)
            left = mid + 1;
        else
            right = mid - 1;
    }
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Number %d not found in %.10f seconds (binary search).\n", number, duration);
}

int main() {
    int option, n, number;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Initialize array with random numbers\n");
        printf("2. Display array\n");
        printf("3. Free memory\n");
        printf("4. Linear search\n");
        printf("5. Binary search\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter array size: ");
                scanf("%d", &n);
                initialize_array(n);
                break;
            case 2:
                display_array();
                break;
            case 3:
                free_memory();
                break;
            case 4:
                printf("Enter the number to search: ");
                scanf("%d", &number);
                linear_search(number);
                break;
            case 5:
                printf("Enter the number to search: ");
                scanf("%d", &number);
                binary_search(number);
                break;
            case 0:
                free_memory();
                printf("Program terminated.\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 0);
    return 0;
}*/
//Problema 2
/*void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_pos]) {
                min_pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_pos];
        arr[min_pos] = temp;
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000000;
}

double measure_time(void (*sort_function)(int[], int), int arr[], int n) {
    clock_t start, end;
    double cpu_time;
    int *copy = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        copy[i] = arr[i];

    start = clock();
    sort_function(copy, n);
    end = clock();

    free(copy);
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time;
}

int main() {
    int sizes[] = {100, 1000, 10000, 100000, 1000000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);
    double selection_times[num_sizes];
    double heap_times[num_sizes];

    srand(time(NULL));

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        generate_random_array(arr, n);

        selection_times[i] = measure_time(selection_sort, arr, n);
        heap_times[i] = measure_time(heap_sort, arr, n);

        free(arr);
    }

    printf("| N               | 100       | 1000      | 10000     | 100000    | 1000000   |\n");
    printf("|-----------------|-----------|-----------|-----------|-----------|-----------|\n");
    printf("| Selection Sort  | ");
    for (int i = 0; i < num_sizes; i++)
        printf("%.6f | ", selection_times[i]);
    printf("\n| Heap Sort       | ");
    for (int i = 0; i < num_sizes; i++)
        printf("%.6f | ", heap_times[i]);
    printf("\n");

    return 0;
}
*/


//problema 3

/*
int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary_search(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == key) {
            return middle;
        }
        if (arr[middle] < key) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

void generate_random_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void sort_array(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
}

double measure_search_time(int (*search_function)(int[], int, int), int arr[], int n, int search_count) {
    clock_t start, end;
    double total_time = 0;

    for (int i = 0; i < search_count; i++) {
        int key = rand() % 100000;
        start = clock();
        search_function(arr, n, key);
        end = clock();
        total_time += ((double)(end - start)) / CLOCKS_PER_SEC;
    }

    return total_time;
}

int main() {
    int sizes[] = {100, 1000, 10000, 100000, 1000000};  // Am adăugat 1.000.000
    int size_count = sizeof(sizes) / sizeof(sizes[0]);
    int search_count = 10000;
    double linear_times[size_count];
    double binary_times[size_count];

    srand(time(NULL));

    for (int i = 0; i < size_count; i++) {
        int n = sizes[i];
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Eroare la alocarea memoriei pentru n = %d\n", n);
            return 1;
        }

        generate_random_array(arr, n);

        linear_times[i] = measure_search_time(linear_search, arr, n, search_count);

        sort_array(arr, n);
        binary_times[i] = measure_search_time(binary_search, arr, n, search_count);

        free(arr);
    }

    printf("| N               | 100       | 1000      | 10000     | 100000    | 1000000   |\n");
    printf("|-----------------|-----------|-----------|-----------|-----------|-----------|\n");
    printf("| Linear Search   | %.6f | %.6f | %.6f | %.6f | %.6f |\n",
           linear_times[0], linear_times[1], linear_times[2], linear_times[3], linear_times[4]);
    printf("| Binary Search   | %.6f | %.6f | %.6f | %.6f | %.6f |\n",
           binary_times[0], binary_times[1], binary_times[2], binary_times[3], binary_times[4]);

    return 0;
}
*/
