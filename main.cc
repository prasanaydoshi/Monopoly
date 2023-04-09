#include "Model.h"
#include "View.h"
#include "Controller.h"

int main() {
	Model model;
	View view;
	Controller controller(model, view);

	controller.run();

	return 0;
}
