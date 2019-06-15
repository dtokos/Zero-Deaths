#include "Application.hpp"
#include "ApplicationFactory.hpp"

int main(int argc, const char* argv[]) {
	ApplicationFactory appFactory;
	Application app = appFactory.make();
	app.run();

	return 0;
}
