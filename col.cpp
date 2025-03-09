# include <iostream>
# include <thread>
# include <vector>
# include <mutex>
# include <random>
# include <chrono>

void multiplicaColuna(int m1[500][500], int m2[500][500], int resultado[500][500], int coluna) {
    for (int linha = 0; linha < 500; linha++) {
        resultado[linha][coluna] = 0;
        for (int k = 0; k < 500; k++) {
            resultado[linha][coluna] += m1[linha][k] * m2[k][coluna];
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
            m1[j][i] = distrib(gen);
            m2[j][i] = distrib(gen);
        }
    }

    

    // Vetor de threads
    int num_threads = 500;
    std::vector<std::thread> threads;

    for(int i = 0; i < num_threads; i++) {
        threads.push_back(std::thread(multiplicaColuna, m1, m2, resultado, i));
    }

    for(auto &t: threads) {
        t.join();
    }

    auto fim = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duracao = fim - inicio;
    std::cout << "Tempo de execução: " << duracao.count() << " segundos" << std::endl;

    
}