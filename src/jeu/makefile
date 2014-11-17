CC=gcc
CFLAGS=-Wall -I ../../include/libMatrice -Wl,-R ../../lib -lMatrice
LDFLAGS=
EXEC= halma

all:			$(EXEC)

halma:			main.o
				$(CC) -o $@ $^ $(CFLAGS)

#procédure simple de compilation de .c -> .o
%.o: 			%.c
				$(CC) -o $@ -c $< $(CFLAGS)

#destruction des fichiers temporaires
clean:	
				rm -rf *.o 

#supprime tout pour repartir de 0
mrproper:
				rm -rf *.o
				rm  -rf $(EXEC)