#pragma hdrstop
#include <iostream>

#include <fstream>
#include <string>
#include <Windows.h>
#include "ViborResult.h"
#include "Interface.h"





using namespace std;



int main()
{


	setlocale(LC_ALL, "russian");
	
label:
	Interface Interface;
	Interface.menu();
	ViborResult C;
	C.setVibor(Interface.n);
	C.Result();
	goto label;
	
	return 0;
}
