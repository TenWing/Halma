########################################
#RECUPERATION DES FICHIERS DU DOSSIER
########################################
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

#Commande d'exécution
all: 		 $(EXEC)

#Listage de tous les fichiers objets du dossier et compilation
$(EXEC):	 $(OBJ)

#Procédure simple de compilation .c -> .o
%.o: 		 %.c
	 	 	 @$(CC) -o $@ -c $< $(CFLAGS)

#efface TOUT
mrproper:	
			 @rm -rf *.o