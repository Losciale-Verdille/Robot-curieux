Année 2019:

Travail durant les vacances:

J'ai mis en place la communication bluetooth de notre robot ce qui me permet donc de le controler avec un télephone ( voir vidéo)
[![Essai Robot]()](https://youtu.be/6meGp6HiwKE)

Y sont actuellement les fonctions basiques pour se déplacer. Malheureusement, il me manque du matériel pour continuer ce que j'avais prévu tel qu'un boitier avec des piles pour eviter que le robot soit attaché à la prise de courant et des cables pour relier les divers autres composant.
La séance du jeudi 10 janvier aura comme objectif la finition du programme pour que le robot se déplace sans heurter d'objet. Quand mon collègue aura fini avec le micro, je l'incorporerai dans le programme.












Jeudi 10 janvier:
Durant cette séance , j'ai créé le programme permettant au robot de se déplacer automatiquement, cependant le micro n'étant toujours pas opérationnel, il est impossible d'incorporer la deplacement avec le micro.
Afin de faire cela, j'ai recupéré un boitier de pile afin que le robot soit libre. Cependant, les problèmes ont commencé. 
Le premier problème était que lorsque j'alimentais la carte arduino avec le boitier de pile, il ne se passait rien, aucune commande manuelle ne focntionnait, pour cela , j'ai fait différent changement:
premierement les piles était de 1.5V et l'une d 'elle ne donnait pas une tension de 1.5V, je l'ai donc changé. 
Ensuite j'ai remarqué que dans le programme, je n'avais pas mis les moteurs à pleine puissance car lorsque je branchais avec la prise sevteur, on avait une tension de 12V alors qu'avec le boitier de pile, on en a que 6V.
Le résultat est que  je n'avais pas assez de puiisance pour démarrer les moteurs avec 6V.
L'ultime changement était le remplacement de la carte Atmel en une carte Uno afin d'alimenter la carte Uno à partir du boitier de pile.
Après cela, le problème venait de l'uitlisation du Bluetooth avec le moteur:
je me connecte  ene bluetooth, je demande au robot d'aller tout droit, il execute l'ordre et le module bluetooth s'éteint. Le problème vient soit du module soit d'autre part. Testé individuellement , les 2 marchaient coorectement. J'ai alors pensé que le problème venait de la distribution de la tension.
En effet, les moteurs sont éteint et deviennent actifs lorsque ils reçoivent un ordre. A ce moment, le courant était principalement distrtibué au moteur ce qui pourrait expliquer pourquoi le module BT s'éteint, pour cela, j'ai donc rajouter un consensateur entre le 5V de la carte et le GND.
Je commence enfin les tests, je remarque que si le poids du robot est mal réparti, une des roues n'arrive pas a rester en contact avec le sol ce qui dévie le robot, pour cela il suffit juste de bien organiser la répartition du poids.
Deux mode possible: automatique et manuel.
Cependant pour le mode automatique, j'ai mis un capteur de distance afin qu'il évite de se manger un mur. Cependant un problème survient c'est que lorsque je fais des mesures de distance, celui varie entre 0 et 100, ce qui implique que le robot se déplace bizarrement
( vidéo dispo vendredi 11)
Il devrait continuer tout droit s'il n'y a pas d'obstacle et tourner si un obstacle apparait à 30 cm de lui.

le fil permettant de relier la batterie a la carte s'est cassé, il faut le ressouder donc il n'y aura pas de vidéo.
