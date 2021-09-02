#include <iostream>
#include <Windows.h>
#include "ViborResult.h"
#include "Interface.h"


using namespace std;





int main()
{
	setlocale(LC_ALL, "russian");
label:

	Interface Interface;
	Interface.Menu();
	ViborResult VR;
	VR.setVibor(Interface.n);
	VR.Result();

	
	goto label;
	
	
	return 0;
}