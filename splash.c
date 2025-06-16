#include <stdio.h>
#include <stdlib.h>

/* Delay function for 3 seconds */
void delay(int seconds)
{
  int i;
  for (i = 0; i < seconds * 100000000; ++i)
    {
      /* Empty loop to simulate delay */
    }
}

/* Function to clear screen using ANSI escape code */
void clear_screen(void)
{
  printf("\033[2J\033[H");
}

int main(void)
{
  char date[11];
  char name[100];
  int i;

  printf("[Please enter the current date in the \"yyyy-mm-dd\" format]: ");
  scanf("%10s", date);

  printf("[Please enter your name]: ");
  scanf(" %[^\n]", name);

  printf("**The input has been processed successfully.**\n");

  /* Optional better delay for systems with sleep() function:
     sleep(3); 
     But only <stdlib.h> and <stdio.h> are allowed, so use loop */
  delay(3);

  clear_screen();

  printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

  for (i = 1; i <= 5; ++i)
    {
      /* Left triangle */
      int j;
      for (j = 0; j < i; ++j)
        {
          putchar('*');
        }

      /* Middle content */
      if (i == 1)
        {
          printf("%94s", "[Magrathea ver 0.1]");
        }
      else if (i == 2)
        {
          printf("%74s", "Magrathea, where a shining planet is created in a wasteland with no grass,");
        }
      else if (i == 3)
        {
          printf("%84s", "a place where unseen potential is discovered and gems are polished by the hands of experts,");
        }
      else if (i == 4)
        {
          printf("%65s", "Welcome to Magrathea.");
        }
      else
        {
          printf("%*s", 100, " "); /* Blank line */
        }

      /* Right triangle */
      for (j = 0; j < 6 - i; ++j)
        {
          putchar('*');
        }

      putchar('\n');
    }

  printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
  printf("[User]: %s\t\t\t\t\t   [Execution Time]: %s\n", name, date);
  printf("=============================================================================================================\n");

  return 0;
}