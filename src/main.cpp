#include "Application/Application.hpp"
#include "Application/ApplicationFactory.hpp"

int main(int argc, const char* argv[]) {
	ApplicationFactory appFactory;
	Application app = appFactory.make();
	app.run();

	return 0;
}
