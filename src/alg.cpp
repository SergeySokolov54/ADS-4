// Copyright 2021 NNTU-CS

int sorted(int* arr, int size) {
    int k = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;
            }
        }
    }
    return *arr;
}

int countPairs1(int *arr, int len, int value) {
  sorted(arr, len);
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
  sorted(arr, len);
    int k = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > value) {
                break;
            }
            if ((len - i) > i) {
                if (arr[i] + arr[j] == value) {
                    k += 1;
                }
                if (arr[len - i] + arr[len - j] == value) {
                    k += 1;
                }
            }
        }
    }
    return k;
}

int cbinsearch(int* arr, int size, int value) {
    sorted(arr, size);
    int c = size / 2;
    int k = -size;
    while (k != size) {
        k++;
        if (arr[c] > value) {
            c /= 2;
        } else if (arr[c] < value) {
            c += c / 2;
        } else if (arr[c] == value) {
            int a = 1;
            for (int i = c - 1; arr[i] == value; i--) {
                a += 1;
            }
            for (int i = c + 1; arr[i] == value; i++) {
                a += 1;
            }
            return a;
        }
    }
    return 0;
}

int* promejDiapazon(int* arr, int start, int end) {
    for (int j = 0; j < start - end; j++) {
        for (int i = start; i < end; i++) {
            arr[j] = arr[i];
            break;
        }
    }
    return arr;
}

int countPairs3(int *arr, int len, int value) {
  sorted(arr, len);
    int k = 0;
    for (int i = 0; i < len; i++) {
        k += cbinsearch(promejDiapazon(arr, i+1, len), len - i, value - arr[i]);
    }
    return k/2;
}
