#include "../include/decompressor.h" 

Decompressor::Decompressor(string filename)
{
    int posicao = filename.find(DOT);
    string extensao = filename.substr(posicao + 1);
    if (extensao != EXTENSION)
    {
        perror(EXTENSION_ERROR);
        exit(EXIT_FAILURE);
    }
    
    this->filename = filename;
}

void Decompressor::lzwDecompression()
{
    for (unsigned int i = 0; i < 256; i++)
        simbolos[i] = string(1, i);
    
    while(proximo_codigo < 300) // condição de loop errada
    {
        /**
         * Caso em que o código do simbolo descoberto está no dicionário
         **/
        if(simbolos.find(codigo) != simbolos.end())
        {
            simbolos[codigo] = simbolo_anterior + simbolo_anterior[0];
        }

        /**
         * Caso em que o código do simbolo descoberto não está no dicionário
         **/
        if (simbolo_anterior.size() && proximo_codigo <= tamanho_maximo)
        {
            simbolos[proximo_codigo++] = simbolo_anterior + simbolos[codigo][0];
        }
        simbolo_anterior = simbolos[codigo];
        proximo_codigo++;
    }
}

Decompressor::~Decompressor()
{

}

