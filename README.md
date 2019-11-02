# lzw-file-compressor
![GitHub](https://img.shields.io/github/license/gustavooquinteiro/lzw-file-compressor?color=purple&style=flat-square) ![C++ Version](https://img.shields.io/badge/C++-8.3.0-blue.svg?style=flat-square&logo=c%2B%2B) ![GitHub top language](https://img.shields.io/github/languages/top/gustavooquinteiro/lzw-file-compressor?color=red&style=flat-square) ![Tested in](https://img.shields.io/badge/tested%20in-linux--64%20-orange)

Compactador de arquivos LZW

## :clipboard: Descritivo do Trabalho  
O foco do trabalho será no método de compressão. Podendo-se assumir que todas as estruturas de dados necessárias podem ser armazenadas na memória principal.
Somente podem ser utilizados recursos da linguagem de programação escolhida e bibliotecas comumente disponíveis com a linguagem. Não podem ser utilizadas bibliotecas
específicas relacionadas a compressão.

## :outbox_tray: Especificação da Saída
O programa deverá ter o nome ``` mata54comp ``` e terá dois parâmetros: o primeiro indicará a **operação** (compressão ou descompressão); o segundo indicará o **nome do arquivo**, da forma abaixo:  

* mata54comp -c nome-arquivo  

Formato para comprimir o arquivo ```nome-arquivo ```. O arquivo **poderá ter qualquer nome e extensão**. O nome do arquivo comprimido gerado deverá ser o nome do arquivo de entrada acrescido do sufixo (extensão) ".cmp".  

* mata54comp -d nome-arquivo  

Formato para descomprimir o arquivo ```nome-arquivo ```. O arquivo passado como parâmetro **deve ter a extensão ".cmp"**. O nome do arquivo descomprimido gerado deve ser o nome do arquivo sem a extensão ".cmp".

## :busts_in_silhouette: Decisões da Equipe
* Utilização do algoritmo de compressão e descompressão [LZW (Lempel-Ziv-Welch)](https://pt.wikipedia.org/wiki/LZW) 
* Utilização da linguagem C++ para a implementação do algoritmo  

## :pushpin: Restrições do Compactador
* Os nomes dos arquivos **não podem** conter espaços 

## :gear: Compilando o Compactador
É fornecido um [Makefile para plataformas UNIX](Makefile) para facilitar a compilação dos arquivos.  
> Para compilá-los utilize o comando ``` make all ``` no diretório corrente ao Makefile. 
