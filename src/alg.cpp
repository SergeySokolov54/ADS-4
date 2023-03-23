// Copyright 2021 NNTU-CS

int countPairs1(int* arr, int len, int value) {
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                k++;
            }
        }
    }
    return k;
}

int countPairs2(int* arr, int len, int value) {
    int nach = 0;
    int kon = len - 1;
    int k = 0;
    while (nach < kon) {
        for (int i = nach + 1; i <= kon; i++) {
            if (arr[nach] + arr[i] == value) {
                k++;
            }
        }
        nach++;
        for (int j = kon - 1; j >= nach; j--) {
            if (arr[kon] + arr[j] == value) {
                k++;
            }
        }
        kon--;
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

int countPairs3(int* arr, int len, int value) {
    int k = 0;
    int err = 0;
    for (int i = 0; arr[i] < value / 2; i++) {
        k += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
    }
    for (int i = 0; arr[i] == value / 2; i++) {
        err += cbinsearch(arr + i + 1, len - i - 1, value - arr[i]);
    }
    err /= 2;
    return k + err;
}
