#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include "funcoes.hpp"
using namespace std;

#define ARQUIVO "estoque.txt"
#define TEMP "temp.txt"
#define MAX_ITEM 100

int main(){
    int esc;
    char c;
    string nome;
    int quantidade;

    while (true) {
        cout << "===============================\n";
        cout << "   Controle de Estoque\n";
        cout << "===============================\n";
        cout << "Selecione uma opcao:\n";
        cout << "1. Adicionar Item\n";
        cout << "2. Remover Item\n";
        cout << "3. Listar Estoque\n";
        cout << "4. Sair\n";
        cout << "Opcao: ";

        if (!(cin >> esc)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nErro: Entrada nao numerica, por favor, digite um numero\n\n";
            continue;
        }

        switch(esc){
            case 1:
                cout << "\nDigite o nome do item: ";
                cin >> nome;
                cout << "Digite a quantidade: ";
                cin >> quantidade;
                adicionar_item_arquivo(nome, quantidade);

                while (true) {
                    cout << "Deseja realizar outra operacao? (s/n): ";
                    cin >> c;
                    if(c=='s' || c=='S') { cout << "\n\n\n"; break; }
                    if(c=='n' || c=='N') { 
                        cout << "Obrigado por usar o Controle de Estoques! Ate a proxima.\n"; 
                        return 0; 
                    }
                    cout << "Resposta invalida. Por favor, digite 's' ou 'n'\n\n";
                }
                break;

            case 2:
                cout << "Digite o nome do item a remover: ";
                cin.ignore(); // descarta '\n' pendente
                getline(cin, nome);
                cout << "Digite a quantidade a remover: ";
                cin >> quantidade;
                remover_item_arquivo(nome, quantidade);
                break;

            case 3:
                listar_estoque();
                break;

            case 4:
                cout << "\nObrigado por usar o Controle de Estoques! Ate a proxima.\n";
                return 0;

            default:
                cout << "\nOpcao invalida! Tente novamente.\n\n";
        }
    }
}
