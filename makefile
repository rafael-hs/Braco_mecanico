all: pilha.o arquivo.o
		gcc -o arquivo *.o
		
pilha.o: pilha.c
		gcc -c pilha.c
		
arquivo.o: arquivo.c
		gcc -c arquivo.c
		
clean:
		rm -f *.o arquivo
