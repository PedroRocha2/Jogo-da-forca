#include <iostream>
#include <vector>
#include "jogo.hpp"

using namespace std;

int main() {
    Jogodaforca f;
    string p_palavrasorteada;
    vector <char> jogo_atual;
    char tentativa;
    bool resultado {true};

    p_palavrasorteada = f.GerarPalavra();

    jogo_atual.resize(p_palavrasorteada.size(), '_');

   while (resultado) {
        cout << "Adivinhe uma letra: ";
        cin >> tentativa;
        resultado = f.Adivinharletra(p_palavrasorteada, jogo_atual, tentativa);

        cout << "Estado atual: ";
        for (char c : jogo_atual) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}