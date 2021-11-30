#include "LinkedList.h"
#include "parser.h"
#include "Funciones.h"
#include "Menu.h"
#include "Editorial.h"
#include "Libro.h"

int controller_LibroLoadFromText(char* path , LinkedList* pArrayListLibro);
int controller_EditorialesLoadFromText(char* path , LinkedList* pArrayListEditoriales);

int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_ListEditoriales(LinkedList* pArrayListEditoriales);
int controller_listMinotauro(LinkedList* this, LinkedList* thisEditoriales);

int controller_sortLibrosByAutor(LinkedList* pArrayList);
int controller_sortLibrosByEditorial(LinkedList* pArrayList);



int controller_saveAsText(char* path , LinkedList* this, LinkedList* thisE);
int controller_countEditorialConMasLibros(LinkedList* this, LinkedList* thisEditorial);
int controller_addLibro(LinkedList* this, LinkedList* thisEditorial);

int controller_map(LinkedList* this, LinkedList* thisE);
