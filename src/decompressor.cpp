#include "../include/decompressor.h" 

Decompressor::Decompressor(string filename)
{
    nome_arquivo_compactado = filename;
    int posicao = filename.find(DOT);
    nome_arquivo_descompactado = filename.substr(0, posicao);
    string extensao = filename.substr(posicao + 1);
    if (extensao != EXTENSION)
    {
        cerr << EXTENSION_ERROR;
        exit(EXIT_FAILURE);
    }
    
}

void Decompressor::lzwDecompression()
{
  
    ifstream arquivo(nome_arquivo_compactado);
    InputStream arquivo_compactado(arquivo, tamanho_maximo);    
    
    ofstream arquivo_final(nome_arquivo_descompactado);
    OutputStream arquivo_descompactado(arquivo_final);
    
    int size = (tamanho_maximo * 11) / 10;
    unordered_map<unsigned int, string> simbolos(size);
    
    for (unsigned int i = 0; i < 256; i++)
        simbolos[i] = string(1, i);
    
    string simbolo_anterior;
    unsigned int codigo;
    unsigned int proximo_codigo = 257;
    while(arquivo_compactado >> codigo)
    {
        /**
         * Caso em que o código do simbolo descoberto não está no dicionário
         **/
        if(simbolos.find(codigo) == simbolos.end())
            simbolos[codigo] = simbolo_anterior + simbolo_anterior[0];
        
        arquivo_descompactado << simbolos[codigo];
        
        /**
         * Caso em que o código do simbolo descoberto esteja muito a frente no dicionário
         **/
        if (simbolo_anterior.size() && proximo_codigo <= tamanho_maximo)
            simbolos[proximo_codigo++] = simbolo_anterior + simbolos[codigo][0];
        simbolo_anterior = simbolos[codigo];
    }
}

Decompressor::~Decompressor(){}

