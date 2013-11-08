#ifndef _BASE_H_
#define _BASE_H_

//Longitud de pantalla.
const int X_MAX = 78;
//Anchura de pantalla.
const int Y_MAX = 23;
//Inicio horizontal de mapa.
const int XMAP_INI = 10;
//Inicio vertical de mapa.
const int YMAP_INI = 10;
//Inicio vertical de la info.
const int YINFO_INI = 16;
//Anchura de mapa.
const int WIDTH = 60;
//Final horizonal de mapa.
const int XMAP_FIN = WIDTH + XMAP_INI;
//Retardo en milisegundos.
const int TIME_SLEEP = 50;
//Vida de las gotas de lluvia en frames.
const int MAX_LIFE_WATER = 8;
//Parte de la vida de las gotas donde tocan el suelo.
const int FLOOR_LIFE_WATER = MAX_LIFE_WATER/3;
//Maximo numero de gotas de lluvia.
const int MAX_NUM_RAINDROP = WIDTH/4;

//Tecla izquierda.
const char LEFT_KEY = 'a';
//Tecla derecha.
const char RIGHT_KEY = 'd';
//Disparo izquierdo.
const char LEFT_SHOT = 'q';
//Disparo derecha.
const char RIGHT_SHOT = 'e';
//Tecla de salida.
const char ESC = 27;

//Imagen de Heroe.
const char C_HERO = 'X';
//Imagen de bala izquierda.
const char C_BULLET_LEFT = '<';
//Imagen de bala derecha.
const char C_BULLET_RIGHT = '>';
//Imagen de enemigo.
const char C_ENEMY = 'M';
//Imagen del mapa.
const char C_MAP = '_';
//Imagen de la gota de lluvia cayendo.
const char C_FALLING_RAINDROP = ':';
//Imagen de la gota de lluvia al caer.
const char C_RAINDROP = '.';
//Imagen del marco.
const char C_FRAME = '*';

//Color del heroe.
const int COLOR_HERO = 2;	//DARK_GREEN
//Color de los enemigos.
const int COLOR_ENEMY = 4;	//DARK_RED
//Color de las balas.
const int COLOR_BULLET = 6;	//DARK_YELLOW
//Color de las gotas de lluvia.
const int COLOR_RAINDROP = 3;	//DARK_AQUA
//Color del marco.
const int COLOR_FRAME = 7;	//COLOR_CONSOLE
//Color del mapa.
const int COLOR_MAP = 3;	//DARK_AQUA
//Color inicial.
const int COLOR_RESET = 7;	//COLOR_RESET

//Numero de entidades.
const int NUM_ENTITIES = 4;
//Velocidad del enemigo izquierda.
const int MOV_ENEMY_LEFT = 1;
//Velocidad del enemigo derecha.
const int MOV_ENEMY_RIGHT = -1;
//Velocidad de la bala izquierda.
const int MOV_BULLET_LEFT = -2;
//Velocidad de la bala derecha.
const int MOV_BULLET_RIGHT = 2;
//Velocidad del heroe izquierda.
const int MOV_HERO_LEFT = -1;
//Velocidad del heroe derecha.
const int MOV_HERO_RIGHT = 1;

//Posicion del enemigo izquierda.
const int ENEMY_LEFT = 0;
//Posicion del enemigo derecha.
const int ENEMY_RIGHT = 1;
//Posicion de la bala izquierda.
const int BULLET_LEFT = 2;
//Posicion de la bala derecha.
const int BULLET_RIGHT = 3;

//Tipos de movimiento.
enum TMOV { NoMove, ToLeft, ToRight };

//Tipos de accion.
enum TACTION { MOVE_LEFT, MOVE_RIGHT, SHOT_LEFT, SHOT_RIGHT, ESCAPE, NOTHING };

#endif