
import random 
#18/01/2017
#adinhe o numero 
print('jogo adivinhe o numero')
"""
#print("hello world")
#a=41
#print(a)"""

"""comentario"""
true =1
num = random.randint(1,100)
while true:
	n = int (input("digite um numero:"))
	if n> num:
		print('mais para baixo')
	elif n< num:
		print('mais pra cima')
	else:
		print('acertou')
		break 
print('jogo finalizado')		

