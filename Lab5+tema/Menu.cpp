#include "repo.h"
#include "Ctrl.h"
#include "Ui.h" 
#include <cstring>
#include "Test.h"
using namespace std;



int main()
{
	Repo repo = Repo();
	Ctrl ctrl = Ctrl(repo);
	Ui ui = Ui(ctrl);
	ui.run();
	testBanca();
	testRepo();
	testCtrl();
	return 0;
}