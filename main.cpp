#include <iostream>

using namespace std;

class item{
    string nome;
    int quantidade;
public:
    item(string s, int x){
        quantidade=x;
        nome=s;
    }
    string get_nome(){
        return nome;
    }
    int get_quantidade(){
        return quantidade;
    }
};

int main(){
    int loop;
}