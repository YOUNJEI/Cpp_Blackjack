#ifndef __SAVEHELPER_H__
#define __SAVEHELPER_H__
#include <fstream>
#include "Player.h"
using namespace std;

class SaveHelper {
private:
	string filepath;
	ifstream ifs;
	ofstream ofs;

public:
	SaveHelper(string s) { this->filepath = s; }
	bool SaveData(Player* p);
	bool LoadData(Player* p);
};

#endif