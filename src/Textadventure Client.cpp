#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <sstream>

using namespace std;

struct Situation{
	string id;
	vector <string> beschrieb;
	vector <string> frage;
	vector <string> ids;
	int art;

};



int main() {
	cout << "gestartet"<< endl;
	string tempStr;
	string Name;
	ifstream file;
	//int y = 0;
	bool running = true;
	file.open("StoryEthan.txt");
	if(!file.is_open()){
		cout << "file could not be opened!";
		return 0;
	}
	/*
	vector<Situation> sit;
	string temp;
	while(getline(file,temp)){
		if(temp != "---"){
			break;

		}
		Situation item;
		getline(file,item.id);
		getline(file,item.beschrieb);
		getline(file,item.frage);
		getline(file,item.next_id_ja);
		getline(file,item.next_id_nein);
		sit.push_back (item);

	}*/
	string endzeichen = "§";
	vector<Situation> sit;
	string temp;
	getline(file,Name);
	while(getline(file,temp)){
		if(temp != "---"){
			break;
		}
		Situation item;
		getline(file,item.id);



		getline(file,tempStr);
		item.beschrieb[0] = tempStr;
		item.beschrieb.push_back(tempStr);
		int runde = 1;
		while(getline(file,temp)){
			if(temp  == "!!!"){
				getline(file,tempStr);
							item.beschrieb[runde] = tempStr;
							item.beschrieb.push_back(tempStr);
							runde ++;
			}
			else{
				continue;
			}

		}
		item.beschrieb[runde] = endzeichen;
		item.beschrieb.push_back(endzeichen);

		//bei frage position eintagen
		// vieleicht über temporärer string


		getline(file,tempStr);
				item.frage[0] = tempStr;
				item.frage.push_back(tempStr);
				runde = 1;
				while(getline(file,temp)){
					if(temp  == "!!!"){
						getline(file,tempStr);
									item.frage[runde] = tempStr;
									item.frage.push_back(tempStr);
									runde ++;
					}
					else{
						continue;
					}

				}
				item.frage[runde] = endzeichen;
				item.frage.push_back(endzeichen);



				getline(file,tempStr);
						item.ids[0] = tempStr;
						item.ids.push_back(tempStr);
						runde = 1;
						while(getline(file,temp)){
							if(temp  == "!!!"){
								getline(file,tempStr);
								item.ids[runde] = tempStr;
								item.ids.push_back(tempStr);
								runde ++;
							}
							else{
								continue;
							}
						}
						item.ids[runde] = endzeichen;
						item.ids.push_back(endzeichen);

						getline(file,tempStr);

						stringstream ss;
						ss.str (tempStr);
						ss >> item.art;

						sit.push_back(item);
	}




	//hier startet das richtige spiel
/*
		cout << Name << endl;
		int w = 1000;
		this_thread::sleep_for(std::chrono::milliseconds(w));
	string tempId = "1";
	while(running){

		for(int x=0; x< sit.size();x++){

		if(sit[x].id == tempId){
			string exitvalues = "9";
			if(exitvalues == sit[x].next_id_ja ){
				running = false;
			}
			if(exitvalues == sit[x].next_id_nein){
				running = false;
			}
			if(tempId == "5"){
				cout << endl << endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "Ende Kapitel I" << endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << endl << endl;
			}
			if (tempId == "5.1.1.1"||tempId == "5.1.1.5"||tempId == "5.1.5.1"||tempId == "5.1.5.5"||tempId == "5.5.5.5"||tempId == "5.5.1.5"||tempId == "5.5.1.1"){
				cout << sit[x].beschrieb<< endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << endl << endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << endl << endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << endl << endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				tempId =  "0"; //dort wo es weitergeht
				continue;
			}
			if(tempId =="5.5.5.1"){
				cout << "Chatverlauf:"<<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "E: Ethan, F: Freund"<<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "E: Ey ich verschwinde. Frau hat mit mir Schluss gemacht und fang jetzt ein neues Leben an."<<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "F: Oh scheisse. Aber wir bleiben in Kontakt klar?"<<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "E: Klar sicher. Noch letzte Worte?  "<<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "F: das heisst also du siehst deine Tochter auch nicht? "<<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "E: No shit Sherlock. Ehrlich du weisst wie meine Ex-Frau tickt." <<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "F: Hmm…naja dann tschüss. Bis irgendwann dann mal."<<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "Genervt verdrehst du deine Augen und fährst zum Bahnhof."<< endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				tempId =  "0";
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << endl << endl;

				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << endl << endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << endl << endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				continue;
			}
			if(tempId == "0"){
				cout << "*Egal wie schlecht es dir Geht"<<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << "irgendwann geht es wieder besser*" <<endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				cout << endl<<endl<<"ENDE"<< endl;
				return 0;
			}
			cout << "..." << endl;
			this_thread::sleep_for(std::chrono::milliseconds(w));
			cout << "..." << endl;
			this_thread::sleep_for(std::chrono::milliseconds(w));
			cout << "..." << endl;
			this_thread::sleep_for(std::chrono::milliseconds(w));
			cout << sit[x].beschrieb << endl;
			this_thread::sleep_for(std::chrono::milliseconds(w));
			cout << sit[x].frage << endl;
			this_thread::sleep_for(std::chrono::milliseconds(w));
			cout << "für JA drücke J" << endl << "für NEIN drücke N" << endl;
			this_thread::sleep_for(std::chrono::milliseconds(w));
			char temp;
			cin >> temp;
			if(temp == 'J' || temp == 'j'){
				tempId = sit[x].next_id_ja;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				continue;
			}
			else if(temp == 'N' || temp == 'n'){
				tempId = sit[x].next_id_nein;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				continue;

			}
			else{
				cout << "Du hast etwas falsches eingegeben" << endl;
				this_thread::sleep_for(std::chrono::milliseconds(w));
				x=x - 1;
				y++;
				if(y > 4){
					cout << "Wat laberst du denn da?" << endl;
					this_thread::sleep_for(std::chrono::milliseconds(w));
				}

			}

		}
	}

	}
*/
	cout << "ende";


	return 0;
}
