# StracciaCamicia

Straccia Camicia è un gioco di carte determistico a due giocatori.
A ogni stato iniziale corrisponde uno e un solo possibile risultato.
Il mazzo da gioco è formato da 40 carte e presenta due tipi di carte:
 -1,2,3 che sono le carti vincenti
 -tutte le altre, che sono le carte neutre
Il gioco inizia distribuendo 20 carte a giocatore e uno dei due scarta la prima carta del suo 
mazzo. Il gioco si basa su due semplici regole:
 -se la carta è neutra tocca all'altro giocatore scartarne una sulla stessa pila
 -se la carta è una vincente dal valore n l'altro giocatore deve scartare n carte una alla volta.
  Alla prima carta vincente scartata tocca all'altro giocatore seguendo questa stessa regola. Se tutte
  le n carte sono neutre vince il turno il giocatore che per ultimo ha scartato una carta vincente 
  e inserisce la pila di scarti in fondo al suo mazzetto.
Vince chi ottiene tutte le quaranta carte

Il programma cicla simulando in C++ partite di Straccia Camicia. Ogni partita inizia con un mazzo mescolato casualmente.

