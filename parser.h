#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"

int parser_libroFromText(FILE* pFile , LinkedList* pArrayListLibros);
int parser_editorialesFromText(FILE* pFile , LinkedList* pArrayListEditoriales);
int parser_LibrosToText(FILE* pFile , LinkedList* this, LinkedList* thisE);
#endif /* PARSER_H_ */
