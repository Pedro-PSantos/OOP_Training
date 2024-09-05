#include "interface.h"



interface::interface() {}

interface::~interface() {}

void interface::BoasVindas()
{
	cout << "Bem-Vindo às informações de 10porto!!" << endl
	     << "Para interagir, selecione o número que aparece à frente" << endl
		 << "da opção a escolher ou insira a informação requerida!" << endl;
}

void interface::Menu()
{
	cout << "\nInserir jogo - 1" << endl
		 << "Ver informações de um jogo - 2" << endl
		 << "Sair - 3" << endl
		 << "\nOpção escolhida: ";
}

void interface::MenuInserir()
{
	cout << "Inserir jogo.\n" << endl;
	cout << "Qual a modalidade?" << endl
		 << "Futebol - 1" << endl
		 << "Basquetebol - 2" << endl
		 << "\nModalidade escolhida: ";
}

void interface::MenuVerJogo()
{
	cout << "Ver Informações de um jogo.\n" << endl;
	cout << "Escolha a modalidade: " << endl;
	cout << "Futebol - 1" << endl
		 << "Basquetebol - 2" << endl;
}

void interface::MenuVerDados(int i)
{
	cout << "\nVer Nome Equipas -         1    ";
	if(i==1)
	cout << "Ver Golos -         5" << endl;
	else
	cout << "Ver Pontos -        5" << endl;

	cout << "Ver Jogadores da Casa -    2    ";

	if(i==1)
		 cout << "Ver Substituições - 6" << endl;
	else
		 cout << "Ver Tempo Jogado -  6" << endl;
	cout << "Ver Jogadores Visitantes - 3    "
		 << "Ver Expulsões -     7" << endl
		 << "Ver Resultado -            4    "
		 << "Sair -              8" << endl

		 << "Opção escolhida: ";
}

int interface::Input()
{
	string input;

	getline(cin,input);

	if(input.size()!=1)
		return 0;
	else
	   return input[0]-48;
}

int interface::ShowStatsF(InfoJogoFutebol F)
{
	vector<Jogador> Jogadores;
	vector<Jogador>::iterator it;
	vector<string> Data;
	vector<string>::iterator itS;

	int minuto,equipa;
	string Jog1,Jog2,aux;


	switch(Input())
	{
	case 1:
		cout << "\nA mostrar Nome das Equipas..." << endl
			 << "Equipa da Casa: " << F.getEq1() << endl
			 << "Equipa Visitante: " << F.getEq2() << endl;
		break;

	case 2:
		Jogadores=F.getJogEq1();

		cout << "\nA mostrar Jogadores da Equipa da Casa..." << endl;

		for(it=Jogadores.begin();it!=Jogadores.end();it++)
		{
			(*it).ShowPlayer(1);
		}
		break;

	case 3:
		Jogadores=F.getJogEq2();

		cout << "\nA mostrar Jogadores da Equipa Visitante..." << endl;

		for(it=Jogadores.begin();it!=Jogadores.end();it++)
		{
			(*it).ShowPlayer(1);
		}
		break;

	case 4:
		cout << "\nA mostrar resultado..." << endl;

		cout << F.getEq1() << " " << F.getGolosC() << "-" << F.getGolosV() << " " << F.getEq2() << endl;

		break;

	case 5:
		Data=F.getGolos();
		cout << "\nA mostrar golos..." << endl;


		if(Data.empty())
		{
			cout << "Não existiram golos no jogo." << endl;
			break;
		}
		for(itS=Data.begin();itS!=Data.end();itS++)
		{
			//cout << (*itS) << endl;
			std::stringstream data((*itS));

			getline(data,Jog1,',');
			getline(data,aux,',');
			minuto=stoi(aux);
			getline(data,aux);
			equipa=stoi(aux);
			if(equipa==1)
				cout << "Golo de " << F.getEq1();
			else
				cout << "Golo de " << F.getEq2();

			if(!Jog1.compare("#"))
				cout << " por autogolo da equipa contrária ";
			else
				cout << " marcado por " << Jog1;

			cout << " no minuto " << minuto << endl;
		}

		break;

	case 6:
		Data=F.getSubs();
		cout << "\nA mostrar substituições..." << endl;

		if(Data.empty())
		{
			cout << "Não existiram substituições neste jogo." << endl;
			break;
		}

		for(itS=Data.begin();itS!=Data.end();itS++)
		{
			//cout << (*itS) << endl;
			std::stringstream data((*itS));

			getline(data,Jog1,',');
			getline(data,Jog2,',');
			getline(data,aux);
			minuto=stoi(aux);

			cout << Jog1 << " foi substituido por " << Jog2 << " no minuto " << minuto << endl;
		}

		break;

	case 7:
		Data=F.getExps();
		cout << "\nA mostrar expulsões..." << endl;

		if(Data.empty())
		{
			cout << "Não existiram expulsões neste jogo." << endl;
			break;
		}

		for(itS=Data.begin();itS!=Data.end();itS++)
		{
			//cout << (*itS) << endl;
			std::stringstream data((*itS));

			getline(data,Jog1,',');
			getline(data,aux);
			minuto=stoi(aux);

			cout << Jog1 << " foi expulso no minuto " << minuto << endl;

		}

		break;

	case 8:
		cout << "\nA fechar Menu...\n" << endl;
		return 1;

	default:
		cout << "\nOpção inválida...\n" << endl;


	return 0;

}


	return 0;
}

