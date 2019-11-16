# lzw-file-compressor
![GitHub](https://img.shields.io/github/license/gustavooquinteiro/lzw-file-compressor?color=purple&style=flat-square) ![C++ Version](https://img.shields.io/badge/C++-8.3.0-blue.svg?style=flat-square&logo=c%2B%2B) ![Tested in](https://img.shields.io/badge/tested%20in-linux--64%20-orange)

Compactador de arquivos utilizando o algoritmo LZW desenvolvido por Daniel Lopes dos Santos e Gustavo Oliveira Quinteiro. 

## Descritivo do Trabalho  
O foco do trabalho será no método de compressão. Podendo-se assumir que todas as estruturas de dados necessárias podem ser armazenadas na memória principal. Somente podem ser utilizados recursos da linguagem de programação escolhida e bibliotecas comumente disponíveis com a linguagem. Não podem ser utilizadas bibliotecas específicas relacionadas a compressão.  

## Decisões da Equipe
* Utilização do algoritmo de compressão e descompressão [LZW (Lempel-Ziv-Welch)](https://pt.wikipedia.org/wiki/LZW) visto em sala   
* Utilização da linguagem C++ para a implementação do algoritmo  
* Tamanho máximo da tabela igual a 2<sup>15</sup> - 1, ou seja, **32767 posições**  
* Inicialização de codificação em 9 bits e aumento dessa codificação, se necessário, até alcançar o valor máximo da tabela (a váriavel ```tamanho_maximo```, na classe ```LZW```)

> Quando o programa é iniciado pela primeira vez, o código máximo possível que o programa pode emitir é 256, que precisa apenas de nove bits para codificar. E cada vez que emitimos um novo símbolo, esse valor máximo possível do código aumenta apenas um, o que significa que os primeiros 256 códigos emitidos pelo codificador podem caber em nove bits.
>
> Portanto, o codificador LZW começa a codificar usando larguras de código de nove bits e depois aumenta o valor para dez assim que o código de saída mais alto possível atingir 512. Esse processo continua, incrementando o tamanho do código até que o tamanho máximo do código seja atingido. Nesse ponto, o tamanho do código permanece fixo, pois nenhum novo código está sendo adicionado ao dicionário.
>
> O decodificador segue exatamente o mesmo processo - lendo no primeiro código com uma largura de nove bits e depois pulando para dez quando o código de entrada máximo possível atingir 512.

* Daniel foi designado para a codificação da função de compactação  
* Gustavo foi designado para a codificação da função de descompactação  

## Compilando o Compactador
É fornecido um Makefile para plataformas UNIX para facilitar a compilação dos arquivos.  
> Para compilá-los utilize o comando ``` make all ``` no diretório corrente ao Makefile.   

> Colocando arquivos variados no caminho ```tests/compress/``` , o Makefile é capaz de automatizar a execução da compressão, descompressão e verificação de taxa de compressão do arquivo e corretude desses arquivos com o comando ```make tests```   
