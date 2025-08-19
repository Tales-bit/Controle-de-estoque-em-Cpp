#include "funcoes.hpp"
#include <iostream>
#include <limits>
#include <fstream>
#include <string>

#define ARQUIVO "estoque.txt"
#define TEMP "temp.txt"
#define MAX_ITEM 100

using namespace std;

void adicionar_item_arquivo(const string& s, int q){
    ofstream arquivo(ARQUIVO, ios::app); // append
    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!\n";
        return;
    }
    arquivo << s << endl;
    arquivo << q << endl;
    arquivo.close();
    cout << "Item adicionado com sucesso\n\n";
}

void listar_estoque() {
    ifstream arquivo(ARQUIVO);
    if (!arquivo) {
        cout << "\nErro ao abrir o arquivo\n\n";
        return;
    }

    cout << "\n===============================\n";
    cout << "   Estoque atual\n";
    cout << "===============================\n";

    arquivo.seekg(0, ios::end);
    if (arquivo.tellg() == 0) {
        cout << "O estoque esta vazio\n\n";
        return;
    }
    arquivo.seekg(0, ios::beg);

    string linha;
    int contagem = 0;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;
        if (contagem % 2 == 0) {
            cout << "Nome: " << linha << "\n";
        } else {
            cout << "Quantidade: " << linha << "\n";
        }
        contagem++;
    }
    arquivo.close();
    cout << endl;
}

// Função para remover item
void remover_item_arquivo(const string& nomeItem, int qtdRemover) {
    ifstream arquivo(ARQUIVO);
    ofstream temp(TEMP);
    if (!arquivo || !temp) {
        cout << "Erro ao abrir os arquivos.\n";
        return;
    }

    string linhaItem;
    string linhaQtd;
    bool encontrado = false;

    while (getline(arquivo, linhaItem) && getline(arquivo, linhaQtd)) {
        int qtd = stoi(linhaQtd);

        if (linhaItem == nomeItem) {
            encontrado = true;

            if (qtdRemover <= qtd) {
                int novaQtd = qtd - qtdRemover;
                if (novaQtd > 0) {
                    temp << linhaItem << "\n" << novaQtd << "\n";
                    cout << "Quantidade atualizada com sucesso!\n";
                } else {
                    cout << "Item removido do estoque.\n";
                    // não escreve no arquivo temporário, item removido
                }
            } else {
                temp << linhaItem << "\n" << qtd << "\n";
                cout << "Estoque insuficiente. Quantidade disponível: " << qtd << "\n";
            }
        } else {
            temp << linhaItem << "\n" << qtd << "\n";
        }
    }

    arquivo.close();
    temp.close();

    if (!encontrado) {
        cout << "Item nao encontrado.\n";
        remove(TEMP);
    } else {
        remove(ARQUIVO);
        rename(TEMP, ARQUIVO);
    }
}