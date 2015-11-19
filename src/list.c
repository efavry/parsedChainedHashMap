/*Auteur Favry Erwan et Jaffali Hamza
 *Sujet : HashMap LP25
 *Utilité : gestion des listes
 *date : P2014
 */

#include "common.h"

void List_free(List l)
{
  while (l!=NULL) 
  {
    l=List_remove_head(l);
  }
}


/*
 * Test if a list is empty
 * l - a list of product
 * return true if the list is empty, false otherwise
 */
/*Public*/
int List_is_empty (List l) 
{
	if (l == NULL) 
	{
		return 1;
	} 
	else 
	{
		return 0;
	}
}
/*public*/
/*FAIL IF THE LIST IS EMPTY*/
Record List_get_head_record(List l) 
{
    return l->value;
}
/*Public*/
/*FAIL IF THE LIST IS EMPTY*/
Record List_get_tail_record(List l)
{
  List lreturn;
  lreturn=List_last(l);
  return lreturn->value;
}

/*private*/
/*get first cell of list*/
Cell* List_head (List l) 
{
  
  if (List_is_empty(l))
  {
    return NULL;
  }
  else
  {
	Cell* p;
	p=l;/*wtf? useless!*/
	return p;
  }
	
}

/*private get last cell of list*/
Cell* List_last (List l) 
{
	List p = l;

	if (p != NULL) 
	{
		while (p->next !=NULL) 
		{
			p=p->next;
		}
	}
	return p;
}

List List_insert_head (List l, Record p) 
{
	List newel;
	newel = (Cell *) malloc(sizeof(Cell));
	newel->value = p;
	newel->next = l;
	return newel;
}

List List_insert_tail(List l, Record p) 
{
	List newel; List d;
	newel = (Cell *) malloc(sizeof(Cell));
	newel->value = p;
	newel->next = NULL;
	if (l == NULL) 
	{
		l=newel;
	} 
	else 
	{
		d = l;
		while (d->next !=NULL) 
		{
			/*if(pl->next != NULL)
			{*/
			  d=d->next;
			  /*assert(d->next!=NULL);*/
			/*}*/
		}
		d->next=newel;
	}
	return l;
}

int List_nb_record(List l) 
{
  int nb;
	if( List_is_empty(l)) {
		return 0;
	} else {
		List p = l;
		nb = 0;
		while (p->next != NULL) {
			nb=nb+1;
			p = p->next;
		}
		return nb+1;
	}
}

Record* List_Pop(List l, char* unic_id)
{
    Record *rec;
    Cell *temp, *temp2;
    int vb_isInList;
    
    rec = NULL;
    vb_isInList = List_contains_unic_id( l, unic_id);
    temp = NULL;
    if (!List_is_empty(l))
    {
        if(vb_isInList>1)
        {
            temp = l;
            while (!strcmp((temp->value).unic_id,unic_id))
            {
                temp2 = temp;
                temp = (*temp).next;
            }
            temp2->next = temp->next;
	    rec = &(temp->value);
        }
        
    }
    
    return rec;
}


void List_display(List l)
{
     List temp;
     temp=l;
     if(temp==NULL)
      {
         printf("List is Empty");
      }
     while(temp!=NULL)
     {	
	  /*Dummy !*/
    	 /*Afficher record a la place*/
    	 RecordShow(temp->value);
	 puts(""); /*saut de ligne*/
         /*printf("-> ");*/
         temp=temp->next;
     }
     
} 

/*
List List_remove_tail(List l)
{
    List p;
    if(l!=NULL)
    {
      if(l->next == NULL)
      {
	RecordFree((l->value));
	free(l);
	l=NULL;
      }
      else
      {
	p=l;
	while(p->next->next != NULL)
	{
	  p=p->next;
	}
	RecordFree((p->next->value));
	free(p->next);
	p->next = NULL;
      }
    }
    return l;
} 
*/
List List_remove_head(List l)
{
  List p;
  p=NULL;
  if(l==NULL)
  {
    puts("Bucket to free is null");
    p=NULL;
  }
  else
  {
    p = l-> next;
    RecordFree((l->value));
    free(l);
    l=NULL;
    l=p;
  }
  return p;
}

int List_contains(List l, Record rec)
{
  int truth=0;
  List p = l;
  while(!List_is_empty(p) && truth ==0)
  {
    if(RecordCompare(rec,l->value))
    {
      truth=1;
    }
    else
    {
      p=p->next;
    }
  }

  return truth;
}

/*HAMZA PROPOSITION*/
int List_contains_unic_id(List l, char *unic_id)
{
    Cell *temp;
    temp = l;
    while (temp!=NULL)
    {
        if (strcmp((temp->value).unic_id, unic_id)==0)
            return 1;
    }
    return 0;
}

/*HAMZA PROPOSITION*/
List List_remove_unic_id(List l, char *unic_id)
{
    Record *rec;
    rec = List_Pop( l, unic_id);
    RecordFree(*rec);
    return l;
}