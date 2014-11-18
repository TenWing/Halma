#edition des liens (étape finale)
LINKING=-I ../include/libMatrice -Wl,-R ../lib -L ../lib -lMatrice
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall 
EXEC=halma

all:			$(EXEC)

$(EXEC):		$(OBJ)
				$(CC) -o $@ $^ $(LINKING)

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