/*
 ============================================================================
 Name        : SP_LABO.c
 Author      : Martinez Alexis
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"
#include "Funciones.h"
#include "Menu.h"
#define TAM 51

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* libros;
	LinkedList* editoriales;
	int opcion;
	int flagLibros = 0;
	int flagEditorial = 0;
	int cantidad;
	char archivo[TAM];

	eEditorial* prueba;
	prueba = editoriales_new();

	prueba->idEditorial = 15;

	libros = ll_newLinkedList();
	editoriales = ll_newLinkedList();


	if(libros != NULL && editoriales != NULL)
	{
		do
		{
			MenuPrincipal();
			PedirNumero(&opcion, "Ingrese opcion: ");

			switch(opcion)
			{
				case 1:
					PedirCaracteresConReintentos(archivo, TAM, "Ingrese el nombre del archivo sin la extension: ", 3);
					if(strcmp("libros", archivo) == 0)
					{
						strcat(archivo, ".csv");

						if(controller_LibroLoadFromText(archivo, libros) == 0)
						{
							flagLibros = 1;
						}
					}
					else
					{
						printf("\n--- Nombre del archivo incorrecto ---\n--- Volviendo al Menu Principal ---\n\n");
					}
					break;

				case 2:
						PedirCaracteresConReintentos(archivo, TAM, "Ingrese el nombre del archivo sin la extension: ", 3);

						if(strcmp("editoriales", archivo) == 0)
						{
							strcat(archivo, ".csv");

							if(controller_EditorialesLoadFromText(archivo, editoriales) == 0)
							{
								flagEditorial = 1;
							}
						}
						else
						{
							printf("\n--- Nombre del archivo incorrecto ---\n--- Volviendo al Menu Principal ---\n\n");
						}
					break;

				case 3:
					if(flagLibros && flagEditorial)
					{
						controller_sortLibrosByAutor(libros);
					}
					else
					{
						printf("\n--- No hay datos cargados ---\n");
					}
					break;

				case 4:
					if(flagLibros && flagEditorial)
					{
						controller_ListLibros(libros, editoriales);
					}
					else
					{
						printf("\n--- No hay datos cargados ---\n");
					}
					break;

				case 5:
					if(flagLibros && flagEditorial)
					{
						controller_listMinotauro(libros, editoriales);
					}
					else
					{
						printf("\n--- No hay datos cargados ---\n");
					}
					break;

				case 6:
					cantidad = ll_countEditorialMinotauro(libros, libros_countEditorialMinotauro);

					if(cantidad != -1)
					{
						printf("\nCantidad de libros de la editorial MINOTAURO: %d\n\n", cantidad);
					}
					else
					{
						printf("\nNo hay libros de la editorial Minotauro\n\n");
					}
					break;

				case 7:
					controller_ListEditoriales(editoriales);
					//controller_countEditorialConMasLibros(libros, editoriales);
					break;

				case 8:
					controller_addLibro(libros, editoriales);
					break;

				case 0:
					printf("\n--- Adios ---\n\n");
					break;

				default:
					printf("\n--- Opcion incorrecta ---\n\n");
					break;
			}

		}while(opcion != 0);
	}

	return EXIT_SUCCESS;
}
