char polybious_alphabet[6][5] = {
    {'a', 'b', 'c', 'd', 'e'},
    {'f', 'g', 'h', 'i', 'j'},
    {'k', 'l', 'm', 'n', 'o'},
    {'p', 'q', 'r', 's', 't'},
    {'u', 'v', 'w', 'x', 'y'},
    {'z'}
};

char * polybyius_encrypt(char * text){
    char * res = (char *) malloc(1000 * sizeof(char));
    for(int i = 0, l = 0; i <= strlen(text); i++, l+=2){
        for(int k = 0; k < 6; k++){
            for(int j = 0; j < 5; j++){
                if(text[i] == polybious_alphabet[k][j]){
                    res[l] = k+1 + '0';
                    res[l+1] = j+1 + '0';
                }
            }
        }
    }
    return res;
};


char * polybyius_decrypt(char * text){    char * res = (char *) malloc(1000 * sizeof(char));
    for(int i = 0, l = 0; i < strlen(text); i+=2, l++){
        int k = text[i] - 1 - '0';
        int j = text[i+1] - 1 - '0';
        res[l] = polybious_alphabet[k][j];
    }
    return res;
}