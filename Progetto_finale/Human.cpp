#include "Human.hpp"

//Initialization
//Passiamo anche un puntatore già deferenziato in modo tale da poter lavorare su quela specifica barca
void Human:: init_unit(Battlefield& b1 , NavalUnit* unit ,std::ofstream& log ){
	
	while(true){
		system("cls");
		Sleep(500);
		std::cout<<"Quali sono le coordinate per "<<get_unit_name()<< " ?" << std::endl;
		
		std::string input1, input2;
		std::cin>> input1 >> input2;
		//controllo che la stringa inserita non sia valida
		if(input1.size() == 0 || input2.size() == 0 || input1.size() > 3 || input2.size() > 3 ) continue;
		
		Coordinate bow , stern;
		
		bow = Coordinate(input1);
		stern = Coordinate(input2);
		
		std::vector<Coordinate> positions = generate_inline_position(bow, stern);
		
		//Controllo che non sia diverso dalla size effettiva di quella data NavalUnit
		if((int)positions.size() != unit->size()) {
			std::cout<<"Lunghezza della barca non coincide"<<std::endl;
			Sleep(500);
			std::cin.clear(); //pulisce il cin
			std::cin.ignore(100,'\n');// se la stringa inserita ha più di 100 input li ignora
			continue;
		}
		
		//Controllo che le coordinate siano tutte interne al battlefield
		if(!b1.is_inside(positions)) {
			std::cout<<"Le posizioni inserite non sono totalmente interne"<<std::endl;
			Sleep(500);
			std::cin.clear(); //pulisce il cin
			std::cin.ignore(100,'\n');// se la stringa inserita ha più di 100 input li ignora
			continue;
		}
		
		//Controllo che non sovrascriviamo delle barche sul battlefield
		if(b1.check_position(positions)) {
			std::cout<<"Le posizioni inserite sono gia' occupate alemeno in parte"<<std::endl;
			Sleep(500);
			std::cin.clear(); //pulisce l'input
			std::cin.ignore(100,'\n');
			continue;
		}
		
		//Settaggio delle posizioni
		unit->set_positions(positions);
		
		//Inserimento barca
		b1.insert(unit);
		
		// Aggiorno il contatore, dopo Corazzata 1 andrò a printare Corazzata 2 e cosi via.
		initialized_units_++; 
		
		//scrive nel file log per passarlo poi al replay
		log<<input1<<" "<<input2<<std::endl; 
		
		//esco dal ciclo della barca i-esima
		break; 
	}
	
}

//Turn
int Human::turn(Battlefield& b1 , Battlefield& b2, std::ofstream& log){

	while(true){
		
		std::cout<<"E' il tuo turno, seleziona la barca per compiere una nuova mossa, e imponi la coordinata di target!"<<std::endl;
		
		std::string input1, input2;
		std::cin>> input1 >> input2;
		
		//controllo che la stringa inserita non sia valida
		if(input1.size() == 0 || input2.size() == 0 || input1.size()>3 || input2.size()>3 ) continue;
		
		//Controllo Comandi speciali
		if(special_commands(b1,input1,input2)) continue; // per evitare che stampi in maniera disordinata il battlefield sotto la domanda
		
		Coordinate unit_pos , target;
		
		unit_pos = Coordinate(input1);
		target = Coordinate(input2);
		
		
		
		//Controllo che la corrdinata di target vada bene
		if(!b2.is_inside(target)){ 
			std::cout<<"La coordinata di target non e' all'interno della matrice"<<std::endl; 
			continue;
		}
		
		//Seleziono la barca con cui fare la mossa
		NavalUnit* unit = b1.choose_unit(unit_pos);
		
		//Controllo che sia stato selezionato correttamente un centro di massa
		//di una navae altrimenti, choose_unit ritorna un puntatore nullo
		if(unit == nullptr){
			std::cout<<"La coordinata selezionata non corrisponde al cm di nessuna barca"<<std::endl;
			continue;
		}
		
		//Scrivo nel log NOTA : bisogna scriverlo prima di fare l'azione altrimenti quando vado a prendere il file 
		//dal log vad a prendere quella del centro di massa di una nave che si è spostata e di conseguenza crea problemi molto pericolosi
		log<<input1<<" "<<input2<<std::endl;
		
		//Faccio l'azione specifica della nave
		unit->action(b1,b2,target);
		
		break;
	}
	//Alla fine di ogni turno ritorna 1, incrementando un contatore nel main
	return 1;
}

//Funzione privata che mi ritorna l'output del nome di barca da stampare
std::string Human:: get_unit_name(){
	
	switch(initialized_units_){
		case 1: return "Corazzata 1";
		case 2: return "Corazzata 2";
		case 3: return "Corazzata 3";
		case 4: return "SupportVessel 1";
		case 5: return "SupportVessel 2";
		case 6: return "SupportVessel 3";
		case 7: return "Submarine 1";
		case 8: return "Submarine 2";
	
		default : break;
	
	}
	return nullptr; 
}

bool Human:: special_commands(Battlefield& b1, std::string input1, std::string input2){
	
	//AA AA cancella gli avvistamenti sonar
	if(input1 == "AA" && input2 == "AA"){
		//seleziono il tipo di "pulizia"
		b1.clean_attack('Y');
		return true;
	}
	//BB BB cancella i relativi ai colpi andati a segno
	if(input1 == "BB" && input2 == "BB"){
		//seleziono il tipo di "pulizia"
		b1.clean_attack('X');
		return true;
	}
	//CC CC cancella i colpi a vuoto
	if(input1 == "CC" && input2 == "CC"){
		//seleziono il tipo di "pulizia"
		b1.clean_attack('O');
		return true;
	}
	//XX XX visualizza la griglia del giocatore
	if(input1 == "XX" && input2 == "XX"){
		std::cout<<b1<<std::endl<<std::endl;
		return true;
	}
	return false;
}