#include "Editorial.h"

eEditorial* editoriales_new()
{
	return (eEditorial*) malloc(sizeof(eEditorial));
}

eEditorial* editoriales_newParametros(char* idStr,char* editorialStr)
{
	int id;

	eEditorial* this;
	this = NULL;

	this = editoriales_new();

	if(this != NULL)
	{
		id = atoi(idStr);
		editoriales_setId(this, id); //SET AND GET EDITORIAL
		editoriales_setEditorial(this, editorialStr);
	}

	return (eEditorial*)this;
}

int editoriales_setId(eEditorial* this,int idEditorial)
{
	int retorno = -1;

	if(this != NULL && idEditorial >= 0)
	{
		this->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

/// @brief Setear nombre
///
/// @param this Employee*
/// @param nombre char*
/// @return int
int editoriales_setEditorial(eEditorial* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->nombre, titulo);
		retorno = 0;
	}

	return retorno;
}

/// @brief	Obtener un id
///
/// @param this Employee*
/// @param id int*
/// @return int
int editoriales_getId(eEditorial* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->idEditorial;
		retorno = 0;
	}

return retorno;
}

/// @brief	Obtener nombre
///
/// @param this Employee*
/// @param nombre char*
/// @return int
int editoriales_getEditorial(eEditorial* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(titulo, this->nombre);
		retorno = 0;
	}

return retorno;
}

int editoriales_findById(LinkedList* pArrayListEditoriales, int id)
{
	int retorno = -1;
	eEditorial* auxEditorial = NULL;

	if(pArrayListEditoriales != NULL && id >= 50)
	{

		for(int i = 0; i < ll_len(pArrayListEditoriales); i++)
		{
			auxEditorial = ll_get(pArrayListEditoriales, i);
			if(id == auxEditorial->idEditorial)
			{
				retorno = i;
				break;
			}
		}
	}

return retorno;
}

int editoriales_getEditorialById(LinkedList* pArrayListEditoriales ,int id, char* editorial)
{
	int retorno = -1;
	int indice;
	eEditorial* this = NULL;

	if(pArrayListEditoriales != NULL)
	{
		indice = editoriales_findById(pArrayListEditoriales, id);
		if(indice >= 0)
		{
			retorno = 0;
			this = ll_get(pArrayListEditoriales, indice);

			if(this != NULL)
			{
				strcpy(editorial, this->nombre);
				retorno = 1;
			}
		}
	}
	return retorno;
}

int editoriales_ListEditoriales(LinkedList* this)
{
	int retorno = -1;
	eEditorial* pElement;

	if(this != NULL)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			pElement = ll_get(this, i);
			printf("%4d %20s \n",pElement->idEditorial,pElement->nombre);
		}

		retorno = 0;
	}
	return retorno;
}

int editoriales_ListOneEditorial(LinkedList* this, int id)
{
	int retorno = -1;
	char editorial[51];
	eEditorial* pElement;

	if(this != NULL && id > -1)
	{
		for(int i = 0; i < ll_len(this); i++)
		{
			pElement = ll_get(this, i);

			if(pElement->idEditorial == id)
			{
				editoriales_getEditorial(pElement, editorial);
				break;
			}
		}


		printf("%20s \n", editorial);
	}

return retorno;
}


int editoriales_pedirEditorial(char* idEditorial, char* mensaje, int reintentos, LinkedList* thisE)
{
	int retorno = -1;
	int id;
	char idStr[51];

	if(thisE != NULL && reintentos > 0)
	{
		retorno = 0;
		do{
			editoriales_ListEditoriales(thisE);
			PedirNumeroConReintentos(&id, mensaje, reintentos);

			if(editoriales_findById(thisE, id) > -1)
			{
				itoa(id, idStr, 10);
				strcpy(idEditorial, idStr);
				reintentos = 0;
				retorno = 1;
			}
			else
			{
				printf("\n--- Id incorrecto ---\n--- Le quedan %d reintentos ---\n\n", reintentos-1);

			}

			reintentos--;
		}while(reintentos > 0);
	}
	return retorno;
}


