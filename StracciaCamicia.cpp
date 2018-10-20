#include<iostream>
#include<vector>
#include<assert.h>
#include<cstdlib> 
#include<algorithm>

using namespace std;

int myrandom(int i) { return rand() % i; }

void stampa(vector<int> aux) {	//Per stampare il mazzo

	for (int i = 0; i < aux.size(); i++) {
		cout << aux[i] << ' ';
	}
	cout << endl;
}

int pop_front(vector<int>& vec){//Toglie il primo elemento del vettore con controlli
	int x = vec[0];
	assert(!vec.empty() && "E' vuoto"); //Termina il programma se l'argomento è falso
	vec.erase(vec.begin());
	return x;
}

void trasla(vector<int>& vet, int k) {

	for (int i = 0; i < k; i++)
		pop_front(vet);
}

void travasa(vector<int>&vet, vector<int>& p) { //Elementi di p travasati in coda vet

	int dim = p.size(); //Variabile d'appoggio perche varia durante l'esecuzione
	for (int i = 0; i < dim ; i++) {
		vet.push_back(p[0]);
		 pop_front(p);
	}

}

int check(int k, vector<int>& vet, vector<int>& p, int& ip) {

	if (vet.size() < k)
		return 0;

	for (int i = 0; i < k; i++) {
		ip++;
		p.push_back(vet[0]);
		int x = pop_front(vet); 
		if (x != 0)  
			return x; 
	}
	return 0;
}

int main() {

	char stop;
	int contaPartite = 0;

	while(true){
		contaPartite++;
		int turno = 0; // 0 se gioca il giocare iniziale, 1 altrimenti
		int contaTurni = 0;

		vector<int> v{ 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 0 };

		//Mescolamento del mazzo
		random_shuffle(v.begin(), v.end(), myrandom);

		vector<int> counter{ 0,0 };  //Contatore di carte in pila per ogni mazzetto
		vector<vector<int>> m(2, vector<int>(20));
		vector<int> pila;
		//PER TEST SPECIFICI (eventualmente commentare il for seguente
		//m[0] = { 0,1,0,0,1,0,0,0,0,0,2,1,0,3,0,0,0,0,0,0 };
		//m[1] = { 3,2,0,2,1,0,0,0,0,3,2,0,0,0,0,0,3,0,0,0 };

		for (int i = 0; i < 20; i++) {
			m[0][i] = v[i];
			m[1][i] = v[i + 20];
		}

		// Per visualizzare (commentarlo quando si vuole velocizzare)
		if (contaPartite % 1000 == 0) {
			stampa(m[0]);
			stampa(m[1]);
		}

		// Core Game
		while (!m[0].empty() && !m[1].empty()) {

			int aux = 0;
			int c = counter[turno];
			int scarto;

			scarto = pop_front(m[turno]);
			pila.push_back(scarto);
			c++;
			if (scarto != 0) {

				turno = !turno; //Alternativamente si poteva usare turno = turno xor 1
				bool fine = false;
				while (!fine) {

					aux = check(scarto, m[turno], pila, counter[turno]);
					if (aux == 0) { //Vittoria dell'altro
						travasa(m[!turno], pila);
						counter[0] = 0;
						counter[1] = 0;
						contaTurni++;
						if (contaTurni == 10000) {
							cout << "Stato iniziale sospetto" << endl;
							cin >> stop;
						}
						fine = true;
					}
					else {
						scarto = aux;
						turno = !turno;
					}
				}
			}
			turno = !turno; //Ricomincia l'altro
		}
		if (contaPartite % 1000 == 0) {
			cout << "PARTITA NUMERO : " << contaPartite << " Vince giocatore " 
				 << turno << " in " << contaTurni << " turni!" << endl;
		}
	}
	cin >> stop;
}
