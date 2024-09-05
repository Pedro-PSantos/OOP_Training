#include "Jogador.h"

Jogador::Jogador() {
	numero=0;
	expulso=false;
	titular=false;
	checkplay=false;
	pontos=0;
}

Jogador::~Jogador() {
	// TODO Auto-generated destructor stub
}


void Jogador::ShowPlayer(int id){

	cout << "Nome: " << nome
		 << "    Número: " << numero
		 << "    Posição: " << posicao;
	if(id==1)
		cout << "    Golos: ";
	else
		cout << "    Pontos: ";

	cout << pontos << endl;
}
