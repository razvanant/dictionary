#include "header.h"


int main()
{
 struct dictionar *radacina=NULL;
 struct dictionar *rezultat=NULL;
 int optiune;
 char englez[50],roman[50];
 FILE *f;
 f=fopen("dictionar.txt","r");
 if(f!=NULL)
 {
    while((fscanf(f, "%s %s", englez, roman) == 2))
 {
    radacina = inserare(radacina, englez, roman);
 }
 fclose(f);
}
 do
 {
printf("1-adauga cuvant\n");
printf("2-cauta cuvant\n");
printf("3-afiseaza dictionarul\n");
printf("4-iesire\n");
scanf("%d",&optiune);
switch (optiune)
{
case 1:
scanf("%s",englez);
scanf("%s",roman);
radacina=inserare(radacina,englez,roman);
    break;
    case 2:
    scanf("%s",englez);
    rezultat=cautare(radacina,englez);
    if(rezultat==NULL)
    printf("cuvantul nu a fost gasit\n");
    else printf("traducerea in romana este:%s\n",rezultat->ro);
    break;
    case 3:
    afisare(radacina);
    break;
    case 4:
   {
            FILE *f = fopen("dictionar.txt", "w"); 
              if (f != NULL) 
            {
                salvareFisier(radacina, f); 
                fclose(f);                  
                printf("Dictionarul a fost salvat cu succes!\n");
            }
            else 
            {
                printf("Eroare! Nu s-a putut salva fisierul.\n");
            }
            eliberareMemorie(radacina);
            printf("La revedere!\n");
            return 0;
     }
default:
printf("ai introdus gresit\n");
    break;
}
 } while (1);
}