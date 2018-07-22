# wordgame
Word Game Using Data Structures.

1)Aim : Build a "vocabulary game" where the player is asked to connect two words chosen by the computer 

2) Constraints : Project can be in ay language except python. Can be in Android app/web app or html/css could be used.

3) Files Uploaded : 
 - game.c -> Contains the code in C language 
 - wordsEn.h -> Has the list of all the meaningful words that can be formed in the intermediate stages.
 
4) Concept : 
Edit Distance between two words (operations allowed: insert, modify, delete one letter at a time)
e.g., time -> stime -> spime -> spame -> space (edit distance = 4)

A twist: intermediate words must be valid English words 
time -> tame -> fame -> face -> pace -> space (edit distance = 5)
