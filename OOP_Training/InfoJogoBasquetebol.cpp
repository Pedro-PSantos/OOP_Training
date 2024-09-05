#include "InfoJogoBasquetebol.h"

InfoJogoBasquetebol::InfoJogoBasquetebol() : InfoJogo() {
	pontosC=0;
	pontosV=0;
}

InfoJogoBasquetebol::~InfoJogoBasquetebol() {
	// TODO Auto-generated destructor stub
}
bool InfoJogoBasquetebol::checkTempo(string Tempo, int id)
{
	int time=0;

	if(int(Tempo.size())>2||Tempo.empty())
	{
		return false;
	}

	for(int i=0;i<int(Tempo.size());i++)
	{
		if((Tempo[i]-48)<0||(Tempo[i]-48)>9)
		{
			return false;
		}
	}

	time = stoi(Tempo);

	if(id==1)
	{
		if(time < 0 || time > 40)
		{
			return false;
		}
	}
	else
	{
		if(time < 0 || time >= 60)
		{
			return false;
		}
	}


	return true;
}

bool InfoJogoBasquetebol::checkPontos(string Pontos,int &pontos)
{
	pontos=0;

	if(int(Pontos.size())>2||Pontos.empty())
	{
		return false;
	}

	for(int i=0;i<int(Pontos.size());i++)
	{
		if((Pontos[i]-48)<0||(Pontos[i]-48)>9)
		{
			return false;
		}
	}

	pontos = stoi(Pontos);

	if(pontos < 0 || pontos > 99)
	{
		return false;
	}

	return true;
}

void InfoJogoBasquetebol::InserirSubs(string inputS)
{
	string Nome;
	string Minuto;
	string Segundo;
	std::stringstream s(inputS);

	getline(s,Nome,':');
	getline(s,Minuto,':');
	getline(s,Segundo);


	if(!checkTempo(Minuto,1)||!checkTempo(Segundo,2))
	{
		cout << "Erro. Minuto inválido. Insira entre 0 e 40 minutos e entre 0 a 60 segundos.\n"<< endl;
		return;
	}


	for(itJ=JogEq1.begin(),itJ2=JogEq2.begin();itJ!=JogEq1.end()&&itJ2!=JogEq2.end();itJ++,itJ2++)
	{
		if(!(*itJ).getnome().compare(Nome)||!(*itJ2).getnome().compare(Nome))
		{
			addSubs(inputS);
			cout << "Tempo Jogado de " << Nome << " adicionado com sucesso." << endl;
			return;
		}
	}

		cout << "Dados Inválidos. Insira-os novamente." << endl;
}

void InfoJogoBasquetebol::InserirExps(string inputS)
{
	string Nome;
	string Exp;
	std::stringstream s(inputS);

	getline(s,Nome,':');
	getline(s,Exp);


	if(!Exp.compare("#"))
	{
		cout << "Erro. Formato inválido. Utilize Jog:# para assinalar a expulsão de 'Jog'.\n"<< endl;
		return;
	}

	for(itJ=JogEq1.begin(),itJ2=JogEq2.begin();itJ!=JogEq1.end()&&itJ2!=JogEq2.end();itJ++,itJ2++)
	{
		if(!(*itJ).getnome().compare(Nome)||!(*itJ2).getnome().compare(Nome))
		{
			addExp(Nome);
			cout << "Expulsão adicionada com sucesso." << endl;
			return;
		}
	}

		cout << "Expulsão Inválida. Insira novamente os dados." << endl;
}

void InfoJogoBasquetebol::InserirPontos(string inputS,int ID)
{
	string Nome;
	string pontos;
	std::stringstream s(inputS);
	int ponto=0;

	getline(s,Nome,',');
	getline(s,pontos);

	if(!checkPontos(pontos,ponto))
	{
		cout << "Erro. Valor de pontos inválido. Insira entre 0 e 99.\n" << endl;
		return;
	}


	if(ID==1)
	{
		for(itJ=JogEq1.begin();itJ!=JogEq1.end();itJ++)
		{
			if(!(*itJ).getnome().compare(Nome))
			{
				(*itJ).addpontos(ponto);
				inputS+=":1";
				addPonto(inputS);
				incpontosC(ponto);
				cout << "Pontos adicionados com sucesso!" << endl;
				return;
			}
		}
		cout << "Erro, Jogador não pertence à equipa da casa " << getEq1() << endl;

	}
	else
	{
		for(itJ=JogEq2.begin();itJ!=JogEq2.end();itJ++)
		{
			if(!(*itJ).getnome().compare(Nome))
			{
				(*itJ).addpontos(ponto);
				inputS+=":2";
				addPonto(inputS);
				incpontosV(ponto);
				cout << "Pontos adicionados com sucesso!" << endl;
				return;
			}
		}
		cout << "Erro, Jogador não pertence à equipa visitante " << getEq2() << endl;

	}

}

bool InfoJogoBasquetebol::setvencedor()
{
	if(pontosC>pontosV)
		vencedor=getEq1();
	else if(pontosC<pontosV)
		vencedor=getEq2();
	else
		return false;

	return true;
}
