#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#define EXTENSION_ERROR "Extensão de arquivo compactado não reconhecida"
#define EXTENSION "cmp"
#define DOT "."

#include <fstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class Decompressor
{
    const unsigned int tamanho_maximo = 32767;
    unordered_map<unsigned int, string> simbolos;
    
    ifstream* arquivo_compactado;    
    ofstream* arquivo_descompactado;
    
    string simbolo_anterior;
    unsigned int codigo;
    unsigned int proximo_codigo = 257;

    public:
        Decompressor(string filename);
        void lzwDecompression();
        ~Decompressor();
};

#endif 
