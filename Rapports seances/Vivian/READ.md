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
![alt text](https://github.com/Losciale-Verdille/Robot-curieux/blob/master/Rapports%20seances/Vivian/49517024_2245816098990626_29802305620541440_n.jpg)



Jeudi 17 janvier:

Etant donné que pour avancer la voiture, il nous fallait impérativement des micros,dans cette sénace nous nous somme focalisé sur le micro. Alexandre a réussit a faire un micro qui detecte les clapements de main. Nous avons alors essayé différentes forme de micro afin de voir lequel était le plus réceptif. Pour cela, j'ai dupliqué le module du micro que alexandre a fait 
![alt text](https://github.com/Losciale-Verdille/Robot-curieux/blob/master/Rapports%20seances/Vivian/50023948_368657130591160_8592740781897285632_n.jpg)
(PS pour le montage, je ne voulais pas couper les pattes car nous étions pas sur que nous allions garder ce modèle, néanmoins à ne jamais faire comme nous !)
puis nous avons fait des test.
[![Clap bruit]()](https://youtu.be/oALtmsmLZ9g)


On peut voir que le module avec le carton capte beaucoup mieux que celui en forme de parabole ( qui capte presque jamais) 
Nous avons donc decidé de garder le modele avec le cube. Etant donné qu'il nous fallait 4 micros de ce type, nous sommes alors cherché le materiel afin de dupliquer cleui deja pré existant.
Ensuite j'ai réparé le cable et testé mon mode automatique. Il ne marche pas du tout comme prévu, j 'ai remarqué que le capteur de distance affiche parfois 0cm soit qu'un obstacle est devant lui alors qu'il n' y a rien, ce qui est problematique car le programme est basé sur des mesures de distances regulière.
Pour cela, je compte revoir le programme afin de minimiser le nombre de mesures.
Remarque, bien que le programme ne fonctionne pas comme je le voulais, il n'empeche que le robot ne se heurte a aucun obstacle, il va juste suivre des directions aléatoire.
Ensuite, nous avons montré l'avancement du projet à des personnes venu visiter Polytech pendant 5 min.


Lundi 4 fevrier 2019:

j'ai repris le système de mode automatique concernant le fait qu'il puisse eviter de se prendre des murs. Malheureusement, comme annoncé dans le rapport de la seance dernière, le capteur affiche certaines fois un 0. J'ai donc enlevé le 0 afin d 'avoir des bonnes mesures de distances. Cependant, j'ai constaté que le capteur de distance ne fonctionne absolument pas lorsque je branche avec le boitier de pile, et dont j'ignore completement pourquoi cela ne veut pas marcher. J'ai donc testé independamment le module et aucun problème de ce coté.
Après avoir mis un delay entre chaque mesure, le capteur fonctionne. Par contre, chose completement bizarre,le capteur n'arrive pas a detecter quand on est en dessous de 10 cm lorsque je met la voiture sur le sol.
[![Robot probleme]()](https://www.youtube.com/watch?v=Vb8J6qS2bx4)
Après plusieurs tentatives ( changement de matériel, changement du code) j'en ai eu marre et nous avons décidé d 'abandonner le système de navigation automatique; A la place, nous allons incorporer les micros sur la voitures et le robot se deplacera vers la source de bruit et se prendra un mur si il y en a un.
peut etre mettre sur le mode manuel, un bouton permettant d 'avoir la distance disponible devant soi. ( peut etre utile si on ne voit pas la voiture et que l'on veut la diriger aveuglement)


Lundi 11 fevrier 2019:
Durant cette séance , nous avons commencé à finaliser le robot, nous avons fixé les élements sur le robot et j'ai recuperé le module avec les 4 micros permettant de voir la direction du son. Il y a cependant quelque petit problème concernant la mesure du son donc il faudrait voir si on peut séparer chaque micro par des isolants sonores afin d éeviter les perturbations entre micros. J'ai eu un petit problème concernant le montage final du robot. J'ai détaché l'un des moteurs et je l'ai recollé. Cependant, c'était ecrit prise rapide et ça a pris 40 min pour coller donc ce n'est pas rapide. Conclusion, je n 'ai pas pu faire des tests avec la voiture car sinon le moteur se détachait. J'ai donc récuperé tout le matériel afin de faire les ajustement pendant les vacances.


Lundi 25 fevrier 2019:
Nous avons enfin la détection des micros qui marche plus ou moins correctement.Par détection , je veux dire de quel coté provient le son.
En effet, durant cette séance, nous avons essayé de régler le problème qu'on avait au niveau des mesures de son. Nous avions des valeurs de captures qui étaient faussé. C'est à dire que de temps en temps, nous avions un pic qui montait ou descendait alors qu'il ne devait pas.
Pour palier ce problème, il suffisait juste de mettre un condensateur au plus proche du problème.Malgré que nous avions un condensateur déja entre le 5v et la masse présent sur la carte, il a fallu en rajouter un au niveau de la sortie du micro. Grace à cela, nous n'avions plus eu de problème avec ces pics.
En voulant tester le robot avec les piles, nous avions eu un problème qui a du nous prendre 20min. Au cune tension n'était transmise du boitier de pile au robot. j'ai d'abord cru que c'était un problème de branchement sur le robot mais en voyant avec le professeur, nous avions trouvé la source du problème qui était juste le boitier de pile qui ne transmettait pas la tension.
Nous avons aussi récuperé des isolants sonores afin de voir si on peut optimiser la détection du son.
![alt text](https://github.com/Losciale-Verdille/Robot-curieux/blob/master/Rapports%20seances/Vivian/53316655_2192162897766018_6643333814338715648_n.jpg)
Nous allons aussi refaire la boite contenant les micros afin de la rendre plus solide et d'y poser le boitier de pile par la suite
![alt text](https://github.com/Losciale-Verdille/Robot-curieux/blob/master/Rapports%20seances/Vivian/52876795_699304053799449_2594654576044933120_n.jpg)


Lundi 4 mars 2019:
Durant cette dernière séance, nous avons vérifié que tout les modules et que le robot en général marchaient bien. Durant le week end, j'ai rajouté la fonction permettant au robot de se diriger vers la source de son la plus forte. Cependant, il persiste quelque problème.
Le premier étant que la portée de détection pour que le robot capte un son varie. Dans nos expérimentations, le robots ne se diriger que si on était à une distance relativement proche des micros. Ce qui est assez bizarre car durant nos precédents tests sur les micros, nous détections à une plus grande distance.
Nous avons donc vérifié tous les micros durant 45 min environ.
De plus, l'un des moteurs est extremement lent comparé à l'autre ce qui induit que pour que le robot avance à peu près droit, on à du baisser la vitesse de l'autre moteur.
Un problème ( bien que ce n'est pas vraiment un) est du au fait de l'adherence des roues. Parfois, les roues tournent dans le vide. Pour palier cela, il faudrait un poids au niveau arrière du robot afin que les roues soient beaucoup plus en contact avec le sol.
Puis sur la fin de séance, 30 minute avant la fin, nous avons commencé à faire le rapport pour la soutenance de stage.
