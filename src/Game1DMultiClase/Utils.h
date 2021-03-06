#ifndef _MY_UTILS_H_
#define _MY_UTILS_H_

#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <vector>

//Lleva el cursor de pantalla a la posicion deseada.
void gotoxy(int, int);

//Devuelve un numero al azar entre los argumentos pasados.
int Randomize(int, int);

//Cambia el color del texto de consola.
void SetColorText(int);

//Oculta el cursor en pantalla.
void hidecursor(void);

#endif
