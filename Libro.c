#include "Libro.h"

/// @brief Asignar espacio en memoria tipo Employee
///
/// @return Employee*
eLibro* libros_new()
{
	return (eLibro*) malloc(sizeof(eLibro));
}

eLibro* libros_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr)
{
	int id;
	int idEditorial;
	float precio;
	eLibro* this;
	this = NULL;

	this = libros_new();

	if(this != NULL)
	{
		id = atoi(idStr);
		idEditorial = atoi(idEditorialStr);
		precio = atof(precioStr);

		libros_setId(this, id);
		libros_setTitulo(this, tituloStr);
		libros_setAutor(this, autorStr);
		libros_setPrecio(this, precio);
		libros_setIdEditorial(this, idEditorial);
	}

	return (eLibro*)this;
}

int libros_setId(eLibro* this,int id)
{
	int retorno = -1;

	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int libros_setIdEditorial(eLibro* this,int idEditorial)
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
int libros_setTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo, titulo);
		retorno = 0;
	}

	return retorno;
}

/// @brief	Setear horas trabajadas
///
/// @param this Employee*
/// @param horasTrabajadas int
/// @return int
int libros_setAutor(eLibro* this,char* autor)
{
	int retorno = -1;

	if(this != NULL && autor != NULL)
	{
		strcpy(this->autor, autor);
		retorno = 0;
	}

	return retorno;
}

/// @brief	Setear sueldo
///
/// @param this Employee*
/// @param sueldo int
/// @return int
int libros_setPrecio(eLibro* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 0;
	}

	return retorno;
}

/// @brief	Obtener un id
///
/// @param this Employee*
/// @param id int*
/// @return int
int libros_getId(eLibro* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

return retorno;
}

/// @brief	Obtener un id
///
/// @param this Employee*
/// @param id int*
/// @return int
int libros_getIdEditorial(eLibro* this,int* idEditorial)
{
	int retorno = -1;

	if(this != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}

return retorno;
}

/// @brief	Obtener nombre
///
/// @param this Employee*
/// @param nombre char*
/// @return int
int libros_getTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(titulo, this->titulo);
		retorno = 0;
	}


return retorno;
}

/// @brief	Obtener nombre
///
/// @param this Employee*
/// @param nombre char*
/// @return int
int libros_getAutor(eLibro* this,char* autor)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(autor, this->autor);
		retorno = 0;
	}


return retorno;
}

/// @brief	Obtener sueldo
///
/// @param this Employee*
/// @param sueldo int*
/// @return int
int libros_getPrecio(eLibro* this,float* precio)
{
	int retorno = -1;

	if(this != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}

return retorno;
}

int libros_ListLibros(eLibro* this, LinkedList* thisE)
{
	int retorno = -1;
	int id;
	int idEditorial;
	char editorial[50];
	char titulo[50];
	char autor[50];
	float precio;

	if(this != NULL)
	{
		libros_getId(this,&id);
		libros_getTitulo(this,titulo);
		libros_getAutor(this,autor);
		libros_getPrecio(this,&precio);
		libros_getIdEditorial(this,&idEditorial);

		editoriales_getEditorialById(thisE, idEditorial, editorial);

		printf("%4d %20s %20s %20.2f %20s\n",id,titulo,autor,precio, editorial);

		retorno = 0;
	}

	return retorno;
}

int libros_CompareByAutor(void* autorUno, void* autorDos)
{
	int retorno;
	eLibro* eUno;
	eLibro* eDos;

	if(autorUno != NULL && autorDos != NULL)
	{
		eUno = (eLibro*) autorUno;
		eDos = (eLibro*) autorDos;
		retorno = strcmpi(eUno->autor, eDos->autor);
		printf("\nOrdenando... Aguarde.\n\n");
	}

	return retorno;
}

int libros_compareByEditorial(void* editorialUno, void* editorialDos)
{
	eLibro* eUno;
	eLibro* eDos;
	int retorno = 0;

	if(editorialDos != NULL && editorialDos != NULL)
	{
		eUno = (eLibro*) editorialUno;
		eDos = (eLibro*) editorialDos;

		if(eUno->idEditorial > eDos->idEditorial)
		{
			retorno = 1;
		}
		else
		{
			if(eUno->idEditorial < eDos->idEditorial)
			{
				retorno = -1;
			}
		}
		printf("\nOrdenando... Aguarde.\n\n");
	}
	return retorno;
}

int libros_filter(void* element)
{
	int retorno = 0;
	eLibro* aux = NULL;

	aux = (eLibro*) element;

	if(aux->idEditorial == 50)
	{

		retorno = 1;
	}


	return retorno;
}

int libros_countEditorialMinotauro(void* element)
{
	int retorno = -1;
	eLibro* aux = NULL;

	aux = (eLibro*) element;

	if(aux != NULL && aux->idEditorial == 50)
	{
		retorno = 0;
	}

	return retorno;
}

int libros_countEditorial(void* element, int id)
{
	int retorno = -1;
	eLibro* aux = NULL;

	aux = (eLibro*) element;

	if(aux != NULL && aux->idEditorial == id)
	{
		retorno = 0;
	}

	return retorno;
}

int libros_NextId(char* path, char* id)
{
	int retorno = -1;
	int aux;
	char idAux[50];

	FILE* pFile;

	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		fscanf(pFile, "%[^\n]", idAux);

		fclose(pFile);

		aux = atoi(idAux);
		aux++;
		itoa(aux, idAux, 10);

		strcpy(id, idAux);

		pFile = fopen(path, "w");

		fprintf(pFile, "%s", idAux);

		fclose(pFile);

		retorno = 0;
	}

return retorno;
}

eLibro* libros_addLibro(LinkedList* this, LinkedList* thisEditorial)
{
	eLibro* newLibro = NULL;
	char idStr[51];
	char titulo[51];
	char autor[51];
	char precio[51];
	char idEditorialStr[51];
	newLibro = libros_new();

	if(this != NULL && thisEditorial != NULL && newLibro != NULL)
	{
		if(	PedirNombreConReintentos(titulo, 51, "Ingrese titulo: ", 3) &&
			PedirNombreConReintentos(autor, 51, "Ingrese autor: ", 3) &&
			PedirNumeroCharConReintentos(precio, "Ingrese precio: ", 3) &&
			editoriales_pedirEditorial(idEditorialStr, "Ingrese id de la editorial: ", 3, thisEditorial) == 1 &&
			libros_NextId("lista_id.csv", idStr) == 0)
		{
				newLibro = libros_newParametros(idStr, titulo, autor, precio, idEditorialStr);
		}
	}

	return newLibro;
}

int libros_aplicarDescuento(void* element)
{
	int retorno = -1;
	float auxPrecio;

	eLibro* aux = NULL;

	aux = (eLibro*) element;

	if(aux != NULL && aux->idEditorial == 53 && aux->precio > 300)
	{
		auxPrecio = aux->precio;
		aux->precio = aux->precio * 0.8;
		printf("\n--- Descuento del 20 aplicado al libro %s---\nPrecio anterior: $%.2f\nPrecio actual $%.2f\n\n", aux->titulo, auxPrecio, aux->precio);
		retorno = 0;
	}
	else
	{
		if(aux != NULL && aux->idEditorial == 55 && aux->precio > 200)
		{
			auxPrecio = aux->precio;
			aux->precio = aux->precio * 0.9;
			printf("\n--- Descuento del 10 aplicado al libro %s---\nPrecio anterior: $%.2f\nPrecio actual $%.2f\n\n", aux->titulo, auxPrecio, aux->precio);
			retorno = 1;
		}
	}

	return retorno;
}
