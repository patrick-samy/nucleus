#include "config.hh"
//#include "arch/ia-32/ibm-pc/console.hh"

#define ever (;;)

void __cxa_pure_virtual()
{
  for ever;
}

void main()
{
  //platform::Console c;

  //c << "[Atom] Starting kernel...\n";
  char *ptr = (char *)0xb8000;

  for (int i = 0; i < 80 * 25; i += 2)
	ptr[i] = 0;

  ptr[0] = 'A';
  ptr[2] = 't';
  ptr[4] = 'o';
  ptr[6] = 'm';

  for ever;
}
