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
 * Mapeamento de teclas para ações.
 */

/**
 * Muda o modo de edição de "Inserção" para "Manipulação".
 */
const char CHANGE_MODE = 'q';
/**
 * Alterna o tipo de polígono entre aberto e fechado.
 */
const char CHANGE_POLYGON = 'a';
/**
 * Rotaciona um polígono se ele estiver selecionado.
 */
const char ROTATE = 'r';
/**
 * Aumenta a escala de um polígono se ele estiver selecionado.
 */
const char SCALE_UP = 'b';
/**
 * Diminui a escala de um polígono se ele estiver selecionado.
 */
const char SCALE_DOWN = 's';
/**
 * Remove um polígono se ele estiver selecionado.
 */
const char REMOVE = 'd';
/**
 * Finaliza a inserção de um polígono.
 */
const char FINISH = 'f';
/**
 * Adiciona um polígono filho a um polígono que está selecionado ou que está sendo inserido.
 */
const char ADD_SON = 'i';
/**
 * Muda a cor do polígono de forma randômica.
 */
const char CHANGE_COLOR = 'c';
/**
 * Remove um vértice que esteja selecionado.
 */
const char REMOVE_VERTEX = 'v';


/**
 * @}
 */

#endif /* KEYBOARDMAP_H_ */
