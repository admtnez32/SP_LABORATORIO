#ifndef EDITORIAL_H_
#define EDITORIAL_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Funciones.h"
typedef struct
{
	int idEditorial;
	char nombre[51];

}eEditorial;

typedef struct
{
	char nombre[51];
	int contador;

}eAux;

eEditorial* editoriales_new();
eEditorial* editoriales_newParametros(char* idStr,char* editorialStr);

int editoriales_setId(eEditorial* this,int idEditorial);
int editoriales_setEditorial(eEditorial* this,char* titulo);

int editoriales_findById(LinkedList* pArrayListEditoriales, int id);

int editoriales_getEditorial(eEditorial* this,char* titulo);
int editoriales_getEditorialById(LinkedList* pArrayListEditoriales ,int id, char* editorial);
int editoriales_getId(eEditorial* this,int* id);

int editoriales_ListEditoriales(LinkedList* this);
int editoriales_ListOneEditorial(LinkedList* this, int id);

int editoriales_pedirEditorial(char* idEditorial, char* mensaje, int reintentos, LinkedList* thisE);
#endif /* EDITORIAL_H_ */
