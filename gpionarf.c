#define _GNU_SOURCE
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "debugutil.h"


#define GPIO_PATH "/sys/class/gpio/"


/*New! now with static stack memmory allocation!:*/
#define FNAMEBUFFSZE (64)

int
set_gpio_toval (int gpionr, int val)
{
	char filename[FNAMEBUFFSZE];
	char tmp[FNAMEBUFFSZE];
	FILE *fh;

	debugf("Ill try to set [%d] ", gpionr);
	snprintf (filename,(FNAMEBUFFSZE-1),
			GPIO_PATH "gpio%d/value", gpionr);
	filename[FNAMEBUFFSZE-1] = 0;

	debugf(":  %s\n",filename);
	fh = fopen (filename, "w");
	if (fh == NULL)
	{
		if (!(fh = fopen (GPIO_PATH "/export", "w"))){
			debugf("Can't open export\n");
			return -1;
		}
		fprintf(fh, "%d\n", gpionr);
		fclose (fh);
		snprintf(tmp,(FNAMEBUFFSZE-1), 
			GPIO_PATH "gpio%d/direction", gpionr);
		tmp[FNAMEBUFFSZE-1] = 0;
		fh = fopen (tmp, "w");
		if (fh == NULL) {
			debugf("Can't change direction of pin %d\n", gpionr);
			return -1;
		}
		fprintf(fh, "out");
		fclose (fh);
		fh = fopen (filename, "w");
		if (fh == NULL ) {
			debugf("Can't open gpio-pin %d\n", gpionr);
			return -1;
		}
	}
	fprintf(fh, "%d\n", val);
	fclose (fh);
	return 0;
}


