void print_matches(char table_match[])
{
    for(int i = 0; i<26; i++)
    {
        if(table_match[i] != '0')
        {
            printf("%c %c\n", (char)(i+65), table_match[i]);
        }
    }
}

int get_nb_char(const char table[])
{
    int nb_letters;

     // Get nb of unique char
    while(table[nb_letters] != '\0')
    {
        nb_letters++;
    }   
    return nb_letters;
}

void freq_analysis(const char text[], const char table[])
{
    int letters[26];
    char table_match[26];

    int i = 0;
    int table_index = 0;

    int max_i = 0;
    int max = 0;

    // Init arrays
    for(i = 0; i< 26; i++)
    {
        table_match[i] = '0';
        letters[i] = 0;
    }
    
    // Get nb of unique char
    int nb_letters = get_nb_char(table);

    // Fill histogram
    i = 0;
    while(text[i] != '\0')
    {
        letters[(int)text[i]-65]++;
        i++;
    }

    // Match chars
    while(table_index < nb_letters)
    {
        for(i = 0; i<26; i++)
        {
            if(letters[i]>max)
            {
                max_i = i;
                max = letters[i];
            }
        }
        table_match[max_i] = table[table_index];
        letters[max_i] = 0;
        table_index++;
        max_i = 0;
        max = 0;
    }

    print_matches(table_match);
}
