#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// For at finde længden af sætningen
int stringlength(char* letters)
{
  int res = 0;
  // Så længe sætningen ikke er færdig:
  while(letters[res] != '\0')
  {
    res++;
  }
  return res;
}

// Når sorterings-algoritme skal sammenligne værdier
// Skal sortere efter længden, så den længste kommer først
// Input argumenter skal se PRÆCIS sådan ud...
int compare(const void *pa, const void *pb)
{
  // Laver om til format vi "kender"
  // a og b er pointers til første element i liste
  char *a = *(char**)pa;
  char *b = *(char**)pb;

  // Fortæller sorteringsalgoritmen hvilken er længst
  return (stringlength(a)<stringlength(b));
}



int main()
{
  // Total antal ord og længden at sætning
  int total = 0, scentence_length=0;
  // antager at ingen sætninger er over 400 karakterer...
  char str[400];
  // Gør klar til en liste af lister
  // Pointer til andre pointers
  char **listen = (char **)malloc(sizeof(char*));
  // Efter jeg har fortalt hvad der kommer til at være
  // sætter jeg den nuværrende længde ind (1 tom sætning)
  listen[0] = (char*)malloc(400*sizeof(char));

  printf("Please enter a lot of words (ordsprog)!\n");
  while(fgets(str, 400, stdin)) // Så længe man indtaster
  {
    // Stop hvis vi ikke indtaster noget...
    if(str[0] == '\n')
    {
      break;
    }
    total++;
    // ------- memory management start ---------
    // Udvidder vores liste af lister med endnu en linje
    listen = realloc(listen, total*sizeof(char*));
    // Udvidder den totale plads vi råder over
    listen[0] = realloc(listen[0],total*400*sizeof(char));

    // Nu skal jeg løbe igennem og sætte alle pointers...
    // Jeg skal løbe det hele igennem igen, da hele
    // "Blokken" af alle mine sætninger kan have været
    // rykket under "realloc"...
    for(int i=0;i<total;i++)
    {
      listen[i] = listen[0] + 400*i;
    }
    // ------- memory management end ---------
    // Jeg har nu lavet plads til den, så nu kan jeg
    // kopiere sætningen ind i vores "oversigt"/liste af sætninger
    // Dette er måden at kopiere alt fra str til "listen"
    // kig evt på dokumentationen for memcpy.
    memcpy(&listen[total-1][0], &str, 400*sizeof(char));

  }
  printf("\nThank you for your scentences, here are they sorted by length \n\n");
  // Algoritme til at sortere.
  // Den sorterer efter min egen funktion "compare"
  // tjek selv dokumentationen for qsort
  qsort(listen, total, sizeof(listen[0]), compare);
  // Nu er sætningerne sorteret, så skal jeg printe dem:
  for(int i=0;i<total;i++)
  {
    // Skal gå igennem hvert eneste bogstav, da print("string")
    // ikke er mulig i c...
    int amm_letters = stringlength(listen[i]);
    for(int o=0;o<amm_letters;o++)
    {
      printf("%c", listen[i][o]);
    }
  }
  // Det var da en nem opgave, right???
  return 0;
}

// PS. har taget mig hele aftenen af skrive...
