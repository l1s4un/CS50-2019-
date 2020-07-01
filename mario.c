/*
Toward the end of World 1-1 in Nintendo’s Super Mario Brothers, Mario must ascend right-aligned pyramid of blocks, a la the below.

screenshot of Mario jumping up a right-aligned pyramid

Let’s recreate that pyramid in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramid itself is also be taller than it is wide.

       #
      ##
     ###
    ####
   #####
  ######
 #######
########
The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramid should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:

$ ./mario
Height: 8
       #
      ##
     ###
    ####
   #####
  ######
 #######
########
Here’s how the program might work if the user inputs 4 when prompted:

$ ./mario
Height: 4
   #
  ##
 ###
####
Here’s how the program might work if the user inputs 2 when prompted:

$ ./mario
Height: 2
 #
##
And here’s how the program might work if the user inputs 1 when prompted:

$ ./mario
Height: 1
#
If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #
  ##
 ###
####
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
        printf("%s\n", str);
           /* char temp_str[height];
            temp_str[0] = '\0';
            size_t str_len = strlen(str);      
            for (int e = str_len-1; e >=0; e--)
            {
                strcat(temp_str, &str[e]);
            }
            char res_str[2*height +1];
            res_str[0] = '\0';
            memset(res_str, '\0', sizeof res_str);
            strcat(res_str, str);
            strcat(res_str, space);
            strcat(res_str, space);
            strcat(res_str, temp_str);

            printf("%s\n", res_str);*/
    }
}