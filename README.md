Corewar est un jeu dans lequel les joueurs s'affrontent avec leur champion dans une arène.

Les champions sont générés en code machine (.cor) à partir de son code en language assembleur (.s) grace à l'assembleur.

L'arène est modélisée par une zone mémoire dédiée. Le vainqueur du Corewar est le dernier joueur vivant dans l'arène.

Pour générer le code machine, on utilise l'assembleur:
	./asm <nom_du_champion.s>

Pour lancer Corewar:
	./corewar <champion1.cor> <champion2.cor>
