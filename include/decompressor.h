#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#define EXTENSION_ERROR "Extensão de arquivo compactado não reconhecida"
#define EXTENSION "cmp"
#define DOT "."
#define BITS 14

#include <fstream>
#include <iostream>
#include <unordered_map>
#include "file-manager.h"
#include "../src/file-manager.cpp"

using namespace std;

class Decompressor
{
    const unsigned int tamanho_maximo = (2 << BITS) - 1;
    unordered_map<unsigned int, string> simbolos;
    
    string nome_arquivo_compactado;
    string nome_arquivo_descompactado;
    string simbolo_anterior;
    unsigned int codigo;
    unsigned int proximo_codigo = 257;

    public:
        Decompressor(string filename);
        void lzwDecompression();
        ~Decompressor();
};

#endif 
