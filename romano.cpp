#include "romano.hpp"
using namespace std;

int valores(char romano){
    if (romano == 'I' ) return 1;
    if (romano == 'V' ) return 5;
    if (romano == 'X' ) return 10;
    if (romano == 'L' ) return 50;
    if (romano == 'C' ) return 100;
    if (romano == 'D' ) return 500;
    if (romano == 'M' ) return 1000;

    return -1;
}


int converter(string numero){
    int soma = 0;
    vector<int> decimal;
    if (numero.size() > 30) return -1;
    for (int i=1; i < numero.size(); i++) {
        int atual = valores(numero[i]);
        if (atual<0) return -1;
        int antecessor = valores(numero[i-1]);
        if(atual > antecessor){
            antecessor = (antecessor) * (-1);
        }
        decimal.push_back(antecessor);
        if(i == (numero.size() - 1)){
            decimal.push_back(atual);
        }
    }

    for (int i=0 ; i < decimal.size(); i++) {
        soma = soma + decimal[i];
    }

    return soma;
}

string contrario(int decimal) {
    string simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int decimais_romanos[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romano;
    int i = 0;    
    while (decimal > 0) {
      int div = decimal/decimais_romanos[i];
      decimal = decimal%decimais_romanos[i];
      while(div--) romano += simbolos[i];
      i+=1;
    }
    return romano;
}

int validar(string numero){
    int decimal = converter(numero);
    string confere = contrario(decimal); 
    if (confere == numero && decimal < 3001) {
        return decimal;
    } return -1;

}