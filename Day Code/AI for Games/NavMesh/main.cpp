#include "NavMeshApp.h"

int main() {
	
	auto app = new NavMeshApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}