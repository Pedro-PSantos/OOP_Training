#include "InfoJogoFutebol.h"

InfoJogoFutebol::InfoJogoFutebol() : InfoJogo(){
	golosC=0;
	golosV=0;
}

InfoJogoFutebol::~InfoJogoFutebol() {
	// TODO Auto-generated destructor stub
}

bool InfoJogoFutebol::checkMinuto(string Minuto)
{
	if(int(Minuto.size())>2||Minuto.empty())
	{
		return false;
	}

	for(int i=0;i<int(Minuto.size());i++)
	{
		if((Minuto[i]-48)<0||(Minuto[i]-48)>9)
		{
			return false;
		}
	}

	int time = stoi(Minuto);

	if(time < 0 || time >90)
	{
		return false;
	}

	return true;
}
void InfoJogoFutebol::setvencedor()
{
	if(golosC>golosV)
		vencedor=getEq1();
	else if(golosC<golosV)
		vencedor=getEq2();
	else
		vencedor="empate";
}


void InfoJogoFutebol::InserirSubsExp(string inputS)
{
	string Nome1;
	string Nome2;
	string Minuto;
	std::stringstream s(inputS);
	int check1,check2,checkpresence=0;

	getline(s,Nome1,',');
	getline(s,Nome2,',');
	getline(s,Minuto,',');



	if(!checkMinuto(Minuto))
	{
		cout << "Erro. Minuto inválido. Insira entre 0 e 90 minutos.\n"<< endl;
		return;
	}

	if(Nome2!="#")
	{
		for(check1=0,check2=0,itJ=JogEq1.begin();itJ!=JogEq1.end();itJ++)
		{
			if(!(*itJ).getnome().compare(Nome1))
			{
				check1++;
			}
			if(!(*itJ).getnome().compare(Nome2))
			{
				check2++;
			}
			if(check1>0&&check2>0)
				checkpresence=1;

		}
		for(check1=0,check2=0,itJ=JogEq2.begin();itJ!=JogEq2.end();itJ++)
		{
			if(!(*itJ).getnome().compare(Nome1))
			{
				check1++;
			}
			if(!(*itJ).getnome().compare(Nome2))
			{
				check2++;
			}
			if(check1>0&&check2>0)
			{
				checkpresence=1;
				break;
			}
		}

		if(checkpresence==0)
			cout << "Substituição Inválida. Insira novamente os dados." << endl;
		else
		{
			addSubs(inputS);
			cout << "Substituição adicionada com sucesso!" << endl;
		}
	}
	else
	{
		for(check1=0,itJ=JogEq1.begin(),itJ2=JogEq2.begin();itJ!=JogEq1.end()&&itJ2!=JogEq2.end();itJ++,itJ2++)
		{
			if(!(*itJ).getnome().compare(Nome1))
			{
				check1++;
			}
			if(!(*itJ2).getnome().compare(Nome1))
			{
				check2++;
			}
			if(check1>0||check2>0)
			{
				checkpresence=1;
				break;
			}

		}

		if(checkpresence==0)
			cout << "Expulsão Inválida. Insira novamente os dados." << endl;
		else
		{
			addExp((Nome1+","+Minuto));
			cout << "Expulsão adicionada com sucesso!" << endl;
		}
	}
}


void InfoJogoFutebol::InserirGolos(string inputS,int ID)
{
	string Nome;
	string Minuto;
	std::stringstream s(inputS);
	getline(s,Nome,',');
	getline(s,Minuto,',');


	if(!checkMinuto(Minuto))
	{
		cout << "Erro. Minuto inválido. Insira entre 0 e 90 minutos.\n"<< endl;
		return;
	}

	if(ID==1)
	{
		if(!Nome.compare("#"))
		{
			inputS+=",1";
			addGolo(inputS);
			incgolosC();
			cout << "Golo adicionado com sucesso!" << endl;
			return;

		}
		for(itJ=JogEq1.begin();itJ!=JogEq1.end();itJ++)
		{
			if(!(*itJ).getnome().compare(Nome))
			{
				(*itJ).addgolo();
				inputS+=",1";
				addGolo(inputS);
				incgolosC();
				cout << "Golo adicionado com sucesso!" << endl;
				return;
			}
		}
		cout << "Erro, Jogador não pertence à equipa da casa " << getEq1() << endl;
	}
	else
	{
		if(!Nome.compare("#"))
		{
			inputS+=",2";
			addGolo(inputS);
			incgolosV();
			cout << "Golo adicionado com sucesso!" << endl;
			return;
		}
		for(itJ=JogEq2.begin();itJ!=JogEq2.end();itJ++)
		{
			if(!(*itJ).getnome().compare(Nome))
			{
				(*itJ).addgolo();
				inputS+=",2";
				addGolo(inputS);
				incgolosV();
				cout << "Golo adicionado com sucesso!" << endl;
				return;
			}
		}
		cout << "Erro, Jogador não pertence à equipa visitante " << getEq2() << endl;
	}
}
