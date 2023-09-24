#include "Application.h"

int main()
{
	Application application;

	while (application.isRunning())
	{
		application.run();
	}

	return 0;
}

/*
		TODO:
		
*/