int interface::ShowStatsB(InfoJogoBasquetebol B)
{
	vector<Jogador> Jogadores;
	vector<Jogador>::iterator it;
	vector<string> Data;
	vector<string>::iterator itS;

	int pontos,equipa,min,sec;
	string Jog1,Jog2,aux;


	switch(Input())
	{
	case 1:
		cout << "\nA mostrar Nome das Equipas..." << endl
			 << "Equipa da Casa: " << B.getEq1() << endl
			 << "Equipa Visitante: " << B.getEq2() << endl;
		break;

	case 2:
		Jogadores=B.getJogEq1();

		cout << "\nA mostrar Jogadores da Equipa da Casa..." << endl;

		for(it=Jogadores.begin();it!=Jogadores.end();it++)
		{
			(*it).ShowPlayer(2);
		}
		break;

	case 3:
		Jogadores=B.getJogEq2();

		cout << "\nA mostrar Jogadores da Equipa Visitante..." << endl;

		for(it=Jogadores.begin();it!=Jogadores.end();it++)
		{
			(*it).ShowPlayer(2);
		}
		break;

	case 4:
		cout << "\nA mostrar resultado..." << endl;

		cout << B.getEq1() << " " << B.getpontosC() << "-" << B.getpontosV() << " " << B.getEq2() << endl;

		break;

	case 5:
		Data=B.getPontos();
		cout << "\nA mostrar pontos..." << endl;

		if(Data.empty())
		{
			cout << "Não existiram pontos neste jogo." << endl;
			break;
		}

		for(itS=Data.begin();itS!=Data.end();itS++)
		{
			std::stringstream data((*itS));

			getline(data,Jog1,',');
			getline(data,aux,':');
			pontos=stoi(aux);
			getline(data,aux);
			equipa=stoi(aux);

			cout << Jog1 << " marcou " << pontos << " pontos por ";

			if(equipa==1)
				cout << B.getEq1() << endl;
			else
				cout << B.getEq2() << endl;
		}

		break;

	case 6:
		Data=B.getSubs();
		cout << "\nA mostrar tempo jogado..." << endl;

		if(Data.empty())
		{
			cout << "O tempo jogado não foi inserido." << endl;
			break;
		}

		for(itS=Data.begin();itS!=Data.end();itS++)
		{
			std::stringstream data((*itS));

			getline(data,Jog1,':');
			getline(data,aux,':');
			min=stoi(aux);
			getline(data,aux);
			sec=stoi(aux);

			cout << Jog1 << " jogou " << min << ":" << sec << " mins." << endl;
		}

		break;

	case 7:
		Data=B.getExps();
		cout << "\nA mostrar expulsões..." << endl;

		if(Data.empty())
		{
			cout << "Não existiram expulsões neste jogo." << endl;
			break;
		}

		cout << "Os jogadores expulsos foram:" << endl;
		for(itS=Data.begin();itS!=Data.end();itS++)
		{
			cout << (*itS) << ", ";
		}

		break;

	case 8:
		cout << "\nA fechar Menu...\n" << endl;
		return 1;

	default:
		cout << "\nOpção inválida...\n" << endl;


	return 0;

}


	return 0;

}

