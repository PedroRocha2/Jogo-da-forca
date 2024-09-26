#include <iostream>
#include <cstring>
#include "jogo.h"

using namespace std;

int main() {
    string palavraSorteada;
    char *p_palavrasorteada, *jogo_atual;
    char tentativa;
    bool resultado = true;

    cout << "Escolha uma palavra: ";
    cin >> palavraSorteada;

    p_palavrasorteada = new (nothrow) char[palavraSorteada.length() + 1];
    if (p_palavrasorteada == nullptr) {
        cerr << "Erro ao alocar memória para a palavra sorteada." << endl;
        return 1;
    }
    strcpy(p_palavrasorteada, palavraSorteada.c_str());
  
    jogo_atual = new (nothrow) char[palavraSorteada.length() + 1];
    if (jogo_atual == nullptr) {
        cerr << "Erro ao alocar memória para o array de tentativas." << endl;
        delete[] p_palavrasorteada;
        return 1;
    }
    for (size_t i = 0; i < palavraSorteada.length(); ++i) {
        jogo_atual[i] = '_';
    }
    jogo_atual[palavraSorteada.length()] = '\0';

    Jogodaforca f;
    while (resultado) {
        cout << "Adivinhe uma letra: ";
        cin >> tentativa;
        resultado = f.Adivinharletra(p_palavrasorteada, jogo_atual, tentativa);
        cout << "Estado atual: " << jogo_atual << endl;
    }

    delete[] p_palavrasorteada;
    delete[] jogo_atual;

    return 0;
}