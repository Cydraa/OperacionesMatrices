#pragma once

#include <stdio.h>

#include "FuncionesAuxiliares.hpp"

enum opcionesCaptura {
	CONSOLA = 1,
	ARCHIVO
};

void GestionarCapturaArchivo();
void GestionarSuma();
void GestionarResta();
void GestionarProdEscalar();
void GestionarMultiplicacion();
void GestionarTranspuesta();