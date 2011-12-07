#include "config.hh"
#include "platform/ibm-pc/console.hh"

#define ever (;;)

void main()
{
  platform::Console c;

  c << "[Core] Starting kernel...\n";

  for ever;
}
