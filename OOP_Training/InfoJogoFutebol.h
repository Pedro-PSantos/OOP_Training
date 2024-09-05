#ifndef INFOJOGOFUTEBOL_H_
#define INFOJOGOFUTEBOL_H_

#include "InfoJogo.h"

class InfoJogoFutebol: public InfoJogo {

private:

	int golosC;
	int golosV;
	vector<string> golos;

public:

	InfoJogoFutebol();
	virtual ~InfoJogoFutebol();

	vector<Jogador>::iterator itJ;
	vector<Jogador>::iterator itJ2;
	vector<string>::iterator itS;

	int getGolosC(){return golosC;};
	int getGolosV(){return golosV;};
	vector<string> getGolos(){return golos;};

	void setvencedor();
	void setvencedor(string Winner){vencedor=Winner;};
	void incgolosC(){golosC++;};
	void incgolosV(){golosV++;};
	void setGolosC(int golos){golosC=golos;};
	void setGolosV(int golos){golosV=golos;};

	bool checkPosition(string);
	bool checkMinuto(string);

	void addJogadores();
	void InserirJogador(int,int,Jogador&);
	void showplayer();
	void InserirSubsExp(string);
	void InserirGolos(string,int);
	void addGolo(string golo){golos.push_back(golo);};
};

#endif /* INFOJOGOFUTEBOL_H_ */
