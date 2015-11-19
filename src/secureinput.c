/*Auteur Favry Erwan et Jaffali Hamza
 *Sujet : HashMap LP25
 *Utilité : gestion des entré sécurisé (recopie d'un lib de erwan)
 *date : P2014
 */



#include "common.h"

/*Provide a more secure input for the char.*/
char secureinputchar(void)
{

  char in[30];
  char clean;
  printf("\nVeuillez entrer un charactere (double entree pour valider)  : \n");
  fgets(in, sizeof(in), stdin); /*get the answer of the user*/
  while ((clean = fgetc(stdin)) != '\n' && clean != EOF); /*the purpose of the line is to clean the standard input stream, fgetc "eat" the char in the stdin if they were not read by the fgets side effect : double entrée*/
  return in[0];

}

/*Provide a more secure input for the float.*/
float secureinputfloat(void)
{
	char in[30];
	char clean;
	int test,i;
	do {
		/*printf("\nPlease enter a float : \n");*/
		printf("\nVeuillez entrer un reel  : \n");
		test=0;
		i=0;
	    fgets(in, sizeof(in), stdin); /*get the answer of the user*/
	    while ((clean = fgetc(stdin)) != '\n' && clean != EOF); /*the purpose of the line is to clean the standard input stream, fgetc "eat" the char in the stdin if they were not read by the fgets*/
		while(in[i]!='\n' && in[i]!='\0')
		{
					if((in[i] < '0' && in[i]!='\0' && in[i]!='+' && in[i]!='-' && in[i]!='\n' && in[i]!=' ' && in[i]!='.' && in[i]!=',') || in[i] > '9') /*if an "illegal" char is find we re-ask the user to retype the answer*/
					{
						test++;
					}
					i++;
		}
	}while(test>0);
	/*here we convert the , to .*/
	i=0;
	while(in[i]!='\n' && in[i]!='\0')
			{
				if(in[i]==',')
				{
					in[i]='.';
				}
				i++;
			}
	return atof(in); /*we convert the string into number*/
}


/*Provide a more secure input for the int.*/
int secureinputint(void)
{
	char in[9]; /*we consider that a int is between -32 768 and +32 767 */
	char clean;
	int test,i;
	do 
	{
		/*printf("\nPlease enter a integer : \n");*/
		printf("\nVeuillez entrer un entier  : \n");
		test=0;
		i=0;
	    fgets(in, sizeof(in), stdin); /*get the answer of the user*/
	    while ((clean = fgetc(stdin)) != '\n' && clean != EOF); /*the purpose of the line is to clean the standard input stream, fgetc "eat" the char in the stdin if they were not read by the fgets*/
		while(in[i]!='\n' && in[i]!='\0')
		{
					if((in[i] < '0' && in[i]!='\0' && in[i]!='+' && in[i]!='-' && in[i]!='\n' && in[i]!=' ') || in[i] > '9') /*if an "illegal" char is find we re-ask the user to retype the answer*/
					{
						test++;
					}
					i++;
		}
	}while(test>0);
	return atoi(in); /*we convert the string into number*/
} 
