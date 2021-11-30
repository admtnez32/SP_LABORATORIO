#include "Menu.h"


void MenuPrincipal(void)
{
	printf("*********************************************************************************\n\n"
		"Menu:\n\n"
		 " 1. Cargar los datos de los LIBROS desde el archivo.\n"
		 " 2. Cargar los datos de las EDITORIALES desde el archivo.\n"
		 " 3. Ordenar libros según autor.\n"
		 " 4. Imprimir libros\n"
		 " 5. Listado de libros de editorial MINOTAURO\n\n"
		 " 0. Salir\n\n"
		"*********************************************************************************\n\n");
}


void MenuModificar(void)
{
	printf("******************************************\n\n"
			"Modificar:\n\n"
			" 1. Nombre\n"
			" 2. Horas trabajadas\n"
			" 3. Salario\n\n"
			" 0. Menu principal\n\n"
			"******************************************\n\n");
}


void MenuOrdenar(void)
{
	printf("******************************************\n\n"
				"Ordenar por:\n\n"
				" 1. Nombre\n"
				" 2. ID\n"
				" 3. Horas trabajadas\n"
				" 4. Salario\n\n"
				" 0. Menu principal\n\n"
				"******************************************\n\n");
}
