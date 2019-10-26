#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <iostream>
#include <unordered_map>
using namespace std;

class Decompressor
{
    const unsigned int tamanho_maximo = 32767;
    unordered_map<unsigned int, string> simbolos;
    string simbolo_anterior;
    unsigned int codigo;
    unsigned int proximo_codigo = 257;

    public:
    Decompressor();
    ~Decompressor();


};

#endif 
