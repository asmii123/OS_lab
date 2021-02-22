/*Producer Consumer Problem*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void
main ()
{
  int buffer[10], buffsize, in, out, produce, consume, choice = 0;
  in = 0;
  out = 0;
  printf ("Enter Buffer size: ");
  scanf ("%d", &buffsize);
  while (choice != 3)
    {
      printf ("\n1. Produce\t 2. Consume \t3. Exit");
      printf ("\nEnter your choice:=");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  if ((in + 1) % buffsize == out)
	    printf ("\nBuffer is Full");
	  else
	    {
	      printf ("\nEnter the value: ");
	      scanf ("%d", &produce);
	      buffer[in] = produce;
	      in = (in + 1) % buffsize;
	    }
	  break;
	case 2:
	  if (in == out)
	    printf ("\nBuffer is Empty");
	  else
	    {
	      consume = buffer[out];
	      printf ("\nThe consumed value is %d", consume);
	      out = (out + 1) % buffsize;
	    }
	  break;
	}
    }
}
