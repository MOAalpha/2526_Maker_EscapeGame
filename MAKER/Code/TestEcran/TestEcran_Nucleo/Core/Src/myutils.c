/*
 * myutils.c
 *
 *  Created on: 13 avr. 2026
 *      Author: mathe
 */

#include "myutils.h"
#include "ili9341.h"
#include "fonts.h"
#include <stdio.h>

volatile uint8_t start_game_flag = 0;
extern RNG_HandleTypeDef hrng;

void start_story(void) {
    // 1. On nettoie l'écran en noir pour l'ambiance
    ILI9341_FillScreen(ILI9341_BLACK);

    // 2. Titre dramatique
    ILI9341_WriteString(10, 10, "ALERTE VIRALE", Font_11x18, ILI9341_RED, ILI9341_BLACK);
    HAL_Delay(1000);

    // 3. Le synopsis (défilement lent pour la lecture)
    ILI9341_WriteString(10, 40, "L'humanite s'eteint...", Font_7x10, ILI9341_WHITE, ILI9341_BLACK);
    ILI9341_WriteString(10, 55, "10 millions de morts/sec.", Font_7x10, ILI9341_WHITE, ILI9341_BLACK);
    HAL_Delay(2000);

    ILI9341_WriteString(10, 80, "Le Dr. MaBoule a le remede.", Font_7x10, ILI9341_WHITE, ILI9341_BLACK);
    ILI9341_WriteString(10, 95, "Mais il a tout cache...", Font_7x10, ILI9341_WHITE, ILI9341_BLACK);
    HAL_Delay(2000);

    // 4. L'appel à l'action
    ILI9341_FillRectangle(0, 120, 320, 2, ILI9341_RED); // Une ligne de séparation

    ILI9341_WriteString(10, 135, "ETAPE 1: FIND A CODE", Font_7x10, ILI9341_YELLOW, ILI9341_BLACK);
    ILI9341_WriteString(10, 150, "Le damier 4x4 vous attend.", Font_7x10, ILI9341_WHITE, ILI9341_BLACK);

    HAL_Delay(3000);

    // 5. Instruction pour commencer
    ILI9341_WriteString(30, 200, "> APPUYEZ SUR START <", Font_11x18, ILI9341_GREEN, ILI9341_BLACK);

    uint32_t last_msg_time = HAL_GetTick(); // On mémorise l'heure actuelle
    uint32_t test =0;

        while(start_game_flag == 0) {
            uint32_t current_time = HAL_GetTick();

            // On ne change le texte que toutes les secondes (sans bloquer !)
            if (current_time - last_msg_time > 1000) {
                uint32_t monNombre;
                if (1) {
                	char msg_buffer[50]; // Un tableau pour stocker le texte converti

                	if (HAL_RNG_GenerateRandomNumber(&hrng, &test) == HAL_OK) {
                	    // On transforme le nombre en texte (format %lu pour un uint32_t)
                	    sprintf(msg_buffer, "Plus de %lu M morts ! Depeche-toi !!!!", test%999);

                	  }

                    // On efface l'ancien texte (en dessinant un rectangle noir) avant d'écrire le nouveau
                    ILI9341_FillRectangle(0, 190, 320, 30, ILI9341_BLACK);

                    switch(monNombre % 4) {
                        case 0: ILI9341_WriteString(30, 200, "Vite ! Des gens meurent !", Font_7x10, ILI9341_YELLOW, ILI9341_BLACK); break;
                        case 1: ILI9341_WriteString(30, 200, msg_buffer, Font_7x10, ILI9341_CYAN, ILI9341_BLACK); break;
                        case 2: ILI9341_WriteString(30, 200, "Le monde compte sur toi...", Font_7x10, ILI9341_GREEN, ILI9341_BLACK); break;
                        case 3 : ILI9341_WriteString(30, 200, "> APPUYEZ SUR START <", Font_11x18, ILI9341_GREEN, ILI9341_BLACK); break;
                    }
                }
                monNombre++;
                last_msg_time = current_time; // On relance le chrono pour le prochain message
            }

            // La boucle tourne à fond, donc dès que le flag passe à 1, on sort direct !
        }
    // Lance la suite du jeu ici...
    ILI9341_FillScreen(ILI9341_BLACK);
    ILI9341_WriteString(30, 90, "Bravo, tu as fait explose l'antidote ! C'est termine ! TU AS PERDU !!!", Font_11x18, ILI9341_RED, ILI9341_BLACK);
}
