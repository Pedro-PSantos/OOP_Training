#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <fstream>
#include <string>
#include <limits>
#include <regex>
#include "InfoJogoBasquetebol.h"
#include "InfoJogoFutebol.h"


class interface {
public:
	interface();
	virtual ~interface();

void startInterface();

void BoasVindas();
void Menu();
void MenuInserir();
void MenuVer();
void InserirFutebol(InfoJogoFutebol&);
void InserirBasquetebol(InfoJogoBasquetebol&);
void VerEquipa();
void InserirDadosJogador(int,int,Jogador&);
void InserirPosFut(Jogador&);
void InserirPosBas(Jogador&);
void MenuVerJogo();
void MenuVerDados(int);

int ShowStatsF(InfoJogoFutebol);
int ShowStatsB(InfoJogoBasquetebol);
bool SaveGameF(InfoJogoFutebol&);
bool SaveGameB(InfoJogoBasquetebol&);
bool ReadGameF(InfoJogoFutebol&);
bool ReadGameB(InfoJogoBasquetebol&);

void writefile();
void readfile();

Jogador InserirJogador(int,char,int);

int Input();

};

#endif /* INTERFACE_H_ */
