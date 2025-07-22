# Define o compilador C++
CXX = g++

# Define as flags de compilação
# -Wall: habilita todos os avisos
# -g: inclui informações de depuração
# -std=c++11: define o padrão C++11 (se você estiver usando recursos dele)
CXXFLAGS = -Wall -g -std=c++11

# Define os arquivos de cabeçalho (adicione todos os seus .h aqui)
HEADERS = Funcionario.h Desenvolvedor.h Gerente.h Estagiario.h

# Define os arquivos fonte (adicione todos os seus .cpp aqui)
SOURCES = Funcionario.cpp Desenvolvedor.cpp Gerente.cpp Estagiario.cpp main.cpp

# Gera uma lista de arquivos objeto (.o) a partir dos arquivos fonte
OBJECTS = $(SOURCES:.cpp=.o)

# Define o nome do executável final (garanta que seja o mesmo do tasks.json)
TARGET = ativ_dois.exe

# Regra padrão: compila o executável
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)

# Regra para compilar arquivos .cpp em .o
# O $< se refere ao primeiro pré-requisito (o arquivo .cpp)
# O $@ se refere ao alvo (o arquivo .o)
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados (executáveis e objetos)
clean:
	rm -f $(TARGET) $(OBJECTS)