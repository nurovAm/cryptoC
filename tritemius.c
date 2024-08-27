char* tritemius_encrypt(const char *text) {
    char * res = malloc(1000 * sizeof(char));
    for (int i = 0; i < strlen(text)-1; i++){
        char * let_find = strchr(alphabet, text[i]);
        int let_index = let_find - alphabet;
        res[i] = alphabet[(i + let_index) % strlen(alphabet)];
    }
    return res;
}

char* tritemius_decrypt(const char *text) {
    char * res = malloc(1000 * sizeof(char));
    for (int i = 0; i < strlen(text)-1; i++){
        char * let_find = strchr(alphabet, text[i]);
        int let_index = let_find - alphabet;
        if(let_index - i >= 0){
            res[i] = alphabet[(let_index - i) % strlen(alphabet)];
        }else{
            res[i] = alphabet[(let_index - i) + strlen(alphabet)];
        }
    }
    return res;
}