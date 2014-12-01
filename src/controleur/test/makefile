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
LDFLAGS= -Wl,-R ../../../lib -L ../../../lib -lMatrice

#Dossiers où se trouvent les .h des librairies externes /Rapport au makefile
LIBINCLUDEPATH=-I ../../../include/libMatrice

#Dossiers où se trouvent les .h des sources /Rapport au makefile
INCLUDEPATH=-I ../header -I ../../modele/header -I ../../vue/header

#Sous dossier ou sont les fichiers .c  
SOURCE_FOLDER=../source
MODEL_FOLDER=../../modele/source
VUE_FOLDER=../../vue/source

#Recherche de tous les fichiers .c du sous dossier
SRC= $(wildcard $(SOURCE_FOLDER)/*.c)

#le contrôleur a besoin du modèle pour compiler
MODEL_C= $(wildcard $(MODEL_FOLDER)/*.c)

#le contrôleur a besoin de la vue pour compiler
VUE_C = $(wildcard $(VUE_FOLDER)/*.c)

#Recherche le main de test
TEST= $(wildcard *.c)

#Création de la liste des dépendances (.o)
OBJ= $(SRC:.c=.o)
MAIN= $(TEST:.c=.o)
MODEL=$(MODEL_C:.c=.o)
VUE=$(VUE_C:.c=.o)

########################################
#COMMANDES D'EXECUTION
########################################

#Création de l'exécutable et TEST
all: 		 	$(EXEC) clean run

#Pour créer les .o du dossier de destination on a besoin des fichiers .c du sous dossier
$(EXEC):	 	$(OBJ) $(MAIN) $(MODEL) $(VUE)
				@$(CC) -o $@ $^ $(LIBINCLUDEPATH) $(LDFLAGS)

#Procédure simple de compilation .c -> .o 
%.o: 			%.c
	 	 	 	@$(CC) -o $@ -c $< $(CFLAGS) $(INCLUDEPATH) $(LIBINCLUDEPATH)

#nettoyage des .o
clean:
				@rm -rf $(MODEL_FOLDER)/*.o
				@rm -rf $(SOURCE_FOLDER)/*.o
				@rm -rf *.o

#execution
run:
				@./$(EXEC)

#suppression de l'exec
mrproper:		
				@rm -rf $(EXEC)