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
volatile uint8_t touche_TTP = 0;
extern RNG_HandleTypeDef hrng;

//Taille du code à fournir

#define CODE_SIZE 6
#define CODE_LIMIT 1000000

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
    uint32_t total_death = 0;
    uint32_t defilement = 3;

        while(start_game_flag == 0) {
            uint32_t current_time = HAL_GetTick();

            // On ne change le texte que toutes les secondes (sans bloquer !)
            if (current_time - last_msg_time > 1000) {

                defilement++;

                	char msg_buffer[100]; // Un tableau pour stocker le texte converti

                	if (HAL_RNG_GenerateRandomNumber(&hrng, &test) == HAL_OK) {
                	    // On transforme le nombre en texte (format %lu pour un uint32_t)
                		total_death += test%100000;
                	    sprintf(msg_buffer, "%lu morts ! Depeche-toi !!!!", total_death);

                	  }

                    // On efface l'ancien texte (en dessinant un rectangle noir) avant d'écrire le nouveau
                    ILI9341_FillRectangle(0, 190, 320, 30, ILI9341_BLACK);

                    switch(defilement % 4) {
                        case 0: ILI9341_WriteString(30, 200, "Vite ! Des gens meurent !", Font_7x10, ILI9341_YELLOW, ILI9341_BLACK); break;
                        case 1: ILI9341_WriteString(30, 200, msg_buffer, Font_7x10, ILI9341_CYAN, ILI9341_BLACK); break;
                        case 2: ILI9341_WriteString(30, 200, "Le monde compte sur toi...", Font_7x10, ILI9341_GREEN, ILI9341_BLACK); break;
                        case 3 : ILI9341_WriteString(30, 200, "> APPUYEZ SUR START <", Font_11x18, ILI9341_GREEN, ILI9341_BLACK); break;
                    }

                last_msg_time = current_time; // On relance le chrono pour le prochain message
            }

            // La boucle tourne à fond, donc dès que le flag passe à 1, on sort direct !
        }
    // Lance la suite du jeu ici...

   damier();
}


