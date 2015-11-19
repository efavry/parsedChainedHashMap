/*Auteur Favry Erwan et Jaffali Hamza
 *Sujet : HashMap LP25
 *Utilité : gestion des fichiers
 *date : P2014
 */

#include "common.h"

/*open the file and read his line and send it to parse line*/
HashMap parseCSV(char *filepath, HashMap map) {
  
    char *buffer;
    HashMap vide;
    Record rec;
    FILE *file=fopen(filepath, "r");
    
    /*Test if opening was a sucess*/
    if(file==NULL)
    {
      	fprintf(stderr,"Problem during opening of %s \nNo parsing will be made sorry \n exiting \n ", filepath);
	
	
	free(filepath);
	filepath=NULL;
	freeHashMap(&map);
      	exit(0);
      	return vide;
    }
    /*we allocate only if we suceeded the opening*/
    buffer=(char*) calloc(200 , sizeof(char));
  
    /*gets function is deprecated, and is also not adapted for us*/
    /*using fgets instead*/
    /*on considere qu'on a 1024 colonnes  max*/
    /*ca deevrait suffire tant que ya pas trop de fichier sous fichier*/
    
    while(fgets(buffer, 1024, file) != NULL)
    {
      
	rec = RecordNew();
	
	rec = parseLine(buffer,rec);
	
	rec = RecordSetUnicId(rec);
	puts("________________________________________________________________");
	puts("rec unic id est : ");
	puts(rec.unic_id);
	puts("________________________________________________________________");
	
	map = addNewRecord (map,/*balancer copy record avant free*/RecordCopy(rec), hashFunction(map,rec) ) ;
	
	RecordFree(rec);
	
    }
    /*ensure the closing*/
    if (fclose(file)==EOF)
    { /*au seconde run depuis le main fclose donne une segfault */
	fprintf(stderr, "Problem during the closing of %s", filepath);
        return vide;
    }
    file=NULL;
    /*free memory*/
    free(buffer);
    buffer=NULL;
    return map;
}



/*parse the line readesby parseCSV*/
Record parseLine(char *todec, Record rec){
  /*on char more than the actual size to be sure to store \0*/
  char *dec;
  int size_of_dec=34;
  int i=-1; /*to traverse the array*/
  int j=-1; /*to traverse the specific arrayputs(dec);*/
  
  short unsigned int indic=0; /* 0 is the id 1 is the hour 2 is cellid 3 is  the technolgie 4 is the longitude 5 is lattitude*/
  puts(todec);
  dec=(char*) calloc(size_of_dec, sizeof(char));
  /*pas besoin de setter tout a \0 car calloc vien de déjà tout mettre à 0*/
  
  do
  {
    ++j;
    ++i;
    dec[j]=todec[i]; 
    /*if we have reached a , or the end of line or end of string we treat*/
    /*the test are in order of probability of apparition*/
    if(todec[i]== ',' || todec[i] == '\n' || todec[i] == '\0'){
      dec[j]='\0';
      rec = chooseCorrectData(dec, size_of_dec, indic, rec);
      /*++size_of_dec;*/
      /*cleaning dec*/
      for(j=0;j<size_of_dec;++j)
      {
	dec[j]='\0';
      }
      j=-1; /*j repassera donc a 0 quand il passera au ++j donc la prochaine iteration sera avec j=0*/
      ++indic;
    }

  }
  while (todec[(i)] != '\0');
  free(dec);
  dec=NULL;
  return rec;
}

/*this one serve as a choice to choose were the content must be recorderd*/
/*return if the choice suceeded 0 or not -1*/
Record chooseCorrectData(char *dec, int size_of_dec, int indic, Record rec){
  /* 0 is the id 1 is the hour 2 is cellid 3 is  the technolgie 4 is the longitude 5 is lattitude*/
  switch(indic)
  {
    case 0:
	/*puts("id");
	puts(dec);*/
	rec = RecordSetId(rec, dec, size_of_dec);
      break;
    case 1:
	/*puts("hour");
	puts(dec);*/ /*////add the thing to add !*/
	rec = RecordSetTime(rec, dec);
      break;
    case 2 :
	/*puts("cellid");
	puts(dec);*//*////add the thing to add !*/
	rec = RecordSetIdCell(rec, dec);
      break;
    case 3 :
	/*puts("techno");
	puts(dec);*//*////add the thing to add !*/
	rec = RecordSetTechnoUsed(rec,dec,size_of_dec);
      break;
    case 4 :
	/*puts("longitude");
	puts(dec);*//*////add the thing to add !*/
	rec = RecordSetLongitude(rec,dec);
      break;
    case 5 :
	/*puts("lattitude");
	puts(dec);*//*////add the thing to add !*/
	rec = RecordSetLatitude(rec,dec);
      break;
    default:
	 /*puts("end of dec qui vaut :");
	 puts(dec);
	 puts("End of error");*/
      break;
  }
  
  /*++size_of_dec;*/
  return rec;
}