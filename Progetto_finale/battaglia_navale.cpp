#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <Windows.h>
//#include <windows.h>

using namespace std;

#include "Battlefield.hpp"
#include "SupportVessel.hpp"
#include "Coordinate.hpp"
#include "BattleShip.hpp"
#include "Submarine.hpp"
#include "Human.hpp"
#include "Computer.hpp"

constexpr int NUM_MOSSE = 50;

int main(int argc, char* argv[]){ // primo argomento argc , il secondo argomento memorizza in un array di puntatori char, fungono da array di stringhe
	
	//Se l'utente compila ma non mette nessun comando oppure
	//Mette troppi comandi termina
	if(argc == 1 || argc > 3) return 0; 
	
	//Nella cella 0 c'è il comando per eseguire il programma, nel 1 invece ci sarà l'istruzione PC o CC
	string input = argv[1];
	
	//Creo il file di log dove andrò a scrivere tutto quello che avvienne durante la partita
	ofstream log("C://Users//alex1//Codlite_workspace//Codlite_workspace//Progetto_finale//log.txt");
	
	//Partita Player vs Computer
	if(input == "PC"){
		
		system("cls");
		cout<<"Hai selezionato di giocare contro il computer"<<endl; 
		
		//Inizzializzo i due giocatori
		Human g1;
		Computer g2;
		
		//Dichiarazione barche Player
		BattleShip g1_bs1, g1_bs2, g1_bs3;
		SupportVessel g1_sup1, g1_sup2, g1_sup3;
		Submarine g1_s1, g1_s2;

		//Dichiarazione barche Computer
		BattleShip g2_bs1, g2_bs2, g2_bs3;
		SupportVessel g2_sup1, g2_sup2, g2_sup3;
		Submarine g2_s1, g2_s2;
		
		//Inizzializzazione Battlefield
		Battlefield b1;//di Player
		Battlefield b2;//di Computer
		
		//Inizzializzazione barche Player
		g1.init_unit(b1,&g1_bs1,log);
		g1.init_unit(b1,&g1_bs2,log);
		g1.init_unit(b1,&g1_bs3,log);
		g1.init_unit(b1,&g1_sup1,log);
		g1.init_unit(b1,&g1_sup2,log);
		g1.init_unit(b1,&g1_sup3,log);
		g1.init_unit(b1,&g1_s1,log);
		g1.init_unit(b1,&g1_s2,log);
		
		//Inizizalizzazione barche Computer
		g2.init_unit(b2,&g2_bs1,log);
		g2.init_unit(b2,&g2_bs2,log);
		g2.init_unit(b2,&g2_bs3,log);
		g2.init_unit(b2,&g2_sup1,log);
		g2.init_unit(b2,&g2_sup2,log);
		g2.init_unit(b2,&g2_sup3,log);
		g2.init_unit(b2,&g2_s1,log);
		g2.init_unit(b2,&g2_s2,log);
		
		
		Sleep(500);
		system("cls");
		
		cout<<"\n\n\t\t\tInizia la Partita"<<endl<<endl;
		Sleep(500);
		system("cls");
		cout<<"\n\n\t\t\tInizia la Partita."<<endl<<endl;
		Sleep(500);
		system("cls");
		cout<<"\n\n\t\t\tInizia la Partita.."<<endl<<endl;
		Sleep(500);
		system("cls");
		cout<<"\n\n\t\t\tInizia la Partita..."<<endl<<endl;
		Sleep(500);
		system("cls");
		cout<<"Ecco il tuo schieramento:"<<endl<<endl;
		cout<<b1<<endl<<endl;
		Sleep(5000);
		system("cls");
		
		int turn_count = 0;
		
		//Turni della partita Player vs Computer
		while( (turn_count != NUM_MOSSE+1) && (!b1.is_empty() && !b2.is_empty()) ){

			if(turn_count %2 == 0){
				cout<<"TURN: "<<turn_count<<endl;
				//cout<<b1<<endl<<endl;
				turn_count += g1.turn(b1,b2,log);
				//cout<<b1<<endl;
				cout<<"---------------------------------------------------------------------------------------"<<endl;
				Sleep(1500);
				system("cls");
				continue;
			}
			if(turn_count %2 != 0){
				//cout<<"TURN: "<<turn_count<<endl;
				turn_count += g2.turn(b2,b1,log);
				continue;
			}
		}
	}
	
	//Partita Computer vs Computer
	if(input == "CC"){
		
		cout<<"Hai selezionato di simulare una partita computer vs computer"<<endl;
		//Inizzializzo i due giocatori
		Computer g1;
		Computer g2;
		
		//Dichiarazione barche Player
		BattleShip g1_bs1, g1_bs2, g1_bs3;
		SupportVessel g1_sup1, g1_sup2, g1_sup3;
		Submarine g1_s1, g1_s2;

		//Dichiarazione barche Computer
		BattleShip g2_bs1, g2_bs2, g2_bs3;
		SupportVessel g2_sup1, g2_sup2, g2_sup3;
		Submarine g2_s1, g2_s2;
		
		//Inizzializzazione Battlefield
		Battlefield b1;//di Player
		Battlefield b2;//di Computer
		
		//Inizzializzazione barche Computer (g1)
		g1.init_unit(b1,&g1_bs1,log);
		g1.init_unit(b1,&g1_bs2,log);
		g1.init_unit(b1,&g1_bs3,log);
		g1.init_unit(b1,&g1_sup1,log);
		g1.init_unit(b1,&g1_sup2,log);
		g1.init_unit(b1,&g1_sup3,log);
		g1.init_unit(b1,&g1_s1,log);
		g1.init_unit(b1,&g1_s2,log);
		
		//Inizizalizzazione barche Computer (g2)
		g2.init_unit(b2,&g2_bs1,log);
		g2.init_unit(b2,&g2_bs2,log);
		g2.init_unit(b2,&g2_bs3,log);
		g2.init_unit(b2,&g2_sup1,log);
		g2.init_unit(b2,&g2_sup2,log);
		g2.init_unit(b2,&g2_sup3,log);
		g2.init_unit(b2,&g2_s1,log);
		g2.init_unit(b2,&g2_s2,log);
		
		system("cls");
		Sleep(500);
		
		cout<<"\n\n\t\t\tInizia la Partita"<<endl<<endl;
		Sleep(500);
		system("cls");
		cout<<"\n\n\t\t\tInizia la Partita."<<endl<<endl;
		Sleep(500);
		system("cls");
		cout<<"\n\n\t\t\tInizia la Partita.."<<endl<<endl;
		Sleep(500);
		system("cls");
		cout<<"\n\n\t\t\tInizia la Partita..."<<endl<<endl;
		Sleep(500);
		system("cls");
		cout<<"Ecco il tuo schieramento:"<<endl<<endl;
		cout<<b1<<endl<<endl;
		Sleep(5000);
		int turn_count = 0;
		
		//Turni della partita Computer vs Computer
		while( (turn_count != NUM_MOSSE+1) && (!b1.is_empty() && !b2.is_empty()) ){
			
			if(turn_count %2 == 0){
				//system("cls");
				cout<<"Player 1 TURN : "<<turn_count<<endl;
				turn_count += g1.turn(b1,b2,log);
				cout<<b1<<endl;
				cout<<"---------------------------------------------------------------------------------------"<<endl;
				//Sleep(1500);
				continue;
			}
			if(turn_count %2 != 0){
				//system("cls");
				cout<<"Player 2 TURN: "<<turn_count<<endl;
				turn_count += g2.turn(b2,b1,log);
				cout<<b2<<endl;
				cout<<"---------------------------------------------------------------------------------------"<<endl;
				//Sleep(1500);
				continue;
			}
		}
	}

	return 0;
}