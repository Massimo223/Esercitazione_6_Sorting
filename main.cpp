#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  
#include "src/SortingAlgorithm.hpp"  

using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <dimensione_vettore>" << endl;
        return 1;
    }

   
    int n = atoi(argv[1]); 
    vector<int> vec(n);

   
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 1000;  
    }

    
    auto start = high_resolution_clock::now();
    BubbleSort(vec);  
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "BubbleSort ha impiegato " << duration.count() << " millisecondi" << endl;

    
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 1000;
    }

   
    start = high_resolution_clock::now();
    HeapSort(vec);  
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "HeapSort ha impiegato " << duration.count() << " millisecondi" << endl;
	return 0;
};
