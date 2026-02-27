
#include "header.h"
struct dictionar*fabrica( char *e,char *r)
{
    struct dictionar*p;
    p=malloc(sizeof(struct dictionar));
    if(p==NULL)
    {
        printf("nu este spatiu");
        exit(1);
    }
    strcpy(p->eng,e);
    strcpy(p->ro,r);
    p->drept=NULL;
    p->stg=NULL;
    return p;
}
struct dictionar *inserare(struct dictionar *p,char *e,char *r)
{
if(p==NULL)
return fabrica(e,r);
else
{
    if(strcmp(e,p->eng)<0)
    p->stg=inserare(p->stg,e,r);
    else if(strcmp(e,p->eng)>0) p->drept=inserare(p->drept,e,r);
     else strcpy(p->ro,r);
}


return p;
}
struct dictionar *cautare(struct dictionar *p, char *e)
{ if(p==NULL) return NULL;
    if(strcmp(e, p->eng) < 0)
    return cautare(p->stg,e);
    else
    if(strcmp(e, p->eng) > 0) return cautare(p->drept,e);
    if(strcmp(e, p->eng) ==0) return p;
    

}
void afisare(struct dictionar *p)
{
    if(p==NULL) return;
    afisare(p->stg);
    printf("%s - %s\n", p->eng, p->ro);
    afisare(p->drept);
}
void eliberareMemorie(struct dictionar *p)
{
    if(p==NULL) return;
    eliberareMemorie(p->drept);
    eliberareMemorie(p->stg);
    free(p);
}
void salvareFisier(struct dictionar*p,FILE *f)
{
    if(p==NULL) return;
    fprintf(f, "%s %s\n", p->eng, p->ro);
    salvareFisier(p->stg, f);
    salvareFisier(p->drept, f);
}