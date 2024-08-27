char * belazo_encrypt(char * text, char * key){
    char * res = malloc(1000 * sizeof(char));
    for(int i = 0; i < strlen(text) - 1; i++){
        char * let_find_text = strchr(alphabet, text[i]);
        char * let_find_key = strchr(alphabet, key[i % (strlen(key) - 1)]);
        int let_index_text = let_find_text - alphabet;
        int let_index_key = let_find_key - key;
        printf("%s \n", let_find_key);
    }
}

