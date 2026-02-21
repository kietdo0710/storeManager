#include <unistd.h>
#include "ui.hpp"

using namespace std;

Ui::Ui()
{
	Ui::start();
}

Ui::~Ui()
{
	Ui::stop();
}


int Ui::start()
{
	// thread t1(&Ui::refresh, this);
	// t1.detach();
	return 0;
}

int Ui::stop()
{
	// t1.join();
	return 0;
}

void Ui::refresh()
{
}