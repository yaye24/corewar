# Champ Yolo for 42 Corewar by some noobs

.name "Yolo"
.comment "basic champ to end the project"

start:	sti r1, %:live, %1
		and r1, %0, r1

loop:	live %1
		fork %:destroy
		zjmp %:live

live:	live %1
		zjmp %:live

destroy:sti r1,%17,r3
		add r3,r4,r3
		xor r5,r3,r6
		
