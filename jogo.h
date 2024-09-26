#include <iostream>
#include <cstring>

using namespace std;

class Jogodaforca {
public:
    bool Adivinharletra(char palavra[], char jogo_atual[], char tentativa);
};

bool Jogodaforca::Adivinharletra(char palavra[], char jogo_atual[], char tentativa) {
    bool encontrou = false;
    for (int i = 0; i < strlen(palavra); i++) {
        if (palavra[i] == tentativa) {
            jogo_atual[i] = palavra[i];
            encontrou = true;
        }
    }

    if (strcmp(palavra, jogo_atual) == 0) {
        return false; 
    }
    return encontrou; 
}