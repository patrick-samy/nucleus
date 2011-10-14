#include "platform/ibm-pc/console.hh"

#define ever (;;)

namespace ibm_pc
{
	Console cout;
}

void main()
{
	ibm_pc::cout << "Hello world !";	

	for ever;
}
