#include "Model.h"
#include "View.h"

class Controller {
	
public:
	Controller(Model& model, View& view);	// constructor 

	void run();				// main running functrion

private:
	Model& model;
	View& view;
};

