/* array.h */

// Finder ud af, at hvis kommandoen ikke allerede eksisterer
// Så bliver den defineret nu ved
#ifndef MAKE2DSPACE_H
#define MAKE2DSPACE_H
double** make2Dspace(int m, int n);
#endif

// Samme for anden kommando
#ifndef FREE2DSPACE_H
#define FREE2DSPACE_H
void free2Dspace(double** matrix);
#endif
