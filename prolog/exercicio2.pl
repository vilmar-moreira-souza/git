masculino(joao).
masculino(pedro).
masculino(antonio).
feminino(ana).
feminino(maria).
feminino(luiza).
feminino(sofia).
feminino(clara).
pai_de(joao,pedro).
pai_de(joao,maria).
pai_de(pedro,sofia).
pai_de(antonio,clara).
mae_de(ana,pedro).
mae_de(ana,maria).
mae_de(maria,clara).
mae_de(luiza,sofia).
%
tio(pedro,clara).
tia(maria,sofia).
%
avo(X,Y) :- pai_de(X,Z), pai_de(Z,Y).
avoh(X,Y) :- mae_de(X,Z) , mae_de(Z,Y).
irmao(X,Y) :- masculino(X),
              (pai_de(Z,X),pai_de(Z,Y));
              (mae_de(W,X),mae_de(W,Y)).
irma(X,Y) :- feminino(X),
              (pai_de(Z,X),pai_de(Z,Y));
              (mae_de(W,X),mae_de(W,Y)).



