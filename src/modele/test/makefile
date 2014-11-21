#/!\ MAKEFILE INDEPENDANT DU PROJET
########################################
#MAKEFILE DE TEST
########################################
#VARIABLES DE COMPILATION
########################################

#Compilateur
CC=gcc

#Nom de l'exécutable
EXEC=testModele

#Options de compilation
CFLAGS=-Wall

#Les options d'édition des liens
LDFLAGS=-I ../../../include/libMatrice -Wl,-R ../../../lib -L ../../../lib -lMatrice 

#Sous dossier ou sont les fichiers .c 
SOURCE_FOLDER=../source

#Recherche de tous les fichiers .c du sous dossier
SRC= $(wildcard $(SOURCE_FOLDER)/*.c)

#Création de la liste des dépendances (.o)
OBJ= $(SRC:.c=.o)

########################################
#COMMANDES D'EXECUTION
########################################

#Création de l'exécutable et TEST
all: 		 	$(EXEC) clean run

#Pour créer les .o du dossier de destination on a besoin des fichiers .c du sous dossier
$(EXEC):	 	$(OBJ)
				@$(CC) -o $@ $^ $(LDFLAGS)

#Procédure simple de compilation .c -> .o 
%.o: 			%.c
	 	 	 	@$(CC) -o $@ -c $< $(CFLAGS)

#nettoyage des .o
clean:
				@rm -rf $(SOURCE_FOLDER)/*.o

#execution
run:
				@./$(EXEC)

#suppression de l'exec
mrproper:		
				rm -rf $(EXEC)