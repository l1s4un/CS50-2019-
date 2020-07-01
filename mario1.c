/*
oward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks, per the below.

screenshot of Mario jumping over adjacent pyramids

Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller than they are wide.

   #  #
  ##  ##
 ###  ###
####  ####
The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:

$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

Here’s how the program might work if the user inputs 4 when prompted:

$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
Here’s how the program might work if the user inputs 2 when prompted:

$ ./mario
Height: 2
 #  #
##  ##
And here’s how the program might work if the user inputs 1 when prompted:

$ ./mario
Height: 1
#  #
If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

Modify mario.c at right in such a way that it implements this program as described!
*/

#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    const char space[1] = " ";
    const char hash[1] = "#";
    int height = 0;

    while (height <= 0 || height > 8)
    {
         height = get_int("Height:");
    }
    char str[height+1];
    str[0] = '\0';
    for (int i = 0; i < height; i++)
    {
        memset(str, 0, sizeof(str));
        for (int j = 0; j < height; j++)
        {
            if (j + 1 >= height - i)
            {
                str[j] = hash[0];
            }
            else 
            {
                str[j] = space[0];
            }
        }
        printf("%s  ", str);
        for (int j = 0; j < height; j++)
        {
            if (j <= i)
            {
                str[j] = hash[0];
            }
            else 
            {
                str[j] = space[0];
            }
        }
        printf("%s\n", str);

    }
}