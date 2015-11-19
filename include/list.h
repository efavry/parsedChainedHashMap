#ifndef __LIST__
#define __LIST__

/* List Element Type */
/*typedef struct {
	int code;  Code of the product
	float price;  Price of the product 
	float quantity;
} Record;*/

/* List Node Type */
typedef struct cell {
	/*struct cell* prev;*/
	Record value;
	struct cell* next;
} Cell;

typedef Cell* List;
typedef List Bucket;

/*
typedef struct List{
  Cell* head;
  Cell* tail;
  int size;
} ListI;
*/

void List_free(List l);

int List_is_empty(List l); /*testé*/

Record List_get_head_record(List l); /*testé*/
Record List_get_tail_record(List l); /*testé*/

Cell* List_head (List l); /*testé*/
Cell* List_last (List l); /*testé*/

List List_insert_head(List l, Record p);/*testé*/
List List_insert_tail(List l, Record p);/*testé*/

int List_nb_record(List l); /*testé*/

void List_display(List l); /*testé*/

/*List List_remove_tail(List l);*/ /*testé*/
List List_remove_head(List l); /*boucle infinie ?*/

Record* List_Pop(List l, char* unic_id); /*a faire*/

/*rajout fct remove by unique id !*/
int List_contains_unic_id(List l, char *unic_id);
List List_remove_unic_id(List l, char *unic_id);

int List_contains(List l, Record rec);
#endif 
