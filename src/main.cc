#include "platform/ibm-pc/console.hh"

#define ever (;;)

void main()
{
  ibm_pc::Console c;

  c << "[Core] Starting kernel...\n";

  for ever;
}
