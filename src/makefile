##############################
#OPTIONS DE COMPILATION
##############################

#Compilateur
export CC=gcc

#Options de compilation des .c
export CFLAGS=-Wall

#Nom de l'executable final
export EXEC=halma

#Noms des sous dossiers
export MODEL_DIR=modele
export VIEW_DIR=vue
export CONTROLLER_DIR=controleur
export MAIN_DIR=jeu

#Résolutions des inclusions
#Dossiers où se trouvent les .h des librairies externes /rapport à la position des sous makefiles
export LIBINCLUDEPATH=-I ../../include/libMatrice

#Dossiers où se trouvent les .h des sources /rapport à la position des sous makefiles
export INCLUDEPATH=-I header -I ../modele/header -I ../vue/header -I ../controleur/header 
###########################

#Nom du dossier de build (stockage des .o)
BUILD_DIR=../build

#Nom du dossier de stockage de l'exécutable
RUN_DIR=../bin

#Les options pour l'éditions des liens (IMPORTANT LIBRAIRIE DYNAMIQUE)
export LDFLAGS=-I ../include/libMatrice -Wl,-R ../lib -L ../lib -lMatrice 

##############################
#COMMANDES DE COMPILATION
##############################

#Construction de l'exécutable
all: 		$(EXEC)

#Appels des sous makefiles pour build les .o puis editer les liens
$(EXEC):	
			@(cd $(MODEL_DIR) && $(MAKE))
			@(cd $(VIEW_DIR) && $(MAKE))
			@(cd $(CONTROLLER_DIR) && $(MAKE))
			@(cd $(MAIN_DIR) && $(MAKE))
	 		@(cd $(BUILD_DIR) && $(MAKE))

#commande de nettoyage du projet (suppr les .o)
mrproper:	
			@(cd $(BUILD_DIR) && $(MAKE) $@)

#pour lancer l'exécutable final
run:
			@cd $(RUN_DIR); ./$(EXEC)