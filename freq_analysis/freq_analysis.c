#include<stdio.h>
#include<string.h>

#define HISTO_SIZE 256

void freq_analysis(const char text[], const char table[])
{
    int nb_unique_char = strlen(table);
    int nb_char_in_txt = strlen(text);
    int i;
    int histo[HISTO_SIZE];
    
    for(i = 0; i<HISTO_SIZE; i++)
    {
        histo[i] = 0;
    }

    for(i = 0; i<nb_char_in_txt; i++)
    {
        histo[(int)text[i]]+=1;
    }

    int i_table = 0;
    int j;
    int max = 0;
    int max_i = 0;

    for(i = 0; i<nb_unique_char; i++)
    {
        //search mor max occurence
        for(j = 0; j<256; j++)
        {
            if(histo[j]>histo[max_i])
            {
                max_i = j;
            }
        }

        printf("%c %c\n", max_i, table[i]);
        histo[max_i] = 0;
        max_i = 0;
    }
}


int main()
{
    freq_analysis("ABBCCCDDDD", "ABCD");
    printf("\n\n");
    freq_analysis("FXOWFFOWOFF", "ABCD");
}

