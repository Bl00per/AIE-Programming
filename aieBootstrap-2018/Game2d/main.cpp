#include "Game2dApp.h"

int main() {
	
	// allocation
	auto app = new Game2dApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}