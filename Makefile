# Nome do projeto e do executável encontrado no diretório corrente após compilação
PROJ_NAME = mata54comp

# Arquivos .c encontrados em src/
C_SOURCE = $(wildcard ./src/*.cpp)

# Arquivos .h encontrados em lib/
H_SOURCE = $(wildcard ./include/*.h)

# Arquivos objetos .o encontrados em obj/ após compilação
OBJ = $(subst .cpp,.o,$(subst src,build,$(C_SOURCE)))

# Compilador utilizado
CC = g++

# Flags utilizadas na compilação
CC_FLAGS = -c \
           -g \
           -O2 \

# Comando de construção de diretório
MKDIR = mkdir -p

# Comando de limpeza de alvos 
RM = rm -rf

GREEN=\033[0;32m
NC=\033[0m

# Regras de compilação
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ $(CC) $^ -o $@
	@ echo -e -n " [${GREEN} OK ${NC}]"
	@ echo " Binário construido: $@"

./build/%.o: ./src/%.cpp ./include/%.h
	@ $(CC) $< $(CC_FLAGS) -o $@
	@ echo -e -n " [${GREEN} OK ${NC}]"
	@ echo " Compilado $< em $@"

# Regra de criação de diretório para os objetos
objFolder:
	@ $(MKDIR) build
	@ echo -e -n " [${GREEN} OK ${NC}]"
	@ echo ' Criado diretório para objetos' 

# Regra de limpeza de objetos e executável
clean:
	@ $(RM) build $(PROJ_NAME) *~
	@ echo -e -n " [${GREEN} OK ${NC}]"
	@ echo ' Workspace limpo'

.PHONY: all clean 
