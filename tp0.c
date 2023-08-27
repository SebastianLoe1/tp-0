#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char NORMAL = 'N';
const char FUEGO = 'F';
const char AGUA = 'A';
const char PLANTA = 'P';
const char ELECTIRO = 'E';
const char ROCA = 'R';

enum TIPO { NORMAL, FUEGO, AGUA, PLANTA, ELECTRICO, ROCA };

struct ataque {
	char nombre[20];
	enum TIPO tipo;
	unsigned int poder;
};

struct ataque *parsear_ataque(char *texto, struct ataque *ataque)
{
    char nombre[20];
    char tipo;
    unsigned int poder;

    if (sscanf(texto, "%[^;];%c;%u", nombre, &tipo, &poder) != 3) {
        return NULL;
    }

    strncpy(ataque->nombre, nombre, sizeof(ataque->nombre));

    switch (tipo) {
        case NORMAL:
            ataque->tipo = NORMAL;
            break;
        case FUEGO:
            ataque->tipo = FUEGO;
            break;
        case AGUA:
            ataque->tipo = AGUA;
            break;
        case PLANTA:
            ataque->tipo = PLANTA;
            break;
        case ELECTIRO:
            ataque->tipo = ELECTRICO;
            break;
        case ROCA:
            ataque->tipo = ROCA;
            break;
        default:
            return NULL;
    }
    ataque->poder = poder;

    return ataque;
}

int main()
{
	struct ataque un_ataque;
	int errores = 0;

	if (parsear_ataque("", &un_ataque) != NULL) {
		printf("Se espera que no se pueda parsear un string vacío D:\n");
		errores++;
	} else
		printf("Parseo de un string vacío 👍\n");

	if (parsear_ataque("Rayo;E;", &un_ataque) != NULL) {
		printf("Se espera que no se pueda parsear un string incorrecto D:\n");
		errores++;
	} else
		printf("Parseo de un string incorrecto 👍\n");


	if (parsear_ataque("Rayo;E;5", &un_ataque) == NULL) {
		printf("Se espera que se pueda parsear un string correcto D:\n");
		errores++;
	} else if (strcmp(un_ataque.nombre, "Rayo") == 0 &&
		 un_ataque.tipo == ELECTRICO && un_ataque.poder == 5) {
		printf("Parseo de un string correcto 👍\n");
	} else {
		printf("Se parseó el string pero los valores son incorrectos 🤔\n");
		errores++;
	}

	return errores;
}
