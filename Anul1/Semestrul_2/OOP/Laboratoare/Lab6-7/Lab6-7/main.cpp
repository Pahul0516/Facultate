#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include <crtdbg.h>
#include "teste.h"
#include "ui.h"

void start()
{
	ui ui;
	ui.run();
}

int main()
{
	start();
	rulare_teste(); 
	_CrtDumpMemoryLeaks();
	return 0;
}