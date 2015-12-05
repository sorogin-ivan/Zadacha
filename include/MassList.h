#ifndef __MASSLIST__
#define __MASSLIST__

#include <iostream>

using namespace std;

typedef int VT;

class MassList{

private:
	int maxsize;
	VT* data;
	int* nextRefs;

public:

MassList(int);
~MassList();
void Print();
int Find(VT);
void PushEnd(VT);
void PushAfter(VT, VT);
void Delete(VT);
void Swap();
void Push(VT);
int MaxElem();
};


#endif