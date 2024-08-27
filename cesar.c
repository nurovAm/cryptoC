int cesarCheckKey(int key){
    if (key > 0 && key < strlen(alphabet)){
        return 1;
    }
    else{
        return 0;
    }
}

char * cesarEncrypt(char * text, int key){
    if (cesarCheckKey(key) == 0){
        return "is nothing. Wrong key!\n";
    }
    char * ans = (char *) malloc(1000 * sizeof(char));
    for(int i = 0; i < strlen(text) - 1; i++){
        char * let_find = strchr(alphabet, text[i]);
        int let_index = let_find - alphabet;
        ans[i] = alphabet[(let_index + key) % strlen(alphabet)];
    }
    return ans;
}


char * cesarDecrypt(char * text, int key){
    if (cesarCheckKey(key) == 0){
        return "is nothing. Wrong key!\n";
    }
    char * ans = (char *) malloc(1000 * sizeof(char));
    for(int i = 0; i < strlen(text) - 1; i++){
        char * let_find = strchr(alphabet, text[i]);
        int let_index = let_find - alphabet;
        if(let_index - key >= 0){
            ans[i] = alphabet[(let_index - key) % strlen(alphabet)];
        }else{
            ans[i] = alphabet[(let_index - key) + strlen(alphabet)];
        }
    }
    return ans;
}