void interface::InserirDadosJogador(int titular,int i,Jogador &J_inserir)
{
	string inputS;
	int inputN;

	if(titular)
	{
		cout << i << "º Jogador Titular:\n";
		J_inserir.settitular();
		J_inserir.setcheckplay();
	}
	else
		cout << i <<"º Jogador Suplente:\n";

	cout << "Nome: ";
	getline(cin,inputS);
	J_inserir.setnome(inputS);
	for(inputN=-1;inputN < 1 || inputN > 99;)
	{
		cout << "Numero: ";
		cin >> inputN;

		if(inputN < 1 || inputN > 99)
		{
			cout << "Número inválido! Intruduza um número entre 1 e 99." << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	J_inserir.setnumero(inputN);
}

void interface::InserirPosFut(Jogador &J_inserir)
{

	int inputN;

	for(inputN=-1;inputN < 1 || inputN > 4;)
	{
		cout << "Posição do Jogador: " << endl
			 << "Guarda-Redes - 1" << endl
			 << "Defesa - 2" << endl
			 << "Médio - 3" << endl
			 << "Avançado - 4" << endl
			 << "Posição: ";

		cin >> inputN;

		if(inputN < 1 || inputN > 4)
			{
				cout << "Opção Inválida." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

		cout << "\n";

	}
	switch(inputN)
	{
		case 1:
			J_inserir.setposicao("Guarda-Redes");
			break;
		case 2:
			J_inserir.setposicao("Defesa");
			break;
		case 3:
			J_inserir.setposicao("Médio");
			break;
		case 4:
			J_inserir.setposicao("Anvançado");
			break;

	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void interface::InserirPosBas(Jogador &J_inserir)
{

	int inputN;

	for(inputN=-1;inputN < 1 || inputN > 3;)
	{
		cout << "Posição do Jogador: " << endl
			 << "Base - 1" << endl
			 << "Extremo - 2" << endl
			 << "Poste - 3" << endl
			 << "Posição: ";

		cin >> inputN;
		cout << "\n";

		if(inputN < 1 || inputN > 3)
			{
				cout << "Opção Inválida." << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

	}
	switch(inputN)
	{
		case 1:
			J_inserir.setposicao("Base");
			break;
		case 2:
			J_inserir.setposicao("Extremo");
			break;
		case 3:
			J_inserir.setposicao("Poste");
			break;
	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void interface::InserirFutebol(InfoJogoFutebol &F)
{

	string inputS;
	Jogador J_inserir;

	F.setMod("Futebol");

	cout << "Insira os dados requeridos:" << endl
		 << "Nome da equipa da casa: ";
	getline(cin,inputS);
	F.setEq1(inputS);

	cout << "Nome da equipa visitante: ";
	getline(cin,inputS);
	F.setEq2(inputS);

	//Inserir os jogadores da equipa 1
	cout << "Insira os jogadores titulares de " << F.getEq1() << ":" << endl;

	for(int i=1;i<=11;i++)
	{
		InserirDadosJogador(1,i,J_inserir);
		InserirPosFut(J_inserir);
		F.addJogEq1(J_inserir);
	}
	cout << "Todos os jogadores titulares de " << F.getEq1() << " adicionados!\n" << endl;

	cout << "Insira os jogadores suplentes de " << F.getEq1() << ":" << endl;
	for(int i=1;i<=7;i++)
	{
		InserirDadosJogador(0,i,J_inserir);
		InserirPosFut(J_inserir);
		F.addJogEq1(J_inserir);

	}
	cout << "Todos os jogadores suplentes de " << F.getEq1() << " adicionados!\n" << endl;


//Inserir os Jogadores da Equipa2
	cout << "Insira os jogadores titulares de " << F.getEq2() << ":" << endl;

	for(int i=1;i<=11;i++)
	{
		InserirDadosJogador(1,i,J_inserir);
		InserirPosFut(J_inserir);
		F.addJogEq2(J_inserir);
	}
	cout << "Todos os jogadores titulares de " << F.getEq2() << " adicionados!\n" << endl;

	cout << "Insira os jogadores suplentes de " << F.getEq2() << ":" << endl;
	for(int i=1;i<=7;i++)
	{
		InserirDadosJogador(0,i,J_inserir);
		InserirPosFut(J_inserir);
		F.addJogEq2(J_inserir);
	}
	cout << "Todos os jogadores suplentes de " << F.getEq2() << " adicionados!\n" << endl;


	cout << "Insira as substituições e expulsões." << endl
		 << "Utilize o formato:(Sem espaços antes e depois das vírgulas)" << endl
		 << "Nome Jog1,Nome Jog2,Minuto da substituição" << endl
		 << "Ou" << endl
		 << "Nome Jog1,#,Minuto da expulsão\n" << endl;

	//Substituições e Expulções

	//Inserir SUbstituições ou Expulsões das Equipas


	cout << "Quando terminar, escreva 'completo'." << endl;
	cout << "Substituição ou Expulsão: ";


	for(getline(cin,inputS);inputS.compare("completo");getline(cin,inputS))
	{
		F.InserirSubsExp(inputS);
		cout << "Substituição ou Expulsão: ";
	}

	cout <<"\n\nSubstituições e Expulsões adicionadas com sucesso!!" << endl;


	//Inserir Golos

	cout << "\nInsira os Golos do Jogo." << endl
		 << "Utilize o formato:(Sem espaçoes entre vírgulas)" << endl
		 << "Nome Jog1,Minuto do Golo" << endl
		 << "Ou" << endl
		 << "#,Minuto do Autogolo" << endl;

	cout << "Quando terminar, escreva 'completo'." << endl;

	cout << "Golos da Equipa da casa: " << endl;
	cout << "Golo da casa: ";
	for(getline(cin,inputS);inputS.compare("completo");getline(cin,inputS))
	{
		F.InserirGolos(inputS,1);
		cout << "Golo da casa: ";
	}
	cout << "\nGolos da Equipa da casa adicionados com sucesso!\n " << endl;

	cout << "Golos da Equipa Visitante: " << endl;
	cout << "Golo do visitante: ";
		for(getline(cin,inputS);inputS.compare("completo");getline(cin,inputS))
		{
			F.InserirGolos(inputS,2);
			cout << "Golo do visitante: ";
		}
	cout << "\nGolos da Equipa Visitante adicionados com sucesso!\n " << endl;

	//Seleciona o vencedor com os dados dos golos inseridos
	F.setvencedor();

}

void interface::InserirBasquetebol(InfoJogoBasquetebol &B)
{
	string inputS;
	Jogador J_inserir;

	B.setMod("Basquetebol");

	cout << "Insira os dados requeridos:" << endl
		 << "Nome da equipa da casa: ";
	getline(cin,inputS);
	B.setEq1(inputS);

	cout << "Nome da equipa visitante: ";
	getline(cin,inputS);
	B.setEq2(inputS);

	//Inserir os jogadores da equipa 1
	cout << "Insira os jogadores titulares de " << B.getEq1() << ":" << endl;

	for(int i=1;i<=5;i++)
	{
		InserirDadosJogador(1,i,J_inserir);
		InserirPosBas(J_inserir);
		B.addJogEq1(J_inserir);
	}
	cout << "Todos os jogadores titulares de " << B.getEq1() << " adicionados!\n" << endl;

	cout << "Insira os jogadores suplentes de " << B.getEq1() << ":" << endl;
	for(int i=1;i<=7;i++)
	{
		InserirDadosJogador(0,i,J_inserir);
		InserirPosBas(J_inserir);
		B.addJogEq1(J_inserir);
	}
	cout << "Todos os jogadores suplentes de " << B.getEq1() << " adicionados!\n" << endl;


//Inserir os Jogadores da Equipa2
	cout << "Insira os jogadores titulares de " << B.getEq2() << ":" << endl;

	for(int i=1;i<=5;i++)
	{
		InserirDadosJogador(1,i,J_inserir);
		InserirPosBas(J_inserir);
		B.addJogEq2(J_inserir);
	}
	cout << "Todos os jogadores titulares de " << B.getEq2() << " adicionados!\n" << endl;

	cout << "Insira os jogadores suplentes de " << B.getEq2() << ":" << endl;
	for(int i=1;i<=7;i++)
	{
		InserirDadosJogador(0,i,J_inserir);
		InserirPosBas(J_inserir);
		B.addJogEq2(J_inserir);
	}
	cout << "Todos os jogadores suplentes de " << B.getEq2() << " adicionados!\n" << endl;

	cout << "Insira o tempo jogado de cada jogador." << endl
		 << "Utilize o formato:(Sem espaços antes e depois dos dois pontos)" << endl
		 << "Nome Jog:Min:Seg Totais Jogados" << endl;


	//Substituições(Neste caso tempo jogado)

	//Inserir Substituições


	cout << "Quando terminar, escreva 'completo'." << endl;
	cout << "Tempo Jogado:";

	for(getline(cin,inputS);inputS.compare("completo");getline(cin,inputS))
	{
		B.InserirSubs(inputS);
		cout << "Tempo Jogado:";
	}
	cout <<"\n\nTempo jogado por jogador adicionado com sucesso!!" << endl;

	cout << "Insira os jogadores que foram expulsos." << endl
		 << "Utilize o formato:(Sem espaçoes antes e depois dos dois pontos)" << endl
		 << "Nome Jog:#" << endl;

	//Expulsões

	cout << "Quando terminar, escreva 'completo'." << endl;
	cout << "Tempo Jogado:";

	for(getline(cin,inputS);inputS.compare("completo");getline(cin,inputS))
	{
		B.InserirSubs(inputS);
		cout << "Tempo Jogado:";
	}
	cout <<"\n\nExpulsões adicionadas com sucesso!!" << endl;



	cout << "Insira os Pontos do Jogo." << endl
		 << "Utilize o formato:(Sem espaçoes entre vírgulas)" << endl
		 << "Nome Jog1,Pontos totais marcados" << endl;

	for(int checktie=0;checktie==0;)
	{
		cout << "Quando terminar, escreva 'completo'." << endl;

		cout << "Pontos da Equipa da casa: " << endl;
		cout << "Pontos da casa: ";
		for(getline(cin,inputS);inputS.compare("completo");getline(cin,inputS))
		{
			B.InserirPontos(inputS,1);
			cout << "Pontos da casa: ";

		}

		cout << "Golos da Equipa Visitante: " << endl;
		cout << "Pontos do visitante: ";
		for(getline(cin,inputS);inputS.compare("completo");getline(cin,inputS))
		{
			B.InserirPontos(inputS,2);
			cout << "Pontos do visitante: ";
		}

		if(B.setvencedor())
			checktie=1;
		else
			cout << "Não pode haver empates.Por favor insira os pontos que faltam.\n" << endl;


	}

}

bool interface::ReadGameF(InfoJogoFutebol &F)
{
	string Data;
	string Eq1,Eq2,buffer;
	string nomeficheiro="F_";

	cout << "Insira os nomes das equipas do jogo a ver:" << endl
		 << "Equipa da Casa: ";
	getline(cin,Eq1);
	cout << "Equipa Visitante: ";
	getline(cin,Eq2);

	nomeficheiro+=Eq1+"-VS-"+Eq2+".txt";

	std::fstream read;
	read.open(nomeficheiro, std::ios::in);
	if(!read.is_open())
	{
		return false;
	}
	else
	{
		int i=0;

		while(getline(read,buffer))
		{
			if(!buffer.compare("Jogo"+std::to_string(i+1)+":"))
			{
				i++;
			}
		}

		read.clear();
		read.seekg(0);

		if(i!=1)
		{
			cout << "Existem " << i << " jogos entre " << Eq1 << " e " << Eq2 <<endl
				 << "Insira o número do jogo que deseja ver: ";

			while((i=Input())==0)
			{
				cout << "Opção Inválida. Insira Novamente o jogo a ver: " ;
			}


			cout << "Mostrar Jogo " << i;
		}

		buffer.clear();

		//procura jogo selecionado para começar a guardar informação
		while(buffer.compare("Jogo"+std::to_string(i)+":"))
		{
			getline(read,buffer);

		}


		getline(read,buffer);
		std::stringstream data(buffer);

		getline(data,Data,';');
		F.setMod(Data);

		getline(data,Data,';');
		F.setEq1(Data);

		getline(data,Data,';');
		F.setEq2(Data);

		getline(data,Data,';');
		F.setGolosC(stoi(Data));

		getline(data,Data,';');
		F.setGolosV(stoi(Data));

		getline(data,Data,';');
		F.setvencedor(Data);


		string Nome,Num,Pos,Golos;
		Jogador Jog_I;

		//le todos os jogadores adicionando-os à sua respectiva equipa
		//como são 18 jogadores para cada equipa guarda jogadores na equipa 1 até o iterador chegar a esse valor e depois guarda na equipa 2
		for(int j=0;j<36;j++)
		{

			getline(read,buffer);
 			std::stringstream data(buffer);

			getline(data,Nome,';');
			getline(data,Num,';');
			getline(data,Pos,';');
			getline(data,Golos,';');

			Jog_I.setnome(Nome);
			Jog_I.setnumero(stoi(Num));
			Jog_I.setposicao(Pos);
			Jog_I.setScore(stoi(Golos));

			if(j<18)
			{
				F.addJogEq1(Jog_I);
			}
			else
			{
				F.addJogEq2(Jog_I);
			}
		}

		//elimina delimitador Subs: e procura o delimitador Exps:, onde acabam as substituições e começam as expulsoes
		getline(read,buffer);
		getline(read,buffer);

		while(buffer.compare("Exps:"))
		{
			F.addSubs(buffer);
			getline(read,buffer);
		}

		//elimina delimiter Exps para começar a ler expulsoes:
		getline(read,buffer);

		//le as expulsões até encontrar delimitador Golos:
		while(buffer.compare("Golos:"))
		{
			F.addExp(buffer);
			getline(read,buffer);
		}

		//lê os golos até eof(caso seja o último ou único jogo do ficheiro)
		//ou até encontrar o delimitador Jogo'x', onde começa o próximo jogo 'x'
		while(getline(read,buffer) && buffer.compare("Jogo"+std::to_string(i+1)+":"))
		{
			cout << "Golo: " << buffer << endl;
			F.addGolo(buffer);
		}


		read.close();
	}

	return true;
}

bool interface::ReadGameB(InfoJogoBasquetebol &B)
{
	string Data;
	string Eq1,Eq2,buffer;
	string nomeficheiro="B_";

	cout << "Insira os nomes das equipas do jogo a ver:" << endl
		 << "Equipa da Casa: ";
	getline(cin,Eq1);
	cout << "Equipa Visitante: ";
	getline(cin,Eq2);

	nomeficheiro+=Eq1+"-VS-"+Eq2+".txt";

	std::fstream read;
	read.open(nomeficheiro, std::ios::in);
	if(!read.is_open())
	{
		return false;
	}
	else
	{
		int i=0;

		while(getline(read,buffer))
		{
			if(!buffer.compare("Jogo"+std::to_string(i+1)+":"))
			{
				i++;
			}
		}

		read.clear();
		read.seekg(0);

		if(i!=1)
		{
			cout << "Existem " << i << " jogos entre " << Eq1 << " e " << Eq2 <<endl
				 << "Insira o número do jogo que deseja ver: ";

			while((i=Input())==0)
			{
				cout << "Opção Inválida. Insira Novamente o jogo a ver: " ;
			}
		}

		buffer.clear();

		while(buffer.compare("Jogo"+std::to_string(i)+":"))
		{
			getline(read,buffer);
		}

		getline(read,buffer);
		std::stringstream data(buffer);

		getline(data,Data,';');
		B.setMod(Data);

		getline(data,Data,';');
		B.setEq1(Data);

		getline(data,Data,';');
		B.setEq2(Data);

		getline(data,Data,';');

		B.setpontosC(stoi(Data));

		getline(data,Data,';');

		B.setpontosV(stoi(Data));

		getline(data,Data,';');
		B.setvencedor(Data);


		string Nome,Num,Pos,Pontos;
		Jogador Jog_I;

		for(int j=0;j<24;j++)
		{

			getline(read,buffer);
			std::stringstream data(buffer);

			getline(data,Nome,';');
			getline(data,Num,';');
			getline(data,Pos,';');
			getline(data,Pontos,';');

			Jog_I.setnome(Nome);
			Jog_I.setnumero(stoi(Num));
			Jog_I.setposicao(Pos);
			Jog_I.setScore(stoi(Pontos));

			if(j<12)
			{
				B.addJogEq1(Jog_I);
			}
			else
			{
				B.addJogEq2(Jog_I);
			}
		}

		getline(read,buffer);
		getline(read,buffer);

		while(buffer.compare("Exps:"))
		{
			B.addSubs(buffer);
			getline(read,buffer);
		}

		getline(read,buffer);

		while(buffer.compare("Pontos:"))
		{
			B.addExp(buffer);
			getline(read,buffer);
		}

		while(getline(read,buffer) && buffer.compare("Jogo"+std::to_string(i+1)+":"))
		{
			B.addPonto(buffer);
		}

		read.close();
	}

	return true;
}

bool interface::SaveGameF(InfoJogoFutebol &F)
{
	vector<Jogador>::iterator itJ;
	vector<string>::iterator itS;
	vector<Jogador>Aux;
	vector<string>AuxS;
	std::fstream write;
	string nomeficheiro="F_";
	bool NewFile=false;
	int i=1;
	string buffer;

	nomeficheiro+=F.getEq1()+"-VS-"+F.getEq2();
	nomeficheiro+=".txt";

	write.open(nomeficheiro,std::ios::in);
	if(!write.is_open())
	{
		NewFile=true;
	}
	else
	{
		while(getline(write,buffer))
		{
			if(!buffer.compare("Jogo"+std::to_string(i)+":"))
			{
				i++;
			}
		}
	}
	write.close();

	write.open(nomeficheiro, std::ios::app);
	if (write.is_open())
	{
		if(NewFile)
		{
			write << "Jogo1:" << endl;
		}
		else
		{
			write << "Jogo" << i << ":" << endl;
		}

		cout << "Saving Data..." << endl;

		write << F.getMod() << ";" << F.getEq1() << ";" << F.getEq2() << ";"
			  << F.getGolosC() << ";" << F.getGolosV() << ";" << F.getvencedor() << ";" << endl;

		Aux=F.getJogEq1();
		for(itJ=Aux.begin();itJ!=Aux.end();itJ++)
		{
			write << (*itJ).getnome() << ";" << (*itJ).getnumero() << ";" << (*itJ).getposicao() << ";"
				  << (*itJ).getpontos() << endl;
		}

		Aux =F.getJogEq2();
		for(itJ=Aux.begin();itJ!=Aux.end();itJ++)
		{
			write << (*itJ).getnome() << ";" << (*itJ).getnumero() << ";" << (*itJ).getposicao() << ";"
				  << (*itJ).getpontos() << endl;
		}

		AuxS =F.getSubs();
		write << "Subs:" << endl;
		for(itS=AuxS.begin();itS!=AuxS.end();itS++)
		{
			write << (*itS) << endl;
		}

		AuxS =F.getExps();
		write << "Exps:" << endl;
		for(itS=AuxS.begin();itS!=AuxS.end();itS++)
		{
			write << (*itS) << endl;
		}

		AuxS =F.getGolos();
		write << "Golos:" << endl;
		for(itS=AuxS.begin();itS!=AuxS.end();itS++)
		{
			write << (*itS) << endl;
		}

		write.close();

		return true;
	}
	else
		return false;
}

bool interface::SaveGameB(InfoJogoBasquetebol &B)
{
	vector<Jogador>::iterator itJ;
	vector<string>::iterator itS;
	vector<Jogador>Aux;
	vector<string>AuxS;
	std::fstream write;
	string nomeficheiro="B_";
	bool NewFile=false;
	int i=1;
	string buffer;

	nomeficheiro+=B.getEq1()+"-";
	nomeficheiro+="VS";
	nomeficheiro+="-"+B.getEq2();
	nomeficheiro+=".txt";

	write.open(nomeficheiro,std::ios::in);
	if(!write.is_open())
	{
		NewFile=true;
	}
	else
	{
		while(getline(write,buffer))
		{
			if(!buffer.compare("Jogo"+std::to_string(i)+":"))
			{
				i++;
			}
		}
	}
	write.close();

	write.open(nomeficheiro, std::ios::app);

	if (write.is_open())
	{
		if(NewFile)
		{
			write << "Jogo1:" << endl;
		}
		else
		{
			write << "Jogo" << i << ":" << endl;
		}

		write << B.getMod() << ";" << B.getEq1() << ";" << B.getEq2() << ";"
			  << B.getpontosC() << ";" << B.getpontosV() << ";" << B.getvencedor() << ";" << endl;

		Aux=B.getJogEq1();
		for(itJ=Aux.begin();itJ!=Aux.end();itJ++)
		{
			write << (*itJ).getnome() << ";" << (*itJ).getnumero() << ";" << (*itJ).getposicao() << ";"
				  << (*itJ).getpontos() << endl;
		}

		Aux =B.getJogEq2();
		for(itJ=Aux.begin();itJ!=Aux.end();itJ++)
		{
			write << (*itJ).getnome() << ";" << (*itJ).getnumero() << ";" << (*itJ).getposicao() << ";"
				  << (*itJ).getpontos() << endl;
		}

		AuxS =B.getSubs();
		write << "Subs:" << endl;
		for(itS=AuxS.begin();itS!=AuxS.end();itS++)
		{
			write << (*itS) << endl;
		}

		AuxS =B.getExps();
		write << "Exps:" << endl;
		for(itS=AuxS.begin();itS!=AuxS.end();itS++)
		{
			write << (*itS) << endl;
		}

		AuxS =B.getPontos();
		write << "Pontos:" << endl;
		for(itS=AuxS.begin();itS!=AuxS.end();itS++)
		{
			write << (*itS) << endl;
		}

		write.close();

		return true;
	}
	else
		return false;
}

void interface::startInterface()
{

	int input;

	BoasVindas();

		for(int i=0;i==0;)
		{
			Menu();

			switch(Input())
			{
				case 1:
					MenuInserir();

					if((input=Input())==1)
					{
						InfoJogoFutebol F;
						cout << "Futebol.\n" << endl;
						InserirFutebol(F);

						if(!F.getvencedor().compare("empate"))
							cout << "\nJogo terminado em empate." << endl;
						else
							cout << "\nVencedor: " << F.getvencedor() << endl;

						cout << "\nJogo Inserido com sucesso!\n" << endl;
						if(!SaveGameF(F))
							cout << "ERRO A GUARDAR INFORMAÇÕES!\n" << endl;
						else
							cout << "Jogo inserido e guardado com sucesso!" << endl;
					}
					else if(input==2)
					{

						InfoJogoBasquetebol B;
						cout << "Basquetebol.\n" << endl;
						InserirBasquetebol(B);
						cout << "\nVencedor: " << B.getvencedor() << endl;
						if(!SaveGameB(B))
							cout << "ERRO A GUARDAR INFORMAÇÕES!\n" << endl;
						else
							cout << "Jogo inserido e guardado com sucesso!" << endl;
					}
					else
						cout << "\nOpção Inválida." << endl;
					break;

				case 2:
					MenuVerJogo();

					if((input=Input())==1)
					{
						InfoJogoFutebol F;
						if(!ReadGameF(F))
						{
							cout << "Erro! Jogo Inexistênte." << endl;
							break;
						}

						for(int j=0;j==0;)
						{
							MenuVerDados(1);
							j=ShowStatsF(F);
						}
						break;
					}
					else if(input==2)
					{
						InfoJogoBasquetebol B;
						if(!ReadGameB(B))
						{
							cout << "Erro! Jogo Inexistênte." << endl;
							break;
						}

						for(int j=0;j==0;)
						{
							MenuVerDados(0);
							j=ShowStatsB(B);
						}
						break;
					}
					else
						cout << "\nOpção Inválida." << endl;
					break;

				case 3:
					cout << "A sair do programa." << endl;
					exit(0);

				default:
					cout << "Opção inválida. Por favor escolha novamente..." << endl;
					break;
			}
		}

}
