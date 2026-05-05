/*
 * ttp223.h
 *
 *  Created on: 20 avr. 2026
 *      Author: mathe
 */

#ifndef TTP223_H_
#define TTP223_H_


#include "stm32l4xx_hal.h"
#include <stdbool.h>

/**
 * @brief Structure de contrôle pour le capteur TTP223
 */
typedef struct {
    GPIO_TypeDef* port;
    uint16_t pin;
    bool last_state;
} TTP223_t;

/**
 * @brief Initialise la structure du capteur
 * @param dev : pointeur vers la structure TTP223_t
 * @param port : Port GPIO (ex: GPIOB)
 * @param pin : Broche GPIO (ex: GPIO_PIN_8)
 */
void TTP223_Init(TTP223_t *dev, GPIO_TypeDef* port, uint16_t pin);

/**
 * @brief Retourne l'état brut du capteur (vrai si touché)
 */
bool TTP223_IsTouched(TTP223_t *dev);

/**
 * @brief Détecte un front montant (appui unique)
 * @return true seulement à l'instant où l'appui est détecté
 */
bool TTP223_HasBeenPressed(TTP223_t *dev);

#endif /* SRC_TTP223_H_ */
