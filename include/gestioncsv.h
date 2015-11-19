/*Auteur Favry Erwan*/
/*Objet : .h de la gestion de csv*/
/*Nom du fichier : gestioncsv.h*/
/*en rapport direct avec : gestioncsv.c*/
#ifndef __GESTION_CSV__
#define __GESTION_CSV__



/*open the file and read his line and send it to parse line*/
HashMap parseCSV(char *fileName, HashMap map);

/*parse the line readesby parseCSV*/
Record parseLine(char *todec, Record rec);

/*this one serve as a choice to choose were the content must be recorderd*/
Record chooseCorrectData(char *dec, int size_of_dec, int indic, Record rec);
#endif
