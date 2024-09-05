#ifndef INFOJOGO_H_
#define INFOJOGO_H_

#include <iostream>
#include <vector>
#include "Jogador.h"
#include <limits>
#include <regex>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


class InfoJogo {

private:

	string modalidade;
	string equipa1;
	string equipa2;
	vector<string> substituicoes;
	vector<string> expulsoes;

protected:

	vector<Jogador> JogEq1;
	vector<Jogador> JogEq2;
	string vencedor;

public:

	InfoJogo();
	virtual ~InfoJogo();

	void setMod(string mod){modalidade=mod;};
	void setEq1(string nome){equipa1=nome;};
	void setEq2(string nome){equipa2=nome;};
	void addJogEq1(Jogador addJog){JogEq1.push_back(addJog);};
	void addJogEq2(Jogador addJog){JogEq2.push_back(addJog);};
	void addSubs(string subs){substituicoes.push_back(subs);};
	void addExp(string exp){expulsoes.push_back(exp);};

	string getvencedor(){return vencedor;};
	string getMod(){return modalidade;};
	string getEq1(){return equipa1;};
	string getEq2(){return equipa2;};
	vector<Jogador> getJogEq1(){return JogEq1;};
	vector<Jogador> getJogEq2(){return JogEq2;};
	vector<string> getSubs(){return substituicoes;};
	vector<string> getExps(){return expulsoes;};

};

#endif /* INFOJOGO_H_ */
