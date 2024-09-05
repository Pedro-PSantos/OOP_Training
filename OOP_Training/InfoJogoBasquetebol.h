#ifndef INFOJOGOBASQUETEBOL_H_
#define INFOJOGOBASQUETEBOL_H_

#include "InfoJogo.h"

class InfoJogoBasquetebol: public InfoJogo {

private:

	int pontosC;
	int pontosV;
	vector<string> pontos;

public:

	InfoJogoBasquetebol();
	virtual ~InfoJogoBasquetebol();

	vector<Jogador>::iterator itJ;
	vector<Jogador>::iterator itJ2;
	vector<string>::iterator itS;

	bool checkTempo(string,int);

	int getpontosC(){return pontosC;};
	int getpontosV(){return pontosV;};
	vector<string> getPontos(){return pontos;};

	void InserirPontos(string,int);
	void InserirSubs(string);
	void InserirExps(string);
	void addJogadores();
	void addPonto(string ponto){pontos.push_back(ponto);};
	void incpontosC(int ponto){pontosC+=ponto;};
	void incpontosV(int ponto){pontosV+=ponto;};
	void setpontosC(int pontos){pontosC=pontos;};
	void setpontosV(int pontos){pontosV=pontos;};
	bool checkPontos(string,int&);

	bool setvencedor();
	void setvencedor(string Winner){vencedor=Winner;};

};

#endif /* INFOJOGOBASQUETEBOL_H_ */
