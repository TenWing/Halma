########################################
#VARIABLES DE COMPILATION
########################################

#Sous dossier ou sont les fichiers .c 
SOURCE_FOLDER=source

#Recherche de tous les fichiers .c du sous dossier
SRC= $(wildcard $(SOURCE_FOLDER)/*.c)

#Création de la liste des dépendances (.o)
OBJ= $(SRC:.c=.o)

#Cible ou sont stocker les .o
BUILD_TARGET=../../build

########################################
#COMMANDES D'EXECUTION
########################################

#Création des fichiers .o
all: 		 								$(EXEC)

#Pour créer les .o du dossier de destination on a besoin des fichiers .c du sous dossier
$(EXEC):	 								$(BUILD_TARGET)/$(OBJ)

#Procédure simple de compilation .c -> .o prise en charge des dossiers d'arrivée/départ
$(BUILD_TARGET)/$(SOURCE_FOLDER)/%.o: 		$(SOURCE_FOLDER)/%.c
	 	 	 								$(CC) -o $@ -c $< $(CFLAGS)