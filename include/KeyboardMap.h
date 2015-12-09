/*
 * KeyboardMap.h
 *
 *  Created on: 30/04/2015
 *      Author: bigwi_000
 */

#ifndef KEYBOARDMAP_H_
#define KEYBOARDMAP_H_

/**
 * @addtogroup KeyboardMap
 * @{
 * Mapeamento de teclas para a��es.
 */

/**
 * Muda o modo de edi��o de "Inser��o" para "Manipula��o".
 */
const char CHANGE_MODE = 'q';
/**
 * Alterna o tipo de pol�gono entre aberto e fechado.
 */
const char CHANGE_POLYGON = 'a';
/**
 * Rotaciona um pol�gono se ele estiver selecionado.
 */
const char ROTATE = 'r';
/**
 * Aumenta a escala de um pol�gono se ele estiver selecionado.
 */
const char SCALE_UP = 'b';
/**
 * Diminui a escala de um pol�gono se ele estiver selecionado.
 */
const char SCALE_DOWN = 's';
/**
 * Remove um pol�gono se ele estiver selecionado.
 */
const char REMOVE = 'd';
/**
 * Finaliza a inser��o de um pol�gono.
 */
const char FINISH = 'f';
/**
 * Adiciona um pol�gono filho a um pol�gono que est� selecionado ou que est� sendo inserido.
 */
const char ADD_SON = 'i';
/**
 * Muda a cor do pol�gono de forma rand�mica.
 */
const char CHANGE_COLOR = 'c';
/**
 * Remove um v�rtice que esteja selecionado.
 */
const char REMOVE_VERTEX = 'v';


/**
 * @}
 */

#endif /* KEYBOARDMAP_H_ */
