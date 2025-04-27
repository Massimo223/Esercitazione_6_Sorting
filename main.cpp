#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // per generare numeri casuali
#include "src/SortingAlgorithm.hpp"  // Assicurati che il file contenga le definizioni di BubbleSort e HeapSort

using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    // Verifica che sia stato passato l'argomento della dimensione del vettore
    if (argc != 2) {
        cout << "Uso: " << argv[0] << " <dimensione_vettore>" << endl;
        return 1;
    }

    // Ottieni la dimensione del vettore dalla linea di comando
    int n = atoi(argv[1]);  // Converte l'argomento in un intero
    vector<int> vec(n);

    // Genera un vettore casuale di dimensione n
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 1000;  // Numeri casuali tra 0 e 999
    }

    // Misura il tempo per il BubbleSort
    auto start = high_resolution_clock::now();
    BubbleSort(vec);  // Chiamata alla funzione BubbleSort
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "BubbleSort ha impiegato " << duration.count() << " millisecondi" << endl;

    // Rigenera il vettore casuale per evitare di testare il vettore già ordinato
    for (int i = 0; i < n; i++) {
        vec[i] = rand() % 1000;
    }

    // Misura il tempo per l'HeapSort
    start = high_resolution_clock::now();
    HeapSort(vec);  // Chiamata alla funzione HeapSort
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    cout << "HeapSort ha impiegato " << duration.count() << " millisecondi" << endl;
	return 0;
};
