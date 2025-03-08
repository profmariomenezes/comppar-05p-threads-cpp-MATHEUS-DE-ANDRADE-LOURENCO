# include <iostream>
# include <thread>
# include <vector>
# include <mutex>
# include <random>

void multiplicaLinha(int m1[3][3], int m2[3][3], int resultado[3][3], int linha) {
    for(int i = 0; i < 3; i++) {
        resultado[i][j] = 0;
        for(int j = 0; j < 3; j++) {
            resultado[i][j] += m1[linha][i] * m2[j][linha];
        } 
    }
}

int main() {
    // Variáveis para as matrizes
    int m1[3][3], m2[3][3]; 
    int resultado[3][3] = {0};

    // Vetor de threads
    int num_threads = 3;
    std::vector<std::thread> threads;

    for(int i = 0; i < num_threads; i++) {
        threads.push_back(std::thread(multiplicaLinha, m1, m2, resultado, i));
    }

    for(auto &t: threads) {
        t.join();
    }

    for(int i = 0; i < 3; i++) {
        std::cout << "\n" << std::endl;
        for(int j = 0; j < 3; j++) {
            std::cout << resultado[i][j] << " " << std::endl;
        }
    }
}