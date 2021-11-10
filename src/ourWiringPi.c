#include <wiringPi.h>
#include "ebentoak.h"

void wiringPiHasieratu() {
	wiringPiSetup ();
	   pullUpDnControl(TEKLA1, PUD_DOWN);
	   pullUpDnControl(TEKLA2, PUD_DOWN);
	   pullUpDnControl(TEKLA3, PUD_DOWN);
	   pullUpDnControl(TEKLA4, PUD_DOWN);
	   pullUpDnControl(TEKLA5, PUD_DOWN);
	   pullUpDnControl(TEKLA6, PUD_DOWN);
	   pullUpDnControl(TEKLA7, PUD_DOWN);
	   pullUpDnControl(TEKLA8, PUD_DOWN);
	   pullUpDnControl(TEKLA9, PUD_DOWN );
	   pullUpDnControl(TEKLA10, PUD_DOWN);
	   pullUpDnControl(TEKLA11, PUD_DOWN);
	   pullUpDnControl(TEKLA12, PUD_DOWN);
	   pullUpDnControl(TEKLA13, PUD_DOWN);
	   pullUpDnControl(TEKLA14, PUD_DOWN);
	   pullUpDnControl(TEKLA15, PUD_DOWN);
	   pullUpDnControl(TEKLA16, PUD_DOWN);
	   pullUpDnControl(TEKLA17, PUD_DOWN);
	   pullUpDnControl(TEKLA18, PUD_DOWN);
	   pullUpDnControl(TEKLA19, PUD_DOWN);
	   pullUpDnControl(TEKLA20, PUD_DOWN);
	   pullUpDnControl(TEKLA21, PUD_DOWN);
	   pullUpDnControl(TEKLA22, PUD_DOWN);
	   pullUpDnControl(TEKLA23, PUD_DOWN);
	   pullUpDnControl(TEKLA24, PUD_DOWN);
	   pullUpDnControl(TEKLA25, PUD_DOWN);

	   pinMode (TEKLA1, INPUT);
	   pinMode (TEKLA2, INPUT);
	   pinMode (TEKLA3, INPUT);
	   pinMode (TEKLA4, INPUT);
	   pinMode (TEKLA5, INPUT);
	   pinMode (TEKLA6, INPUT);
	   pinMode (TEKLA7, INPUT);
	   pinMode (TEKLA8, INPUT);
	   pinMode (TEKLA9, INPUT);
	   pinMode (TEKLA10, INPUT);
	   pinMode (TEKLA11, INPUT);
	   pinMode (TEKLA12, INPUT);
	   pinMode (TEKLA13, INPUT);
	   pinMode (TEKLA14, INPUT);
	   pinMode (TEKLA15, INPUT);
	   pinMode (TEKLA16, INPUT);
	   pinMode (TEKLA17, INPUT);
	   pinMode (TEKLA18, INPUT);
	   pinMode (TEKLA19, INPUT);
	   pinMode (TEKLA20, INPUT);
	   pinMode (TEKLA21, INPUT);
	   pinMode (TEKLA22, INPUT);
	   pinMode (TEKLA23, INPUT);
	   pinMode (TEKLA24, INPUT);
	   pinMode (TEKLA25, INPUT);
}
