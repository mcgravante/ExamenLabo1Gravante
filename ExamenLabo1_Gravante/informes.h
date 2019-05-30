#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_a(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[], int sizeMusico);
int informes_b(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[],
               int sizeMusico, Instrumento arrayInstrumento[], int sizeInstrumento );
int informes_c(Orquesta arrayOrquesta[], int sizeOrquesta);
int informes_d(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[],
               int sizeMusico, Instrumento arrayInstrumento[], int sizeInstrumento);
int informes_e(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[],
               int sizeMusico, Instrumento arrayInstrumento[], int sizeInstrumento);
int hardCodearDatos(Orquesta arrayOrquesta[], Musico arrayMusico[], Instrumento arrayInstrumento[]);
int ordenarPorIdOrquesta(Musico arrayMusico[], int sizeMusico);
int informes_f(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[], int sizeMusico);
int informes_g(Musico arrayMusico[], int sizeMusico,Instrumento arrayInstrumento[], int sizeInstrumento);
int informes_h(Orquesta arrayOrquesta[], int sizeOrquesta, Musico arrayMusico[], int sizeMusico);
#endif // INFORMES_H_INCLUDED
