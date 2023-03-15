#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& v, int left, int mid, int right) {
    vector<int> tmp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    cout << "??" << endl;

    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            tmp[k] = v[i];
            i++;
        }
        else {
            tmp[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        tmp[k] = v[i];
        i++;
        k++;
    }

    while (j <= right) {
        tmp[k] = v[j];
        j++;
        k++;
    }

    for (int l = 0; l < k; l++) {
        v[left + l] = tmp[l];
    }
}

void merge_insertion_sort(vector<int>& v, int left, int right) {
    int threshold = 10; // threshold for using insertion sort
    if (left < right) {
        if (right - left <= threshold) {
            for (int i = left + 1; i <= right; i++) {
                int key = v[i];
                int j = i - 1;
                while (j >= left && v[j] > key) {
                    v[j + 1] = v[j];
                    j--;
                }
                v[j + 1] = key;
            }
        }
        else {
            int mid = (left + right) / 2;
            merge_insertion_sort(v, left, mid);
            merge_insertion_sort(v, mid + 1, right);
            merge(v, left, mid, right);
        }
    }
}

void merge_insertion_sort(vector<int>& v) {
    merge_insertion_sort(v, 0, v.size() - 1);
}

int main() {
    vector<int> test;
    vector<int> test2;
    // v.push_back(10);
    // v.push_back(7);
    // v.push_back(8);
    // v.push_back(9);
    // v.push_back(1);
    // v.push_back(5);

			srand(time(NULL));
			for (int i = 0; 100 > i; i++)
			{
				const int value = rand();
				test.push_back(value);
				test2.push_back(value);
			}

    int n = test.size();

    merge_insertion_sort(test);
    sort(test2.begin(), test2.end());

    // cout << "Sorted array: ";
    // for (int i = 0; i < n; i++)
    //     cout << test[i] << " ";
    // cout << endl;

    // cout << "Sorted array: ";
    // for (int i = 0; i < n; i++)
    //     cout << test2[i] << " ";
    // cout << endl;

    return 0;
}