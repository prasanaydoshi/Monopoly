#ifndef NONPURCHASE
#define NONPURCHASE
#include "Player.h"
class NonPurchase {
	Player *cur;
public:
	NonPurchase(Player *cur);
	void TuitionPay();
	void CoopFee();
	void OSAPcol();
	void TimsJail();
	void GoToJail();
	void SLC();
	void NH();
};

#endif
