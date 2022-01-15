#include "SaveHelper.h"

bool SaveHelper::SaveData(Player* p) {
	// File open area as default txt properties
	this->ofs.open(this->filepath);
	if (ofs.fail())					// If file open failed return false
		return false;

	// A function for saving data
	ofs << p->GetMoneyInfo() << std::endl;				// Save Money data
	ofs << p->GetwinCount() << std::endl;					// Save Wincount data
	ofs << p->GetlossCount() << std::endl;					// Save losscount data

	// File close
	ofs.close();

	return true;
}

bool SaveHelper::LoadData(Player* p) {
	long long _tm;					// temp money
	int _tw;						// temp wincount
	int _tl;						// temp losscount

	// File open area
	this->ifs.open(this->filepath);
	if (ifs.fail())					// If file open failed return false
		return false;

	// A function for loading data
	ifs >> _tm;
	ifs >> _tw;
	ifs >> _tl;

	p->SetMoneyInfo(_tm);
	p->SetwinCount(_tw);
	p->SetlossCount(_tl);

	// File close
	ifs.close();

	return true;
}