#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <iostream>

using std::cout;
using std::endl;


using std::string;

class Jogador {

private:
	string nome;
	int numero;
	string posicao;
	int pontos;
	bool expulso;//verifica se o jogar foi expulso
	bool titular; //verifica se o jogador é titular
	bool checkplay;//verifica se o jogador está em campo quando marca golo ou é substituido


public:
	Jogador();
	~Jogador();

	void setnome(string str){nome=str;};
	void setnome(char c){nome=c;};
	void setnumero(int n){numero=n;};
	void setposicao(string str){posicao=str;};
	void setexpulso(){expulso=true;};
	void settitular(){titular=true;};
	void setcheckplay(){checkplay=true;};
	void addpontos(int P){pontos+=P;};
	void addgolo(){pontos++;};
	void setScore(int score){pontos=score;};

	string getnome(){return nome;};
	int getnumero(){return numero;};
	string getposicao(){return posicao;};
	int getpontos(){return pontos;};
	bool getexpulso(){return expulso;};
	bool gettitutlar(){return expulso;};
	bool getsubstituido(){return expulso;};

	void ShowPlayer(int);
	void mostrajogador();
};

#endif /* JOGADOR_H_ */
