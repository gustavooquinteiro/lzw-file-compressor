#include <iostream>
#include <fstream>
using namespace std;

bool kilo;
bool mega;
bool giga;

void reset()
{
    kilo = false;
    mega = false;
    giga = false;
}

double converter(size_t tamanho)
{
    reset();
    double valor = 0; 
    if (tamanho >= 1024 && tamanho < 1048576){
        kilo = true;
        valor = tamanho * 0.00097656;
    } else if (tamanho >= 1048576 && tamanho < 1073741824){
        mega = true;
        valor = tamanho * 0.00000095;
    } else if (tamanho >= 1073741824) {
        giga = true;
        valor = tamanho * 0.00000000093;
    } else{
        valor = tamanho;
    }
    return valor;
}


int main(int argc, char**argv)
{
    ifstream original(argv[1], ifstream::ate | ifstream::binary);
    ifstream compressed(argv[2], ifstream::ate | ifstream::binary);
    
    size_t original_size = original.tellg();
    size_t compressed_size = compressed.tellg();
    
    cout << "_______________________________________________________________" << endl;
    cout <<"|Nome do arquivo   |   Tamanho do arquivo" << endl;
    cout <<"| "<< argv[1] << " | " << converter(original_size) << ((kilo)?"Kib":(mega)?"Mib": (giga)?"Gib":"b") <<endl;
    cout <<"| "<< argv[2] << " | " << converter(compressed_size) << ((kilo)?"Kib":(mega)?"Mib": (giga)?"Gib":"b")<< endl;
    cout << "_______________________________________________________________" << endl;
    
    if (original_size > compressed_size)
    {
        int taxa =  ((original_size - compressed_size)*100) / original_size;
        cout << "Taxa de compressão de: " << taxa << "%" << endl;
    } else if (original_size == compressed_size)
    {
        cout << "Não houve compactação entre os arquivos" << endl;
    } else
    {
        cout << "Arquivo compactado maior que o original: Aumento de  " << converter(compressed_size - original_size) << ((kilo)?"Kib":(mega)?"Mib": (giga)?"Gib":"b") << endl;
    }
}
