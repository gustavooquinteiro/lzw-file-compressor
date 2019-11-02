#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char**argv)
{
    ifstream original(argv[1], ifstream::ate | ifstream::binary);
    ifstream compressed(argv[2], ifstream::ate | ifstream::binary);
    size_t original_size = original.tellg();
    size_t compressed_size = compressed.tellg();
    if (original_size > compressed_size)
    {
        int taxa =  ((original_size - compressed_size)*100) / original_size;
        cout << "Taxa de compressão de: " << taxa << "%" << endl;
    } else if (original_size == compressed_size)
    {
        cout << "Não houve compactação entre os arquivos" << endl;
    } else
    {
        cout << "Arquivo compactado maior que o original" << endl;
    }
}
