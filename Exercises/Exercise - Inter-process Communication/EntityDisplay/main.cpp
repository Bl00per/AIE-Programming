#include "EntityDisplayApp.h"

#include <Windows.h>

int main() {
	
	auto app = new EntityDisplayApp(); 
	Sleep(1000);
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}