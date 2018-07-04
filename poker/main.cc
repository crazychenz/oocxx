#include "PokerMachine.h"
#include "PokerUI.h"
int main()
{
    PokerMachine machine = PokerMachine();
    PokerUI(&machine).main_menu();
    return 0;
}

