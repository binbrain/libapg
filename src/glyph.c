#include "glyph.h"

/*
** is_restricted_symbol - detcts if symbol is restricted rigt now
** INPUT:
**   char - symbol.
** OUTPUT:
**   int - 0 - not restricted
**         1 - restricted
** NOTES:
**   none.
*/
int
is_restricted_symbol (char symbol)
{
  int j = 0;
  for (j = 0; j <= 93 ; j++)
    if (symbol == smbl[j].ch)
      if ((S_RS & smbl[j].type) > 0)
        return(1);
  return(0);
}

/*
** gen_rand_symbol - generates random password of specified type
** INPUT:
**   char * - symbol.
**   unsigned int - symbol type.
** OUTPUT:
**   int - password length or -1 on error.
** NOTES:
**   none.
*/
int
gen_rand_symbol (char *symbol, unsigned int mode)
{
  int j = 0;
  char *str_pointer;
  int random_weight[94];
  int max_weight = 0;
  int max_weight_element_number = 0;

  for (j = 0; j <= 93; j++) random_weight[j] = 0; 
  str_pointer = symbol;
  j = 0;
/* Asign random weight in weight array if mode is present*/
  for (j = 0; j <= 93 ; j++)
     if ( ( (mode & smbl[j].type) > 0) &&
         !( (S_RS & smbl[j].type) > 0))
       random_weight[j] = 1 + randint(20000);
  j = 0;
/* Find an element with maximum weight */
  for (j = 0; j <= 93; j++)
     if (random_weight[j] > max_weight)
       {
        max_weight = random_weight[j];
        max_weight_element_number = j;
       }
/* Get password symbol */
  *str_pointer = smbl[max_weight_element_number].ch;
  max_weight = 0;
  max_weight_element_number = 0;
  return (0);
}
