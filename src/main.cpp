#include "../include/main.h"

int main(int argc, char* argv[]){
    if (argc < 3)
    {
        cerr << USAGE_ERROR;
        exit(EXIT_FAILURE);
    } else
    {
        string parameter = argv[PARAMETER_POSITION];
        if (parameter == COMPRESS_PARAMETER)
        {
            // TODO: Chamada a função de compressão
        } else if (parameter == DECOMPRESS_PARAMETER) 
        {
            string filename  = argv[FILENAME_POSITION];
            Decompressor lzw = Decompressor(filename);
            lzw.lzwDecompression();
        } else
        {
            cerr << PARAMETER_ERROR;
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}
