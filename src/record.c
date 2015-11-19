/*Auteur Favry Erwan et Jaffali Hamza
 *Sujet : HashMap LP25
 *Utilité : gestion des record
 *date : P2014
 */


#include "common.h"


Record RecordNew(){
  Record rec;
  
  rec.unic_id=NULL;
  rec.size_unic_id=-1;
  rec.id=NULL;
  rec.size_id=-1;
  rec.hour=-1;
  rec.minute=-1;
  rec.second=-1;
  rec.id_cell=-1;
  rec.techno_used=NULL;
  rec.size_techno=-1;
  rec.longit=-1;
  rec.lati=-1;
  return rec;
  /*copy ?*/
}

Record RecordCopy(Record tcpy){
  Record rec;
  rec= RecordNew();
  
  rec.size_unic_id=tcpy.size_unic_id;
  rec.unic_id=calloc(tcpy.size_unic_id, sizeof(char));
  memcpy(rec.unic_id, tcpy.unic_id, tcpy.size_unic_id);
  
  
  rec.size_id=tcpy.size_id;
  rec.id=calloc(tcpy.size_id, sizeof(char));
  memcpy(rec.id,tcpy.id,tcpy.size_id);
  
  
  
  rec.hour=tcpy.hour;
  rec.minute=tcpy.minute;
  rec.second=tcpy.second;
  rec.id_cell=tcpy.id_cell;
  
  rec.size_techno=tcpy.size_techno;
  rec.techno_used=calloc(tcpy.size_techno, sizeof(char));
  memcpy(rec.techno_used, tcpy.techno_used, tcpy.size_techno);
  
  
  
  rec.longit=tcpy.longit;
  rec.lati=tcpy.lati;
  
  return rec;
}

void RecordFree(Record rec){

    free(rec.unic_id);
    rec.unic_id=NULL;
    free(rec.id);
    rec.id=NULL;
/*  
  rec->size_id=-1;
  rec->hour=-1;
  rec->minute=-1;
  rec->second=-1;
  rec->id_cell=-1;
*/
    free(rec.techno_used);
    rec.techno_used=NULL;
  /*  
  rec->size_techno=-1;
  rec->longit=-1;
  rec->lati=-1;
  */
  /*free(rec);
  rec=NULL;*/
}


Record RecordSetUnicId(Record rec){
  char ac_buffer[6];
  /*ATENTION CA NE MARCHERA PAS CAR CEST LA CLEF QUIL FAUT RECUP*/
  /*FAUX !*/
  
  rec.size_unic_id = 40;
  
  rec.unic_id = calloc(rec.size_unic_id ,sizeof(char)); /*sizeof char n'est pas important mais sera gardé pour la consistence*/
  /*recopier l'id puis y ajouter l'heure*/
  memcpy(rec.unic_id, rec.id, rec.size_id);
  sprintf(ac_buffer,"%d",rec.hour);
  strcat(rec.unic_id, ac_buffer);
  sprintf(ac_buffer,"%d",rec.minute);
  strcat(rec.unic_id, ac_buffer);
  sprintf(ac_buffer,"%d",rec.second);
  strcat(rec.unic_id, ac_buffer);
  return rec;
}

Record RecordSetId(Record rec, char *id, int size){
  /*
   * allouer la mémoire selon la taille, 
   * mettre dans la var de stockage de la taille la  taille
   * recopier le contenu vers la cible
   */
  rec.id = calloc( size ,sizeof(char)); /*sizeof char n'est pas important mais sera gardé pour la consistence*/
  rec.size_id = size;
  memcpy(rec.id,id,size);
  /*strcpy(rec.id,id);*/
  return rec;
}
Record RecordSetTime(Record rec, char *time){
 char h[3];/*store hour*/
 char m[3];/*store seconde*/
 char s[3];/*store second*/
 h[0]=time[0];
 h[1]=time[1];
 h[2]='\0';
 m[0]=time[3];
 m[1]=time[4];
 m[2]='\0';
 s[0]=time[6];
 s[1]=time[7];
 s[2]='\0';
 /*HIDEUX !*/
 rec=RecordSetHour(rec,h);
 rec=RecordSetMinute(rec,m);
 rec=RecordSetSecond(rec,s);
 return rec;
}
Record RecordSetHour(Record rec, char *h){
  rec.hour=atoi(h);
  return rec;
}
Record RecordSetMinute(Record rec, char *m){
  rec.minute=atoi(m);
  return rec;
}
Record RecordSetSecond(Record rec, char *s){
  rec.second=atoi(s);
  return rec;
}
Record RecordSetIdCell(Record rec, char *id_cell){
  rec.id_cell=atoi(id_cell);
  return rec;
}

Record RecordSetTechnoUsed(Record rec, char *techno_used, int size){
  rec.techno_used = calloc(size ,sizeof(char)); /*sizeof char n'est pas important mais sera gardé pour la consistence*/
  rec.size_techno=size;
  memcpy(rec.techno_used,techno_used,size);
  return rec;
}

Record RecordSetLongitude(Record rec, char *longit){
  rec.longit=atof(longit);
  return rec;
}

Record RecordSetLatitude(Record rec, char *lati){
  rec.lati=atof(lati);
  return rec;
}


/*MAJUSCULE*/
/*TOFINISH and to add a .h !!*/
/*affaichage sur une seul ligne !!!*/
void RecordShow(Record rec){
  printf("ID : %s, Hour : %d:%d:%d, ID_Cell : %d Technologie Utilise : %s, Longitide : %f Latitude : %f", rec.id, rec.hour, rec.minute, rec.second, rec.id_cell, rec.techno_used, rec.longit, rec.lati);
}

/*record compare !*/
int RecordCompare(Record rec1, Record rec2){
  if(rec1.unic_id == NULL)RecordSetUnicId(rec1);
  if(rec2.unic_id == NULL)RecordSetUnicId(rec2);
		  
  if(memcmp(rec1.unic_id, rec2.unic_id, 39)) 
    /*peut poser probleme si la mémoire n'est pas mis a 0 partout et que le contenu ne remplace pas totalement le contenant*/
  {
    return 1;
  }
  else
  {
    return 0;
  }
 
}

int RecordPureEquals(Record rec1, Record rec2){
  if(rec1.hour == rec2.hour
    && rec1.minute == rec2.minute
      && rec1.second == rec2.second
	&& rec1.id_cell == rec2.id_cell
	  && rec1.longit == rec2.longit
	    && rec1.lati == rec2.lati
	      && memcmp(rec1.id, rec2.id, rec1.size_id)
		&& memcmp(rec1.techno_used, rec2.techno_used, rec1.size_techno))
	  /*si on atteint ce niveau on est sur que les deux rec sont identique*/
    return 1;
  else
  {
    return 0;
  }
}
