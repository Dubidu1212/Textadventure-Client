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
	cout << "1"<< endl;
	string Name;
	cout << "2"<< endl;
	ifstream file;
	cout << "3"<< endl;
	//int y = 0;
	bool running = true;
	cout << "4"<< endl;
	file.open("StoryTest.txt");
	if(!file.is_open()){
		cerr << "file could not be opened!" << endl;
		return 0;
	}
	cout << "5" << endl;
	string endzeichen = "§";
	vector<Situation> sit;
	string temp;
	getline(file,Name);
	cout << "6" << endl;

	while(getline(file,temp)){
		if(temp != "---"){
			cout << "break"<< endl;
			break;
		}
		cout << "no break"<< endl;
		Situation item;
		getline(file,item.id);
		cout << "7"<< endl;
		getline(file,tempStr);
		cout << "8"<< endl;
		item.beschrieb.reserve(1);
		item.beschrieb[0] = tempStr;
		cout << "9"<< endl;
		item.beschrieb.push_back(tempStr);
		cout << "10"<< endl;
		int runde = 0;
		cout << "11"<< endl;
		while(getline(file,temp)){
			if(temp  == "!!!"){
				getline(file,tempStr);
				cout << "ge!!!"<< endl;
				item.beschrieb[runde] = tempStr;
				item.beschrieb.push_back(tempStr);
				runde ++;
				getline(file,temp);
			}
			else{
				cout << "continued"<< endl;
				break;

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
				if (sit[x].art == 0){//frage und situation
					for(int y = 0; y < sit[y].beschrieb.size(); y++){
						cout << sit[y].beschrieb[y] << endl;
					}
					for(int z = 0; z < sit[z].beschrieb.size(); z++){
						cout << sit[x].frage[z] << endl;
					}


				}

				if(sit[x].art == 1){//nur Situation




				}
				if(sit[x].art == 2){//Medien




				}
				if(sit[x].art == 3){//Gameplay




				}
				if(sit[x].art == 4){//Auswahl nach gefühlen



				}
				if(sit[x].art == 5){//Auswahl nach gefühlen (gezwungen)


				}
			}
	}


	cout << "ende" << endl;


	return 0;
}
