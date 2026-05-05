/*
 * ttp223.c
 *
 *  Created on: 20 avr. 2026
 *      Author: mathe
 */
#include "ttp223.h"

void TTP223_Init(TTP223_t *dev, GPIO_TypeDef* port, uint16_t pin) {
    dev->port = port;
    dev->pin = pin;
    dev->last_state = false;
}

bool TTP223_IsTouched(TTP223_t *dev) {
    // Le TTP223 renvoie HIGH (1) quand il est touché (par défaut)
    return (HAL_GPIO_ReadPin(dev->port, dev->pin) == GPIO_PIN_SET);
}

bool TTP223_HasBeenPressed(TTP223_t *dev) {
    bool current_state = TTP223_IsTouched(dev);
    bool pressed = false;

    // Détection du passage de 0 à 1
    if (current_state && !dev->last_state) {
        pressed = true;
    }

    dev->last_state = current_state;
    return pressed;
}

