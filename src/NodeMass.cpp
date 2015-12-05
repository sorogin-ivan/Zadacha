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

	if (data[i]==key){

return i;
break;
	}


	i=nextRefs[i];
}

}


void MassList:: PushEnd(VT key){

int k=-1;
int m=nextRefs[0];

for (int i=2; i<maxsize; i++)

	if (nextRefs[i]==1){
	
		
		k=i;
	
		break;	
	
	}


if (k==-1)

	throw ("not enough memory");


while(nextRefs[m]!=0)

	m=nextRefs[m];

data[k]=key;

nextRefs[k]=0;

nextRefs[m]=k;

}




void MassList::PushAfter(VT Pkey, VT key){

	int idx=Find(key);
	int k=-1;

	if (idx==-1)
		throw("element not found");

	for (int i=2; i<maxsize; i++)

	if (nextRefs[i]==1){
	
		
		k=i;
	
		break;	
	
	}

	if (k==-1)

	throw ("not enough memory");

	nextRefs[k]=nextRefs[idx];
	
	nextRefs[idx]=k;

	data[k]=key;
	

}


void MassList::Delete(VT key){

int k = nextRefs[0];

while ((nextRefs[k]!=0)&&(data[nextRefs[k]]!=key))

	k=nextRefs[k];

if (data[nextRefs[k]]!=key)

	throw("element not found");


nextRefs[nextRefs[k]]=1;

nextRefs[k]=nextRefs[nextRefs[k]];

}


void MassList::Swap(void){

 int k=nextRefs[0];
 int m;
 while (nextRefs[k]!=0)

	 k=nextRefs[k];


 m=nextRefs[0];

 nextRefs[0]=nextRefs[k];

 nextRefs[k]=nextRefs[m];


}

void MassList::Push(VT key){

	int k=nextRefs[0];
	int m=nextRefs[0];

	for (int i=2; i<maxsize; i++)

	if (nextRefs[i]==1){
	
		
		k=i;
	
		break;	
	
	}

	if (k==-1)

	throw ("not enough memory");


	while ((nextRefs[m]!=0)&&(key>data[nextRefs[nextRefs[m]]]))

		m=nextRefs[m];



	nextRefs[k]=nextRefs[m];

	nextRefs[m]=k;

	data[k]=key;

}



int MassList::MaxElem(void){

	int k=nextRefs[0], maxidx=0;
	VT max=data[nextRefs[0]];

	while (nextRefs[k]!=0){
	
		if(max<data[nextRefs[k]]){

		max=data[nextRefs[k]];
		
		maxidx=nextRefs[k];
		
		}
		
    k=nextRefs[k];
		
	
	
	}

	return maxidx;

}