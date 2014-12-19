########################################
#DECLARATION DES OPTIONS DE COMPILATION
########################################

#Le sous dossier contenant les .o
SOURCE_FOLDER=source

#Le dossier de destination de la dépendance
TARGET_FOLDER=../bin

#Listing de tous les .o du dossier source
OBJ= $(wildcard $(SOURCE_FOLDER)/*.o)

########################################
#COMMANDES D'EXECUTION
########################################

#Création de l'exécutable dans le dossier cible
all: 		 				$(TARGET_FOLDER)/$(EXEC)

#Listage de tous les fichiers objets du sous dossier source
$(TARGET_FOLDER)/$(EXEC):	$(OBJ)
			 				@$(CC) -o $@ $^ $(LDFLAGS) $(LIBINCLUDEPATH)

#efface TOUT les .o du sous dossier source
ifeq ($(OS),Windows_NT)
mrproper:								
							-del /F "$(SOURCE_FOLDER)\*.o"
							-del /F "$(EXEC)"
else
mrproper:
							-rm -rf $(SOURCE_FOLDER)/*.o
							-rm -rf $(EXEC)
endif
							