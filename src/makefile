##############################
#OPTIONS DE COMPILATION
##############################

#Compilateur
export CC=gcc

#Options de compil°
export CFLAGS=-Wall

#Nom de l'executable final
export EXEC=halma

#Noms des sous dossiers
export MODEL_DIR=modele
export VIEW_DIR=vue
export CONTROLLER_DIR=controleur
export MAIN_DIR=jeu

#la liste des noms des fichiers
MODEL= $(wildcard ../moteur/*.o)
VIEW= $(wildcard ../vue/*.o)
CONTROLLER= $(wildcard ../vue/*.o)
GAME= $(wildcard ../jeu/*.o)

#Les options pour l'éditions des liens
LDFLAGS=-I ../include/libMatrice -Wl,-R ../lib -L ../lib -lMatrice 

##############################
#COMMANDES DE COMPILATION
##############################

#Construction de l'exécutable
all: 		$(EXEC)

#Appels des sous makefiles
$(EXEC):	
			@(cd $(MODEL_DIR) && $(MAKE))
			@(cd $(VIEW_DIR) && $(MAKE))
			@(cd $(CONTROLLER_DIR) && $(MAKE))
			@(cd $(MAIN_DIR) && $(MAKE))
	 		$(CC) -o $@ $(MODEL_DIR)/*.o $(VIEW_DIR)/*.o $(CONTROLLER_DIR)/*.o $(MAIN_DIR)/*.o $(LDFLAGS)

#commande de nettoyage
mrproper:	
			@(cd $(MODEL_DIR) && $(MAKE) $@)
			@(cd $(VIEW_DIR) && $(MAKE) $@)
			@(cd $(CONTROLLER_DIR) && $(MAKE) $@)
			@(cd $(MAIN_DIR) && $(MAKE) $@)
			rm -rf $(EXEC)