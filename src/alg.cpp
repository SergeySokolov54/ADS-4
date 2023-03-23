// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
        }
    }
    return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > value) {
            break;
        }
        for (int j = i + 1; j < len; j++) {
            if (arr[j] > value - arr[i]) {
                break;
            }
            if (arr[i] + arr[j] == value) {
                k += 1;
            }
        }
    }
    return k;
}

int cbinsearch(int* arr, int size, int value) {
    int nach = 0;
    int kon = size - 1;
    while (nach <= kon) {
        int promej = nach + (kon - nach) / 2;
        if (value == arr[promej]) {
            int k = 0;
            int err = promej - 1;
            while (value == arr[promej]) {
                promej++;
                k++;
            }
            while (value == arr[err]) {
                err--;
                k++;
            }
            return k;
        } else if (value < arr[promej]) {
            kon = promej - 1;
        } else {
            nach = promej + 1;
        }
    }
    return 0;
}

int countPairs3(int *arr, int len, int value) {
    int i = 0;
    int k = 0;
    int err = 0;
    for (i = 0; arr[i] < value / 2; i++) {
        k += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
    }
    for (i = 0; arr[i] == value / 2; i++) {
        err += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
    }
    err /= 2;
    return k + err;
}
