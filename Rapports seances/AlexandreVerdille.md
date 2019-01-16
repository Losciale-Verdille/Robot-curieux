Séance du 13 Décembre 2018:

Nous avons commencé par l'étude du fonctionnement du micro et de l'amplification du signal obtenu car c'est un élément essentiel dans la réalisation de notre projet. 3 circuits ont été réalisés dans ce but: un filtre passe-haut, amplification avec l'AOP et amplification avec un transistor NPN.
Dans le premier cas, l'amplification était très légère. Nous avons donc chercher des exemples de circuits utilisant notamment des AOP et des transistors espérant de meilleurs résultats. Dans le cas de l'AOP, l'amplification n'était pas satisfaisante, les branchements complexes et gourmand en composant alors qu'il nous faudra amplifier plusieurs micros et donc reproduire ce circuit 4 à 5 fois. Dans le cas du transistor NPN, le résultat était encore une fois pas complètement satisfaisant.
En deuxième partie de séance, nous avons récupéré deux moteurs avec deux roues d'un ancien projet. Nous les avons branchés et testés. A faible tension on observe déjà un léger écart dans la rotation des roues, il nous faudra peut-être rectifier ce point.
En fin de séance, nous avons créer un Github  afin d'y déposer le contenu relatif à ce projet.



Séance du 20 Décembre 2018:

Entre les deux séances, la répartition des tâches a été faite (voir Taches.xlsx), j'ai donc continué l'étude du micro et de son amplification tandis que Vivian réalisait les tests moteurs et quelques petits bricolages pour commencer à former la structure de notre futur robot.
Lors de mon étude, j'ai récupérer le montage ayant le mieux fonctionné la semaine précédente. J'ai effectué des comparaisons notamment avec différentes valeurs de capacité.
Il a ensuite fallu réflechir à améliorer la réception du son par le micro car il fonctionnait seuleument lorsque l'on soufflait dessus à une distance de 1 à 5cm... J'ai donc fabriqué un petit tube en papier du diamètre du micro et d'une longueur d'une vingtaine de centimètres. Grâce à ce dispositif, nous avons enfin réussi à obtenir les premières détections de la voix en restant tout de même à moins d'une dizaine de centimètres du tube!
Je vais donc essayer de travailler la forme de ce tube pour essayer d'obtenir plus de raisonnance et ainsi amplifier physiquement le son avant qu'il arrive au micro pour être amplifié électroniquement.



Séance du 10 Janvier 2019:

Cette séance avait pour but d'améliorer la distance de détection du son afin qu'elle atteigne environ 1 mètre. Depuis la séance précédente, M. Masson (qui encadre les projets) nous a conseillé d'utiliser l'amplificateur opérationnel (AOP) TL072 pour notre amplification.
J'ai tout d'abord vérifié que le micro était capable de détecter la distance souhaitée avec l'oscilloscope car la variation de tension était très faible et illisible sur le traceur série de l'arduino. J'ai ensuite réalisé un amplifcateur non inverseur en suivant le schéma page 26 de ce cours : http://users.polytech.unice.fr/~pmasson/Enseignement/AOP%20-%20Projection%20-%20MASSON.pdf . Malheureusement, je n'ai pas réussi à le régler de manière optimale.
J'ai pu ensuite récupérer un montage avec l'AOP réalisé par M. Masson avec lequel nous avons pu réaliser quelques petits essais en fin de séances. Les premiers résultats sont que ce montage permet de très légèrement détecter la voix à une cinquaine de centimètres et on a réussi à détecter un clapement de main à environ 1 mètre. Un cône doit être installé autour du micro afin que ce clapement soit détecté lorsque qu'on est orienté vers celui-ci, ce qui n'est pas encore le cas actuellement.
Durant la séance, j'ai également aidé mon binôme à diagnostiquer la source du problème de l'alimentation des moteurs avec le boitier de piles en m'appuyant sur le montage similaire d'un petit robot roulant réalisé en TD.

Entre les séances : Réalisation d'un prototype de cône augmentant la portée du micro (environ 2-3 mètres) lorsque on tape dans les mains.
