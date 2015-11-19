/*Auteur Favry Erwan et Jaffali Hamza
 *Sujet : HashMap LP25
 *Utilité : gestion des fichiers
 *date : P2014
 */

#include "common.h"


void runSimulation() {
  int vi_ishashmapexist=0,vi_firsttime=1;
  char vi_choix='\0';
  char *in;
  char clean='\0';

    HashMap map;

    in =calloc(1024,sizeof(char));
    puts("<======================================================>");
    puts("Bienvenue dans le programme de simulation de");
    puts("Jaffali Hamza et Favry Erwan");
    puts("<======================================================>");

    while(vi_choix!='q')
    {
	puts("===================Menu Principal=====================");
	puts("Que voulez-vous faire ?");
	if(vi_ishashmapexist)
	{
	  puts("Choix 'a' : Afficher l'entierete de la hashmap");
	  puts("Choix 'b' : Afficher les satistiques de la hashmap");
	  puts("Choix 'c' : Lire un csv supplementaire");
	  puts("Choix 'q' : Quitter");
	  puts("======================================================");
	  if(vi_firsttime)
	  {
	    while ((clean = fgetc(stdin)) != '\n' && clean != EOF);
	    vi_firsttime=0;
	    /*pour bouffer les char qui depasse en mémoire la premiere fois et qui font relancer le menu a chaque fois*/
	  }
	  vi_choix = secureinputchar();
	  /*scanf("%c", &vi_choix); */
	  switch(vi_choix)
	  {
	    case 'a':
	      puts("");
	      puts("===============Affichage de la Hashmap================");
	      displayHashMap(map);
	      puts("======================================================");
	      break;

	    case 'b':
	      puts("");
	      puts("==============Affichage des statistiques==============");
	      displayHashMapInformations (map);
	      puts("======================================================");
	      break;

	    case 'c':
	      puts("=============Ajout de record supplementaire===========");

	      puts("Veuillez entrer le nom du fichier puis appuyer sur entree");
	      free(in);in=NULL;
	      in = calloc(1024,sizeof(char));
	      scanf("%s",in);
	      map = parseCSV(in,map);
	      puts("======================================================");
	    /*get input from user then send it to the gestionnaire de csv*/
	      /*
	      puts("Lancement de la recherche");*/
	      /*demander le record à luser*/
	      /*appeler is in hashmap*/
	      /*afficher si c'est pas present'*/
	      /*sinon retrouvé son hash*/
	      /*aller a l'indice donné parcouré la lsite pointé et affiché la ou c'est car moi parle france*/
	      puts("======================================================");
	      break;

	    case 'q':
	      puts("Le programme va maintenant quitter");
	      freeHashMap(&map);
	      puts(">======================================================<");
	      break;

	    case '\0':
	      break;

	    default:
	      break;
	  }
	}
	else /*si la hashmap existe pas il faut proposer à l'utilisateur de la creer ou de quitter le programme*/
	{
	  puts("Choix 'a' : Creer la hasmap en chargeant un fichier");
	  puts("Choix 'q' : Quitter");
	  puts("======================================================");
	  /*scanf("%c", &vi_choix);*/ /*AREMPLACER PAR UN SECURE INPUT*/
	  vi_choix = secureinputchar();
	  if (vi_choix == 'a')
	  {


	    puts("Veuillez entrer le nom du fichier puis appuyer sur entree");
	 
	    /*get input from user then send it to the gestionnaire de csv*/
	    scanf("%s",in);
	    map = newHashMap();
	    map = parseCSV(in,map);
	    vi_ishashmapexist=1;
	    puts("Hashmap cree");
	  }
	  else if (vi_choix == 'q')
	  {
	    puts("Le programme va maintenant quitter");
	    puts(">======================================================<");
	  }

	}
    }
    free(in);
    in=NULL;
    return;
}



int main(){
  /*exemple d'utilisation de sprintf :
  char *l;
  l=malloc(160);
  sprintf(l,"%d",60);
  puts(l);*/
  /*Dat main ultra util*/
  runSimulation();
  return 1;
}
