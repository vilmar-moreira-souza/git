homen(joao).
homen(pedro).
homen(yuri).
homen(andre).

mulher(maria).
mulher(ana).
mulher(clara).
mulher(lia).
mulher(debora).

irmaos(pedro,ana).
irmaos(yuri,lia).
irmaos(joao,maria).
irmaos(andre,ana).
irmaos(debora,pedro).


progenitor(joao,ana).
progenitor(joao,pedro).
progenitor(maria,ana).
progenitor(andre,clara).
progenitor(ana,clara).
progenitor(pedro,yuri).
progenitor(pedro,lia).
progenitor(debora,lia).
progenitor(debora,yuri).

mae(X,Y):- progenitor(X,Y),mulher(X).
pai(X,Y):- progenitor(X,Y),homen(X).

filhos(X,Y):- progenitor(X,Y).
filho(X,Y):- progenitor(X,Y),homen(X).
filha(X,Y):- progenitor(X,Y),mulher(X).

avo(X,Y):- progenitor(X,Z),progenitor(Z,Y),homen(X).
avoh(X,Y):- progenitor(X,Z),progenitor(Z,Y),mulher(X).

tio(X,Y):- progenitor(W,X),progenitor(W,Z),progenitor(Z,Y),homen(X).
tia(X,Y) :- filhos(X,W),filhos(Z,W),progenitor(Z,Y),mulher(X).







