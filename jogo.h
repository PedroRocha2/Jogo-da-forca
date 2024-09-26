#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Jogodaforca {
public:
    bool Adivinharletra(char palavra[], char jogo_atual[], char tentativa);
    string GerarPalavra();
};

bool Jogodaforca::Adivinharletra(char palavra[], char jogo_atual[], char tentativa) {
    bool encontrou = true;
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] == tentativa) {
            jogo_atual[i] = palavra[i];
        }
    }

    if (strcmp(palavra, jogo_atual) == 0) {
        cout << "Parabéns! Você adivinhou a palavra" << endl;
        encontrou = false;
    }
    return encontrou; 
}

string Jogodaforca::GerarPalavra() {
    fstream fs("palavras.txt", ios::in | ios::out | ios::trunc);
    vector<string> palavras;
    string palavra;

    if (!fs) {
        cerr << "Erro ao abrir o arquivo: " << endl;
        return "";
    }

    while (getline(fs, palavra)) {
        palavras.push_back(palavra);
    }
    fs.close();

    if (palavras.empty()) {
        cerr << "O arquivo está vazio ou não contém palavras válidas." << endl;
        return "";
    }

    srand(time(0));
    int indiceAleatorio = rand() % palavras.size();
    return palavras[indiceAleatorio];
}