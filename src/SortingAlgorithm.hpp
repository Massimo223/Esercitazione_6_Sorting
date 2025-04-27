#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <gtest/gtest.h> 

using namespace std;

template<typename T>
void BubbleSort(vector<T>& v) {
	for(size_t i = 0; i <= v.size() - 2; i++) {
		for(size_t j = i + 1; j <= v.size() - 1; j++) {
			if(v[j] < v[i]) {
				swap(v[j],v[i]);
			}
		}
	}
}

template<typename T>
void heapify(vector<T>& v, int heap_size, int root_index) {
    int largest = root_index;
    int left_child = 2 * root_index + 1;
    int right_child = 2 * root_index + 2;

    if (left_child < heap_size && v[left_child] > v[largest]) {
        largest = left_child;
    }

    if (right_child < heap_size && v[right_child] > v[largest]) {
        largest = right_child;
    }

    if (largest != root_index) {
        swap(v[root_index], v[largest]);
        heapify(v, heap_size, largest); // 🔥 ricorsione giusta
    }
}

template<typename T>
void HeapSort(vector<T>& v) {
    int n = v.size();

    // Costruisci il Max-Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(v, n, i);
    }

    // Estrai elementi uno a uno dal Max-Heap
    for (int i = n - 1; i > 0; i--) {
        swap(v[0], v[i]);      // Porta il massimo alla fine
        heapify(v, i, 0);      // Ricostruisci heap per la parte rimanente
    }
}




