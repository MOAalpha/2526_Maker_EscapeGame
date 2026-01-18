# **<u>EscapeGame</u>**

Ceci est un projet personnel. L'objectif est de créer une boîte avec différentes énigmes, en mettant en oeuvre différentes compétences apprises, entre la Conception Assistée par Ordinateur (CAO) jusqu'à la fabrication d'un PCB.

## Synopsis

*Une épidémie ravage le monde. Personne n'est à l'abri. Environ 10 000 000 de personnes succombent chaque seconde. Le virus possède une forte volatilité et tue en quelques jours. Le docteur Frank MaBoule, après avoir utilisé sa fille comme cobaye,  a créé un remède. Sa fille ayant succombé, il décida de cacher son remède.Sauriez-vous être le héros qui sauvera ~~le monde~~ votre peau ? Voici les épreuves qui vous attendent :*

### 1. FIND A CODE 
Pour ouvrir la première porte, il faut résoudre une énigme très classique consistant à reconstituer une séquence sur un damier de 4x4 symbolisé par 16 écrans.

### 2. DRESS or LESS 

Pour la deuxième porte, l'idée est de vêtir 3 personnages avec le bon chapeau, pull et pentalon, à l'aide de capteurs RFID. Pour cela, une description incomplète sera fournie à travers l'écran principale.

### 3. CHOOSE THE HERO

Parmi les 3 personnages, un seul cache le remède. Vous aurez leur témoignage pour savoir qui possède le remède.

## Matériel (liste actuelle non exhaustive):

> - 1 écran 15cmx10cm tactile (moniteur principale) [de ce type-là](https://www.amazon.fr/Tactile-Fabricant-Bricolage-Internet-%C3%A9lectrique/dp/B0BWNQKWJR)
> - 16 écrans de 4x4 ?
> - Actionneurs pour portes ? 
> - PLA pour les personnages
> - tissu pour les vêtements
> - Capteurs RFID miniatures ?
> - *A suivre...*

## Planning prévisionnel 



| Séance                  | Action prévue |
|-------------------------|---------------|
| Lundi 16 février 2026   |  Conception des énigmes + Début schématique PCB           |
| Jeudi 19 février 2026   |     Choix des composants(Ecrans, Rasperry Pi/STM) + Suite PCB        |
| Lundi 9 mars 2026       | Début conception mécanique (Plan de la boite, portes, personnages...)              |
| Jeudi 12 mars 2026      |      Découpe laser pour la boîte et premières impressions de pièces         |
| Lundi 16 mars 2026      |    Test PCB        |
| Jeudi 19 mars 2026      |   Setup capteurs RFID + Ecrans principales              |
| Lundi 23 mars 2026      |  Améliorations + Correction             |
| Jeudi 26 mars 2026      |  Code sur STM/Rasberry Pi             |
| Lundi 30 mars 2026      |    Tests / A voir            |
| Jeudi 2 avril 2026      |    A voir            |
| Jeudi 9 avril 2026      |  Possibilité de rajouter des énigmes si tout fonctionne. / Création chatbot pour l'énigme des personnages si le temps le permet.            |
| Lundi 13 avril 2026     |   A voir            |


GANTT : (*IA MADE*)

gantt
    title Planning du projet (février – avril 2026)
    dateFormat  YYYY-MM-DD
    axisFormat  %d/%m

    section Conception
    Conception des énigmes + schéma PCB         :a1, 2026-02-16, 3d
    Choix composants + suite PCB                :a2, after a1, 3d

    section Mécanique
    Conception mécanique (boîte, portes, persos):b1, 2026-03-09, 4d
    Découpe laser + impressions pièces          :b2, after b1, 3d

    section Électronique
    Test PCB                                    :c1, after a2, 2d
    Setup capteurs RFID + écrans principaux     :c2, after c1, 3d

    section Développement
    Améliorations + corrections                 :d1, after c2, 3d
    Code sur STM / Raspberry Pi                 :d2, after d1, 4d

    section Tests & ajustements
    Tests généraux                              :e1, after d2, 3d
    Ajustements techniques                     :e2, after e1, 3d

    section Extensions (optionnel)
    Ajout d’énigmes / chatbot personnages       :f1, after e2, 4d

    section Final
    Finalisation & préparation soutenance       :g1, after f1, 2d
