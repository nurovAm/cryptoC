int is_valid_key(char *key) {
    while (*key) {
        if (!strchr(alphabet, *key)) {
            return 0; // Найден не буквенный символ в ключе
        }
        key++;
    }
    return 1; // Весь ключ состоит из букв
}

char * vizener_encrypt(char * text, char * key){
    if (is_valid_key(key) == 1){
        char * res = malloc(1000*sizeof(char));
        int num_key = strlen(key) - 1;
        for(int i = 0; i < strlen(text) - 1; i++){
            char * let_find = strchr(alphabet, text[i]);
            int let_index = let_find - alphabet;
            char * key_find = strchr(alphabet, key[i % num_key]);
            int key_index = key_find - alphabet;
            res[i] = alphabet[(let_index + key_index) % strlen(alphabet)];
        }
        return res;
    }
    return "Wrong key\n";
}

char * vizener_decrypt(char * text, char * key){
    if (is_valid_key(key) == 1){
        char * res = malloc(1000*sizeof(char));
        int num_key = strlen(key) - 1;
        for(int i = 0; i < strlen(text) - 1; i++){
            char * let_find = strchr(alphabet, text[i]);
            int let_index = let_find - alphabet;
            char * key_find = strchr(alphabet, key[i % num_key]);
            int key_index = key_find - alphabet;
            if(let_index - key_index >= 0){
                res[i] = alphabet[(let_index - key_index) % strlen(alphabet)];
            }else{
                res[i] = alphabet[(let_index - key_index) + strlen(alphabet)];
            }
        }
    return res;
    }
    return "Wrong key\n";
}
