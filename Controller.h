#include "Model.h"
#include "View.h"

class Controller {
	
public:

	// constructor used by main
	Controller(Model& model, View& view);	// constructor 
	// actual running program
	void run();				// main running functrion

private:
	Model& model;
	View& view;
};

