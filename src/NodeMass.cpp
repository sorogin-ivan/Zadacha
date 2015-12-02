#include "MassList.h"

MassList::MassList(int maxsize){

	data=new VT [maxsize+2];
	nextRefs=new int [maxsize+2];
	for(int i=2; i<maxsize;i++)

		nextRefs[i]=1;
	
	nextRefs[0]=0;

	nextRefs[1]=-1;

}



MassList::~MassList(){

	delete[]data;
	delete[]nextRefs;


}


void MassList::Print(void){

int i=nextRefs[0];

while (i!=0){
	cout <<data[i]<< "/t";

i=nextRefs[i];
}
cout <<endl ;
}



int MassList:: Find( VT key){

int i=nextRefs[0];

while (i!=0){

	if (data[i]==key);{

return i;
break;
	}


	i=nextRefs[i];
}

}

