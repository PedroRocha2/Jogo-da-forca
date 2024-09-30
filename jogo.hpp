#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Jogodaforca {
public:
    bool Adivinharletra(const string &palavra, vector<char> &jogo_atual, char tentativa);
    
    string GerarPalavra();
};

string Jogodaforca::GerarPalavra() {
    vector<string> lines;
    string line;
    ifstream myfile ("palavras.txt");

    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            lines.push_back(line);
        }
        myfile.close();

        if (!lines.empty()) {
            srand(time(0)); 
            int randomIndex = rand() % lines.size();
            return lines[randomIndex];
        } else {
            return "O arquivo está vazio.";
        }
    } else {
        return "Unable to open file";
    }
}

bool Jogodaforca::Adivinharletra(const string &palavra, vector<char> &jogo_atual, char tentativa) {
    bool encontrou = true;
    for (size_t i = 0; i < palavra.size(); i++) {
        if (palavra[i] == tentativa) {
            jogo_atual[i] = palavra[i];
            encontrou = true;
        }
    }

    if (string(jogo_atual.begin(), jogo_atual.end()) == palavra) {
        return false; 
    }
    return encontrou; 
}
