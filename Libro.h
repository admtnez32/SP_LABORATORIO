#ifndef LIBRO_H_
#define LIBRO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editorial.h"
#include "Funciones.h"

typedef struct
{
	int id;
	char titulo[51];
	char autor[51];
	float precio;
	int idEditorial;
}eLibro;

eLibro* libros_new();
eLibro* libros_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr);
int libros_NextId(char* path, char* id);
int libros_setId(eLibro* this,int );
int libros_setIdEditorial(eLibro* this,int );
int libros_setTitulo(eLibro* this,char* );
int libros_setAutor(eLibro* this,char* );
int libros_setPrecio(eLibro* this,float);

int libros_getId(eLibro* this,int* );
int libros_getIdEditorial(eLibro* this,int* );
int libros_getTitulo(eLibro* this,char* );
int libros_getAutor(eLibro* this,char* );
int libros_getPrecio(eLibro* this,float*);


int libros_ListLibros(eLibro* this, LinkedList* pArrayListEditoriales);

int libros_compareByEditorial(void* editorialUno, void* editorialDos);
int libros_CompareByAutor(void* autorUno, void* autorDos);

int libros_filter(void* element);

int libros_countEditorial(void* element, int id);
int libros_countEditorialMinotauro(void* element);

eLibro* libros_addLibro(LinkedList* this, LinkedList* thisEditorial);
#endif /* LIBRO_H_ */