void damier(){
	ILI9341_FillRectangle(0, 0, 320, 240, ILI9341_BLACK);
	ILI9341_WriteString(10, 10, "ETAPE 1 : LE DAMIER!", Font_16x26, ILI9341_WHITE, ILI9341_BLACK);
	ILI9341_WriteString(10, 45, "APPUYER SUR LES TOUCHES ", Font_7x10, ILI9341_WHITE, ILI9341_BLACK);
	ILI9341_WriteString(10, 65, "EN RESPECTANT L'ORDRE.", Font_7x10, ILI9341_WHITE, ILI9341_BLACK);


	uint32_t code = 0;
	int code_afficher[CODE_SIZE];
	char instructions[32];
	uint32_t debut_sequence = HAL_GetTick();


	//Génération d'un code aléatoire !
	if (HAL_RNG_GenerateRandomNumber(&hrng, &code) == HAL_OK) {

		code = code%CODE_LIMIT;
		// On remplit le tableau de la droite vers la gauche
			for (int i = CODE_SIZE-1; i >= 0; i--) {
			    code_afficher[i] = code % 10;  // Récupère le dernier chiffre (ex: 9)
			    code = code / 10; // Supprime le dernier chiffre (ex: 12345678)
			}
			/*
		sprintf(instructions, "[%d]  [%d]  [%d]", code_afficher[0], code_afficher[1], code_afficher[2]);
		ILI9341_WriteString(50, 90, instructions, Font_16x26, ILI9341_BLACK, ILI9341_GREEN);
		sprintf(instructions, "[%d]  [%d]  [%d]", code_afficher[3], code_afficher[4], code_afficher[5]);
		ILI9341_WriteString(50, 135, instructions, Font_16x26, ILI9341_BLACK, ILI9341_GREEN);
		sprintf(instructions, "[%d]  [%d]  [%d]", code_afficher[6], code_afficher[7], code_afficher[8]);
		ILI9341_WriteString(50, 175, instructions, Font_16x26, ILI9341_BLACK, ILI9341_GREEN);
		*/





	}else{
		ILI9341_FillRectangle(0,0, 320, 240, ILI9341_BLACK);
		ILI9341_WriteString(10, 10, "Une erreur s'est produite !", Font_16x26, ILI9341_BLACK, ILI9341_RED);
		HAL_Delay(1000);
		bad_end_story();
	}

	uint32_t time_elapsed = 0;
	uint8_t current_step = 0;
	touche_TTP=0;
	char time_left[50];

	while(time_elapsed < 60000){ //Epreuve dure 1 min
		ILI9341_WriteString(10, 200, "Attention ! Respecte bien la sequence !", Font_11x18, ILI9341_RED, ILI9341_BLACK);
		//PENSER AU RESET !

		//On demande au joueur de coder une séquence MORSE :
		//sprintf(instructions, "[%d]  [%d]  [%d]", code_afficher[0]%2, code_afficher[1]%2, code_afficher[2]%2);
		//ILI9341_WriteString(50, 90, instructions, Font_16x26, ILI9341_BLACK, ILI9341_GREEN);
		time_elapsed = HAL_GetTick()- debut_sequence;

		sprintf(instructions, "CODE: %d %d %d %d %d %d",
		            code_afficher[0]%2, code_afficher[1]%2, code_afficher[2]%2,
		            code_afficher[3]%2, code_afficher[4]%2, code_afficher[5]%2);
		ILI9341_WriteString(20, 130, instructions, Font_11x18, ILI9341_CYAN, ILI9341_BLACK);

		    // --- Vérification de l'appui ---
		if (touche_TTP != 0) {
			uint8_t appui = touche_TTP;
		    touche_TTP = 0; // Consommation du flag

		    // On définit la règle : Chiffre PAIR (0) -> TTP1, Chiffre IMPAIR (1) -> TTP2
		    uint8_t attendu = (code_afficher[current_step] % 2 == 0) ? 1 : 2;

		    if (appui == attendu) {
		        current_step++;
		        ILI9341_FillRectangle(0, 160, 320, 10, ILI9341_BLACK);
		        ILI9341_WriteString(10, 160, "BIEN JOUE !", Font_7x10, ILI9341_GREEN, ILI9341_BLACK);
		        HAL_Delay(500); // Petit confort de jeu
		        ILI9341_FillRectangle(0, 160, 320, 10, ILI9341_BLACK);

		    } else {
		        current_step = 0; // RESET total de la progression
		        ILI9341_FillRectangle(0, 160, 320, 10, ILI9341_BLACK);
		        ILI9341_WriteString(10, 160, "RATE ! RECOMMENCE !", Font_7x10, ILI9341_RED, ILI9341_BLACK);
		        HAL_Delay(500);
		        ILI9341_FillRectangle(0, 160, 320, 10, ILI9341_BLACK);

		    }
		 }
		if(current_step > CODE_SIZE-1){
			good_end_story();
			return;
		}
		sprintf(time_left, "Time remaining : %ld s", (60000-time_elapsed)/1000 );
		ILI9341_WriteString(10, 75, time_left , Font_7x10, ILI9341_CYAN, ILI9341_BLACK);

	}
	bad_end_story();

}

void bad_end_story(){
	 ILI9341_FillScreen(ILI9341_BLACK);
	 ILI9341_WriteString(30, 90, "Bravo, tu as fait explose l'antidote ! C'est termine ! TU AS PERDU !!!", Font_11x18, ILI9341_RED, ILI9341_BLACK);

}

void good_end_story(){
	 ILI9341_FillScreen(ILI9341_GREEN);
	 ILI9341_WriteString(30, 90, "Bravo, tu as l'EPREUVE 1 !", Font_11x18, ILI9341_GREEN, ILI9341_BLACK);

}

