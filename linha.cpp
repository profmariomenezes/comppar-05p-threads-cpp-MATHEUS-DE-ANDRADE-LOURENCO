# include <iostream>
# include <thread>
# include <vector>
# include <mutex>
# include <random>
# include <chrono>

void multiplicaLinha(int m1[500][500], int m2[500][500], int resultado[500][500], int linha) {
    for(int j = 0; j < 500; j++) {
        resultado[linha][j] = 0;
        for(int k = 0; k < 500; k++) {
            resultado[linha][j] += m1[linha][k] * m2[k][j];
        }
    }
}

int main() {

    auto inicio = std::chrono::high_resolution_clock::now();

    // Variáveis para as matrizes
    int m1[500][500], m2[500][500]; 
    int resultado[500][500] = {0};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);

    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            m1[i][j] = distrib(gen);
            m2[i][j] = distrib(gen);
        }
    }

    // Vetor de threads
    int num_threads = 500;
    std::vector<std::thread> threads;

    for(int i = 0; i < num_threads; i++) {
        threads.push_back(std::thread(multiplicaLinha, m1, m2, resultado, i));
    }

    for(auto &t: threads) {
        t.join();
    }

    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracao = fim - inicio;
    std::cout << "Tempo de execução: " << duracao.count() << " segundos" << std::endl;
}