#define ever (;;);

int main()
{
  char* ptr = (char*)0xb8000;

  for (int i = 0; i < 80 * 125; ++i)
    ptr[i] = i;

  for ever;
}

