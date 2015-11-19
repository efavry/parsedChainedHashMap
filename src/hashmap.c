/*Auteur Favry Erwan et Jaffali Hamza
 *Sujet : HashMap LP25
 *Utilité : gestion des hasmap
 *date : P2014
 */

#include "common.h"

/*instancie uen nouvelle hashmap*/
HashMap newHashMap ()
{
	int i;
	HashMap hMap;
	/*hMap = (HashMap *) malloc(sizeof(HashMap));*/
	(&hMap)->tableauIndex = calloc (7, sizeof(List));
	(&hMap)->sizeOfIndex = 7;	
	for (i=0; i<((&hMap)->sizeOfIndex); i++)
	{
	      (&hMap)->tableauIndex[i]=NULL;
	}
	(&hMap)->nbRecord =0; /*bouhahahaha &hmap !*/
	printf("\nNew empty hashmap generated\n");	
	return /***/hMap;
}

/*free the hashmap*/
void freeHashMap (HashMap *hash)
{
  int i;
  
  for (i=0; i<(hash->sizeOfIndex); i++)
  {
	      List_free(hash->tableauIndex[i]);
	      hash->tableauIndex[i]=NULL;
  }
  free(hash->tableauIndex);
  hash->tableauIndex=NULL;
  printf("\nHashmap destructed\n");	
}

/*ajouter un record a la hashmap en param*/
/*prend une hashmap en param un rec et un index*/
/*positionne le record dans the right list*/
HashMap addNewRecord (HashMap hash, Record rec, int index)
{	
	*(hash.tableauIndex + index) = List_insert_tail( *(hash.tableauIndex + index), rec);
	printf("\nRecord added successfully to the Hashmap\n");
	hash.nbRecord++;
	return hash;
}

/*suppression d'un record avec l'unic id spécifié*/
HashMap deleteRecord (HashMap hash, char* unic_id)
{
	int recordFinded;
	recordFinded = isInHashMap (hash, unic_id);
	if (recordFinded >= 0)
	{
		printf("\nRecord finded in the Hashmap\n");
		*(hash.tableauIndex + recordFinded) = List_remove_unic_id(*(hash.tableauIndex + recordFinded), unic_id);
		printf("Record removed from Hahmap\n");
		hash.nbRecord--;
		
	}
	else
	{
		printf("\nNo record with this id in the Hashmap\n");
		
	}
	return hash;
}

/*le titre dis tout*/
Record* popRecord (HashMap hash, char* unic_id)
{
    	Record *rec;
	int indexRecord;
	indexRecord = isInHashMap (hash, unic_id);
	rec = List_Pop (*(hash.tableauIndex + indexRecord), unic_id);
	return rec;
}

/*la focntion de hash (voir rapport pour une explication clair*/
int hashFunction (HashMap hashMap, Record rec) 
{
	char *ident;
	int size_ident, record_Hour, size_index, record_Minute, record_Second, sum_ascii=0, ascii_code, i, index;
	ident = rec.id;
	size_index = hashMap.sizeOfIndex; 
	size_ident = rec.size_id; 
	record_Hour = rec.hour; 
	record_Minute = rec.minute; 
	record_Second = rec.second;
	/*we do the sum of ascii code of every char of the id string*/
	for (i=0; i<size_ident; i++)
	{
		ascii_code = (int) *(ident + i);
		sum_ascii = sum_ascii + ascii_code;
	}
	index = sum_ascii - record_Hour*record_Minute - record_Second;
	if (index<0)
	{
		index = (-1)*index;
	}
	index = index/20;
	index = index %	size_index;
	printf("Index generated : %d\n", index);
	return index;
}

/*find if a record belong to the hashmap*/
int isInHashMap (HashMap hash, char* unic_id) 
{
	int recordFinded=-1, i;
	for (i=0; i<hash.sizeOfIndex; i++)
	{
		recordFinded = List_contains_unic_id(*(hash.tableauIndex +i), unic_id);	
		if (recordFinded == 1)
		{
			recordFinded = i;
			return recordFinded;	
		}
	}
	return recordFinded;
}

/*titre clair*/
void displayHashMap (HashMap hash)
{
	int i;
	printf("\n**Starting Hashmap's elements display**\n");
	for (i=0; i<hash.sizeOfIndex; i++)
	{
		printf("\n--- Bucket %d ---\n",i+1);
		List_display(*(hash.tableauIndex +i));		
	}
	printf("\n****************Finished****************\n\n");
}

/*display stat of the hashMap*/
void displayHashMapInformations (HashMap hash)
{
	int nb_Empty_Buckets=0, i;
	float buckets_Size_Average=0;

	for (i=0; i<hash.sizeOfIndex; i++)
	{
		nb_Empty_Buckets = nb_Empty_Buckets + List_is_empty(*(hash.tableauIndex +i));
		buckets_Size_Average = buckets_Size_Average + List_nb_record(*(hash.tableauIndex +i));
	}
	buckets_Size_Average = buckets_Size_Average / hash.sizeOfIndex;

	printf("\n**Starting Hashmap's informations display**\n");
	printf("\tFilling ratio : %.2f\n", (hash.nbRecord+0.0)/hash.sizeOfIndex);
	printf("\tEmpty buckets : %d ", nb_Empty_Buckets);
	printf("\tEmpty buckets ratio : %.2f\n", (nb_Empty_Buckets+0.0)/hash.sizeOfIndex); 
	printf("\tAverage buckets size : %.2f\n", buckets_Size_Average);
	printf("\n*****************Finished******************\n\n");
}
