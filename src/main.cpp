#include "../include/main.h"

int main(int argc, char* argv[]){
    if (argc < 3){
        perror(USAGE_ERROR);
        exit(EXIT_FAILURE);
    } else{
        string parameter = argv[PARAMETER_POSITION];
        string file_name = argv[FILENAME_POSITION];
        if (parameter == COMPRESS_PARAMETER){
            // TODO: Chamada a função de compressão
        } else if (parameter == DECOMPRESS_PARAMETER) {
            // TODO: Chamada a função de descompressão
        } else{
            perror(PARAMETER_ERROR);
            exit(EXIT_FAILURE);
        }
    }
        
    
}
