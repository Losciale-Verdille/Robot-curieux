### Séance du 13 Décembre 2018 :
Nous avons commencé par l'étude du fonctionnement du micro et de l'amplification du signal obtenu car c'est un élément essentiel dans la réalisation de notre projet. 3 circuits ont été réalisés dans ce but: un filtre passe-haut, amplification avec l'AOP et amplification avec un transistor NPN.

Dans le premier cas, l'amplification était très légère. Nous avons donc cherché des exemples de circuits utilisant notamment des AOP et des transistors espérant de meilleurs résultats. Dans le cas de l'AOP, l'amplification n'était pas satisfaisante, les branchements complexes et gourmand en composant alors qu'il nous faudra amplifier plusieurs micros et donc reproduire ce circuit 4 à 5 fois. Dans le cas du transistor NPN, le résultat était encore une fois pas complètement satisfaisant.

En deuxième partie de séance, nous avons récupéré deux moteurs avec deux roues d'un ancien projet. Nous les avons branchés et testés. A faible tension on observe déjà un léger écart dans la rotation des roues, il nous faudra peut-être rectifier ce point.
En fin de séance, nous avons créer un Github  afin d'y déposer le contenu relatif à ce projet.

### Séance du 20 Décembre 2018 :

Entre les deux séances, la répartition des tâches a été faite (voir Taches.xlsx), j'ai donc continué l'étude du micro et de son amplification tandis que Vivian réalisait les tests moteurs et quelques petits bricolages pour commencer à former la structure de notre futur robot.

Lors de mon étude, j'ai récupéré le montage ayant le mieux fonctionné la semaine précédente. J'ai effectué des comparaisons notamment avec différentes valeurs de capacité.

Il a ensuite fallu réflechir à améliorer la réception du son par le micro car il fonctionnait seuleument lorsque l'on soufflait dessus à une distance de 1 à 5cm... J'ai donc fabriqué un petit tube en papier du diamètre du micro et d'une longueur d'une vingtaine de centimètres. Grâce à ce dispositif, nous avons enfin réussi à obtenir les premières détections de la voix en restant tout de même à moins d'une dizaine de centimètres du tube!

Je vais donc essayer de travailler la forme de ce tube pour essayer d'obtenir plus de raisonnance et ainsi amplifier physiquement le son avant qu'il arrive au micro pour être amplifié électroniquement.

### Séance du 10 Janvier 2019 :

Cette séance avait pour but d'améliorer la distance de détection du son afin qu'elle atteigne environ 1 mètre. Depuis la séance précédente, M. Masson (qui encadre les projets) nous a conseillé d'utiliser l'amplificateur opérationnel (AOP) TL072 pour notre amplification.

J'ai tout d'abord vérifié que le micro était capable de détecter la distance souhaitée avec l'oscilloscope car la variation de tension était très faible et illisible sur le traceur série de l'arduino. J'ai ensuite réalisé un amplificateur non inverseur en suivant le schéma [page 26 de ce cours](http://users.polytech.unice.fr/~pmasson/Enseignement/AOP%20-%20Projection%20-%20MASSON.pdf). Malheureusement, je n'ai pas réussi à le régler de manière optimale.

J'ai pu ensuite récupérer un montage avec l'AOP réalisé par M. Masson avec lequel nous avons pu réaliser quelques petits essais en fin de séances. Les premiers résultats sont que ce montage permet de très légèrement détecter la voix à une cinquaine de centimètres et on a réussi à détecter un clapement de main à environ 1 mètre. Un cône doit être installé autour du micro afin que ce clapement soit détecté lorsque qu'on est orienté vers celui-ci uniquement, ce qui n'est pas encore le cas actuellement.

Durant la séance, j'ai également aidé mon binôme à diagnostiquer la source du problème de l'alimentation des moteurs avec le boitier de piles en m'appuyant sur le montage similaire d'un petit robot roulant réalisé en TD.

