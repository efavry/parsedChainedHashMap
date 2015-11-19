#ifndef hj_HASHMAP_h
#define hj_HASHMAP_h

/* Structures definition */

typedef struct HashMap {
	Bucket *tableauIndex;
	int sizeOfIndex;
	int nbRecord;

} HashMap;

/* Prototypes definition */

/*create a new hashmap with 7 initial buckets*/
HashMap newHashMap ();

void freeHashMap (HashMap *hash);

/*add a new record in the hashmap*/
HashMap addNewRecord (HashMap hash, Record rec, int index);

/*delete a specific record from the hashmap*/
HashMap deleteRecord (HashMap hash, char* unic_id);

/*delete a specific record from the hashmap and return it*/
Record* popRecord (HashMap hash, char* unic_id);

/*hash function that return the index of this record*/
int hashFunction (HashMap hash, Record rec);

/*check if the record is already in the hasmap : return -1 if it's false, the index of the record otherwise*/
int isInHashMap (HashMap hash, char* unic_id);

/*display all the elements of the hashmap*/
void displayHashMap (HashMap hash);

/*display all the information related to the hashmap*/
void displayHashMapInformations (HashMap hash);

#endif