# include <iostream>
# include <thread>
# include <mutex>

void multiplicaLinha(int m1[3][3], int m2[3][3], int resultado[3][3], int linha) {
    for(int i = 0; i < 3; i++) {
        resultado[linha] += m1[linha][i]     
    }
}

int main() {
    // Variáveis para as matrizes
    int m1[3][3], m2[3][3], int resultado[3][3];

    // Vetor de threads
    int num_threads = 3;
    std::threads<std::thread> threads;

    for(int i = 0; i < num_threads; i++) {
        threads.push_back(std::thread())
    }

}