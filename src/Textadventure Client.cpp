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
	// von hier bis
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
//bis hier


	//auslesen

	while(running){

			for(int x=0; x< sit.size();x++){
				//abfragen welche art
				if (sit.art == 0){//frage und situation




				}
				if(sit.art == 1){//nur Situation




				}
				if(sit.art == 2){//Medien




				}
				if(sit.art == 3){//Gameplay




				}
			}
	}


	cout << "ende" << endl;


	return 0;
}
