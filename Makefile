# Makefile para o projeto Árvore Binária
# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -Wall -Wextra -std=c99 -g

# Nome do executável
TARGET = arvore_binaria

# Arquivos fonte
SOURCES = main.c ArvoreBinaria.c

# Arquivos objeto
OBJECTS = $(SOURCES:.c=.o)

# Regra principal
all: $(TARGET)

# Compilação do executável
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "✅ Compilação concluída! Execute com: ./$(TARGET)"

# Compilação dos arquivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJECTS) $(TARGET)
	@echo "🧹 Arquivos limpos!"

# Compilação e execução
run: $(TARGET)
	./$(TARGET)

# Regra para Windows
windows:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET).exe
	@echo "✅ Compilação para Windows concluída! Execute com: $(TARGET).exe"

# Regras que não correspondem a arquivos
.PHONY: all clean run windows