#### Entre les séances : 
Réalisation d'un prototype de cône augmentant la portée du micro (environ 2-3 mètres) lorsque on tape dans les mains.

### Séance du 17 Janvier 2019 :

Les essais du prototype de cône ont mis en évidence une faible directivité, c'est-à-dire que le micro à un champ d'écoute trop grand. Or, nous souhaitons un micro très directif pour localiser la source d'un son. Nous avons reçu des ressources au sujet de micros paraboliques utilisant la réflexion du son sur une parabole vers le micro. Mon binôme a dupliqué le circuit d'amplification avec un autre micro pour comparer la parabole avec le cône. Cette solution n'a pas fonctionné car nous n'avons pas réussi à trouver le point de focale de la demi-sphère nous servant de parabole.

J'ai continué à améiorer les réglages du prototype de cône en mesurant plus précisement la valeur moyenne, les variations de tension dûes au bruit ambiant et les variations lorsqu'on tape des mains à moyenne distance (~2-3m) ou qu'on parle à une faible distance (<1m) du micro.

**Présentation orale du projet** au deux tiers de la séance.

Grâce à la précédente duplication, j'ai voulu comparer les mesures de 2 micros orientés dans des directions opposées pour estimer la différence de mesure qu'on soit de face ou bien à l'opposé. J'ai bien constaté une petite différence mais il est à noter qu'un seul des deux micros été équipé du prototype.

#### Entre les séances :
Le prototype de cône (qui est en fait un cylindre sans ses bases) ayant donné satisfaction, j'en ai équipé les 4 micros dont nous disposons. ![cône ampli](https://github.com/Losciale-Verdille/Robot-curieux/blob/master/Rapports%20seances/Images/20190203_151233%5B1%5D.jpg)
Il a également fallu dupliquer le circuit d'amplification pour chaque micro : ![Amplification AOP](https://github.com/Losciale-Verdille/Robot-curieux/blob/master/Rapports%20seances/Images/20190120_184130%5B1%5D.jpg)
(emplacement schema elec)

Le micro se branche sur la ligne 50 côté gauche de la plaque (entre la résistance et le condensateur) et le signal amplifié est mesuré ligne 55 côté droit de la plaque.

### Séance du 4 Février 2019 :

Remplacement des condensateurs des circuits d'amplification. Prise de mesure sur le robot pour y intégrer les micros.

J'ai ensuite dû mesurer manuellement les valeurs de fonctionnement de chaque micro et circuit d'amplification associé (la mesure automatique ne fonctionnant pas correctement, j'essaierais de toujours associer les mêmes micros aux mêmes circuits d'amplification pour ne pas avoir à refaire les mesures à chaque fois).

Cela m'a permis de réaliser le code comparant les sources du son en disposant les micros vers l'avant, vers l'arrière, vers la droite et vers la gauche. Les tests ont montrés que le code fonctionnait mais il y a toujours un léger problème au niveau de la directivité des micros. En effet, à moyenne et longue distance (>2m), les micros opposés ont tendance à capter aussi bien le son que le micro. correctement orienté.
```javascript
int var = 50;
int micro;

// Micro & AOP 1
int gap1;
int m1 = 1;
int amp1 = 503;

// Micro & AOP 2
int gap2;
int m2 = 2;
int amp2 = 505;

//Micro & AOP 3
int gap3;
int m3 = 3;
int amp3 = 510;

//Micro & AOP 4
int gap4;
int m4 = 4;
int amp4 = 508;

void setup() {
  Serial.begin(9600);
}

int Compare(int in1, int in2, int in3, int in4) {
  int mic = 1;
  int vmax = in1;
  if (in2>vmax) {
    mic = 2;
    vmax = in2;
  }
  if (in3>vmax) {
    mic = 3;
    vmax = in3;
  }
  if (in4>vmax) {
    mic = 4;
    vmax = in4;
  }
  return mic;
}

void loop() {
  gap1 = abs(amp1-analogRead(m1));
  gap2 = abs(amp2-analogRead(m2));
  gap3 = abs(amp3-analogRead(m3));
  gap4 = abs(amp4-analogRead(m4));
  if ((gap1 >= var) || (gap2 >= var) || (gap3 >= var) || (gap4 >= var)){
    micro = Compare(gap1,gap2,gap3,gap4);
    Serial.println(micro);
  }
  delay(50);
}
```

