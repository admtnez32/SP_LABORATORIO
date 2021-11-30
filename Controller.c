#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_LibroLoadFromText(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	FILE *pFile = NULL;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		parser_libroFromText(pFile, pArrayListLibro);
		retorno = 0;
		fclose(pFile);
		printf("\n--- Datos cargados con exito ---\n\n");
	}
	else
	{
		printf("\n--- Error al abrir el archivo txt ---\n\n");
	}

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_EditorialesLoadFromText(char* path , LinkedList* pArrayListEditoriales)
{
	int retorno = -1;
	FILE *pFile = NULL;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		parser_editorialesFromText(pFile, pArrayListEditoriales);
		retorno = 0;
		fclose(pFile);
		printf("\n--- Datos cargados con exito ---\n\n");
	}
	else
	{
		printf("\n--- Error al abrir el archivo txt ---\n\n");
	}

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{
	int retorno = -1;
	int i;


	eLibro* auxLibro=NULL;

	if(pArrayListLibros != NULL && pArrayListEditoriales != NULL){

		printf("%4s %20s %20s %20s %20s\n", "ID:", "Titulo:", "Autor:", "Precio:", "Editorial");

		for(i=0;i<ll_len(pArrayListLibros);i++){

			auxLibro = ll_get(pArrayListLibros, i);
			libros_ListLibros(auxLibro, pArrayListEditoriales);
		}
		printf("\n\n");

		retorno = 0;
	}
    return retorno;
}

int controller_ListEditoriales(LinkedList* pArrayListEditoriales)
{
	int retorno = -1;

	if(pArrayListEditoriales != NULL){

		printf("%4s %20s\n", "ID:", "Editorial");

		editoriales_ListEditoriales(pArrayListEditoriales);

		printf("\n\n");

		retorno = 0;
	}
    return retorno;
}

int controller_sortLibrosByAutor(LinkedList* pArrayList)
{
	int retorno = -1;

	if(pArrayList != NULL && ll_sort(pArrayList, libros_CompareByAutor, 1) == 0)
	{
		printf("\n--- Libros ordenados correctamente ---\n\n");
	}

    return retorno;
}

int controller_sortLibrosByEditorial(LinkedList* pArrayList)
{
	int retorno = -1;

	if(pArrayList != NULL && ll_sort(pArrayList, libros_compareByEditorial, 1) == 0)
	{
		printf("\n--- Libros ordenados correctamente ---\n\n");
	}

    return retorno;
}

int controller_listMinotauro(LinkedList* this, LinkedList* thisEditoriales)
{
	int retorno = -1;
	LinkedList* newLl = NULL;

	if(this != NULL && thisEditoriales != NULL)
	{
		retorno = 0;
		newLl = ll_filter(this, libros_filter);

		if(newLl != NULL)
		{
			controller_ListLibros(newLl, thisEditoriales);
			controller_saveAsText("minotauro.csv", newLl, thisEditoriales);
			retorno = 1;
		}
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
*/
int controller_saveAsText(char* path , LinkedList* this, LinkedList* thisE)
{
	int retorno = -1;
	FILE* pFile;

	pFile = fopen(path, "w");

	if(pFile != NULL && this != NULL)
	{
		parser_LibrosToText(pFile, this, thisE);
		fclose(pFile);
		retorno = 0;
		printf("\n--- Datos guardados en archivo con exito ---\n\n");
	}
	else
	{
		printf("\n--- Error al abrir el archivo txt ---\n\n");
	}

    return retorno;
}

int controller_countEditorialConMasLibros(LinkedList* this, LinkedList* thisEditorial)
{
	int retorno = -1;
	int idEditorial;
	int cantidad=0;
	int cantidadNew = 0;
	eEditorial* pElement;
	eAux contador[ll_len(thisEditorial)];

	if(this != NULL && thisEditorial != NULL)
	{

		for(int i = 0; i < ll_len(thisEditorial); i++)
		{
			pElement = (eEditorial*) ll_get(thisEditorial, i);

			editoriales_getId(pElement, &idEditorial);
			cantidad = ll_countEditorial(this, libros_countEditorial, idEditorial);

			if(cantidad >= cantidadNew || i == 0)
			{
				cantidadNew = cantidad;
				strcpy(contador[i].nombre, pElement->nombre);
				contador[i].contador = cantidadNew;
			}
		}

		printf("\nLa/s editorial/es con mas libros es/son: \n");
		for(int i = 0; i < ll_len(thisEditorial); i++)
		{
			if(contador[i].contador == cantidadNew)
			{
				printf("\n%s\n", contador[i].nombre);
			}
		}
		printf("\nCantidad de libros: %d\n\n", cantidadNew);
		retorno = 0;
	}

	return retorno;
}


int controller_addLibro(LinkedList* this, LinkedList* thisEditorial)
{
	int retorno = -1;
	eLibro* newLibro = NULL;

	newLibro = libros_new();

	if(this != NULL && thisEditorial != NULL)
	{
		newLibro = libros_addLibro(this, thisEditorial);

		ll_add(this, newLibro);
	}

	return retorno;
}






