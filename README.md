# Race-Conditions

Set of race conditions based attacks (TOCTTOU)




        file_1 => bait file (the file we are deceiving the system with)

        file_2 => target file (the file we actually want to open)



To compile:

        gcc attack.c -o attack
        
        gcc victim.c -o victim

To run: 

        ./attack file_1 file_2
        
        ./victim file_1 

Pay attention: probably it will give some tries before actually working due to the timing of both the process attack and victimeng.

Improving soon...
