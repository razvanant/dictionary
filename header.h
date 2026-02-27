#ifndef header_h_
#define header_h_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 struct dictionar
{
    char eng[50];
    char ro[50];
   struct dictionar *stg;
   struct dictionar *drept;

};
struct dictionar  *fabrica( char *e,char *r);
struct dictionar *inserare(struct dictionar *p,char *e,char *r);
struct dictionar *cautare(struct dictionar *p, char *e);
void afisare(struct dictionar *p);
void eliberareMemorie(struct dictionar *p);
void salvareFisier(struct dictionar*p,FILE *f);
#endif