### Séance du 11 Février 2019 :
Essais de détection du son avec la boîte contenant les 4 micros orientés dans 4 directions ([aperçu](https://github.com/Losciale-Verdille/Robot-curieux/blob/master/Rapports%20seances/Images/20190210_165025.mp4)). La détection du son sur les micros positionnés sur la longueur de la boîte est bonne et est à améliorer sur ceux positionnés sur la larqeur de la boîte. Suite à ces essais, une version améliorée du code de détection a été faite durant la séance.

Réflexions sur le positionnement des différents élements sur le robot avec Vivian (micros, boitier de piles, carte arduino, circuit amplificateur/plaque). Dans une économie de place et de poids, les circuits d'amplification ont été transférés vers une plus petite plaque.

### Séance du 25 Février 2019 :
Nous avons tout d'abord dû vérifier que tous les modules qui avaient été assemblés fonctionnaient correctement ensemble (Micros + Bluetooth + Moteurs). Evidemment, nous avons rencontré plusieurs problèmes :

**Problème n°1 :** Le signal du son mesuré par les micros comportait des pics parasites qui nuisaient à la bonne détection du son. Nous pensons que ces perturbations étaient dûes au branchement du module Bluetooth sur le 5V et la masse de la plaque des circuits d'amplification des micros. Le problème a été résolu en ajoutant un condensateur entre le 5V et la masse de la plaque.

**Problème n°2 :** La communication avec le module Bluetooth ne fonctionnait plus.

**Problème n°3 :** L'alimentation par le boîtier de piles ne fonctionnait plus. Après avoir vérifié le fonctionnement des moteurs (branchements OK, avec l'alimentation 5V de la carte) et vérifier l'ensemble des piles du boîtier, le problème a finalement été localisé sur le fil de la masse qui était défectueux. Nous avons donc eu un nouveau boîtier de piles.

Nous avons conclu la séance sur l'essai de l'alimentation du robot complet.

### Séance du 4 Mars 2019 :

La détection du son fonctionnant à la séance précédente, nous avons d'abord dû vérifier qu'elle fonctionnait toujours à présent que le robot et le programme étaient complet (le code de détection a été ajouté par Vivian dans le code des moteurs entre les séances). Après une longue et minutieuse vérifiation des branchements (environ 35 min), nous avons pu complétement tester notre robot pour la 1ère fois. Nous avons réalisé les observations suivantes : (1) le robot se met en marche seuleument à partir du moment où le micro avant détecte un son (nous souhaitions une mise en marche dès qu'un des quatre micros était sollicité); (2) en marche avant le robot ne suit pas tout le temps une ligne droite; (3) les roues manquent parfois d'adhérence lorsque le robot doit tourner à droite ou à gauche.

* (1) : Résolu par correction du programme.
* (2) : Nous pensions tout d'abord à un problème de répartition des puissances entre roues droite et gauche. En effet, la roue gauche ayant plus de puissance que celle de droite, il a fallu la brider au niveau du programme (ne pas la mettre à 100% de puissance). Au fil des réajustements à taton, nous nous sommes aperçu que le problème venait de la roue libre avant (3 ème appui du robot en plus des roues motorisés). Lors de changement de direction, probablement dû à une vitesse insuffisante ou un manque d'adhérence, la roue ne s'oriente pas tout à fait dans la direction du mouvement du robot.
* (3) : Plutôt que d'utiliser une roue motrice pour tourner, nous devrions utiliser les deux roues dans des sens opposés.

### Séance du 11 Mars 2019 :
Présentation du projet

Démonstration du mode automatique : https://youtu.be/hMzgcauvrmQ
