#include <stdio.h>
#include <string.h>
#include <ctype.h>  

int main()
{
    char plain[100], cipher[100];
    char key[] = "qwertyuiopasdfghjklzxcvbnm9876543210"; 
    int i, j, len;
    if (strlen(key) != 36)
    {
        printf("Invalid key length. The key must be 36 characters long.\n");
        return 1;
    }

    printf("Enter the plain text: ");
    fgets(plain, sizeof(plain), stdin);

    len = strlen(plain);
    for (i = 0; i < len; i++)
    {
        if (isalpha(plain[i]))
        {
            char base = islower(plain[i]) ? 'a' : 'A';
            j = toupper(plain[i]) - 'A';
            if (j >= 0 && j < 26)
            {
                cipher[i] = key[j];
            }
            else
            {
                cipher[i] = plain[i];
            }
        }
        else if (isdigit(plain[i]))
        {
            j = plain[i] - '0';

            if (j >= 0 && j < 10)
            {
                cipher[i] = key[26 + j];
            }
            else
            {
                cipher[i] = plain[i];
            }
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    cipher[len] = '\0'; 
    printf("The cipher text is: %s", cipher);

    return 0;
}
