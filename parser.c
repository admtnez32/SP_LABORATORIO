#include <stdio.h>
#include <stdlib.h>
#include "Parser.h"


/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_libroFromText(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno = -1;
	char id[50];
	char idEditorial[50];
	char titulo[50];
	char autor[50];
	char precio[50];
	eLibro* eAux;

	if(pFile != NULL && pArrayListLibros != NULL)
	{
		ll_clear(pArrayListLibros);
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio, idEditorial);
			eAux = libros_newParametros(id, titulo, autor, precio, idEditorial);
			ll_add(pArrayListLibros, eAux);
		}
		retorno = 0;
	}
    return retorno;
}

int parser_editorialesFromText(FILE* pFile , LinkedList* pArrayListEditoriales)
{
	int retorno = -1;
	char id[50];
	char editorial[50];

	eEditorial* eAux;

	if(pFile != NULL && pArrayListEditoriales != NULL)
	{
		ll_clear(pArrayListEditoriales);
		fscanf(pFile, "%[^,],%[^\n]\n", id, editorial);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^\n]\n", id, editorial);
			eAux = editoriales_newParametros(id, editorial);
			ll_add(pArrayListEditoriales, eAux);
		}
		retorno = 0;
	}
    return retorno;
}

/// @brief Parsea el archivo data.csv (modo texto) con los datos de los empleados
///
/// @param pFile FILE*
/// @param pArrayListEmployee LinkedList*
/// @return int
int parser_LibrosToText(FILE* pFile , LinkedList* this, LinkedList* thisE)
{
	int retorno = -1;
	int id;
	int idEditorial;
	float precio;
	char autor[50];
	char titulo[51];
	char editorial[51];
	eLibro* aux;

	if(pFile != NULL && this != NULL && thisE != NULL)
	{
		fprintf(pFile, "id,titulo,autor,precio,editorial\n");
		for(int i = 0; i < ll_len(this); i++)
		{
			aux = (eLibro*) ll_get(this, i);
			libros_getId(aux, &id);
			libros_getPrecio(aux, &precio);
			libros_getAutor(aux, autor);
			libros_getTitulo(aux, titulo);
			libros_getIdEditorial(aux, &idEditorial);

			editoriales_getEditorialById(thisE, idEditorial, editorial);

			fprintf(pFile, "%d,%s,%s,%.2f,%s\n", id, titulo, autor, precio, editorial);
		}

		retorno = 0;
	}

	return retorno;
}
