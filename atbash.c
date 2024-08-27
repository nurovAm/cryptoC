char * atbashEncrypt(char * text){
    char * ans = (char *) malloc(1000 * sizeof(char));
    for (int i = 0; i < strlen(text)-1; i++){
        char * let_ptr = strchr(alphabet, text[i]);
        if (let_ptr != NULL) {
            int let_position = let_ptr - alphabet;
            int new_let = strlen(alphabet) - let_position - 1;
            ans[i] = alphabet[new_let];
        } else {
            ans[i] = text[i]; // keep non-alphabetic characters unchanged
        }
    }
    return ans;
}

char * atbashDecrypt(char * text){
    char * ans = (char *) malloc(1000 * sizeof(char));
    for (int i = 0; i < strlen(text)-1; i++){
        char * let_ptr = strchr(alphabet, text[i]);
        if (let_ptr != NULL) {
            int let_position = let_ptr - alphabet;
            int new_let = strlen(alphabet) - let_position - 1;
            ans[i] = alphabet[new_let];
        } else {
            ans[i] = text[i]; // keep non-alphabetic characters unchanged
        }
    }
    return ans;
}