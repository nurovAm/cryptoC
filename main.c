char * alphabet = "abcdefghijklmnopqrstuvwxyz";
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> 
#include "atbash.c"
#include "cesar.c"
#include "polybious.c"
#include "tritemius.c"
#include "belazo.c"
#include "vizener.c"
#include "matrix.c"


#define ATBASH 1
#define CESAR 2
#define POLYBIOUS 3
#define TRITEMIUS 4
#define BELAZO 5
#define VIZENER 6
#define MATRIX 7
#define QUIT 0






void readtext(char *text){
    printf("Enter your text!\n");
    fgets(text, 1000, stdin);
}

void readkey(char *key_text){
    printf("Enter your key!\n");
    fgets(key_text, 1000, stdin);
}

char * formattext(char * text){
    char * new_text = (char *) malloc(1000 * sizeof(char));
    for(int i = 0, j = 0; i < strlen(text); i++){
        if(text[i] == ' ')
        {
            new_text[j++] = 'p';
            new_text[j++]= 'r';
            new_text[j++]= 'b';
        }else if (text[i] == ',')
        {
            new_text[j++] = 'z';
            new_text[j++]= 'p';
            new_text[j++]= 't';
        }else if (text[i] == '.')
        {
            new_text[j++] = 't';
            new_text[j++]= 'c';
            new_text[j++]= 'k';
        }
        else
        {
            if(text[i]>='A' && text[i]<='Z'){
                new_text[j] = text[i] - 'A' + 'a';
            }
            else{
                new_text[j] += text[i];
            }
            j+=1;
        }
    }
    return new_text;
}

char * unformattext(char * text){
    char * new_text = (char *) malloc(1000 * sizeof(char));
    for (int i = 0, j = 0; i < strlen(text); j++){
        if(text[i] == 'p' && text[i+1] == 'r' && text[i+2]=='b')
        {
            new_text[j] = ' ';
            i+=3;
        }
        else if (text[i] == 't' && text[i+1] == 'c' && text[i+2]=='k')
        {
            new_text[j] = '.';
            i+=3;
        }
        else if (text[i] == 'z' && text[i+1] == 'p' && text[i+2]=='t')
        {
            new_text[j] = ',';
            i+=3;
        }
        else{
            new_text[j] = text[i];
            i+=1;
        }
    }

    return new_text;
}

int main(){
    bool fl = true;
    while(fl == true){
        int mode;
        printf("Choose the mode\n"
        "1. Encrypt\n"
        "2. Decrypt\n");
        scanf("%d", &mode);
        printf("Choose the cipher\n"
        "1. Atbash\n"
        "2. Cesar\n"
        "3. Polybious\n"
        "4. Tritemius\n"
        "6. Vizener\n"
        "To quit enter 0\n");
        int choose;
        scanf("%d", &choose);
        getchar();
        char text[1000];
        char key_text[1000];
        char * new_text;
        
        if(mode == 1){   
            char* enc_text;
            switch (choose)
            {
            case ATBASH:
                readtext(text);
                new_text = formattext(text);
                enc_text = atbashEncrypt(new_text);
                printf("Encrypt text %s\n", enc_text);
                break;
            case CESAR:
                readtext(text);
                int key; 
                printf("Enter your key\n");
                scanf("%d", &key);
                new_text = formattext(text);
                enc_text = cesarEncrypt(new_text, key);
                printf("Encrypt text %s\n", enc_text);
                break;
            case POLYBIOUS:
                readtext(text);
                new_text = formattext(text);
                printf("%s\n", new_text);
                enc_text = polybyius_encrypt(new_text);
                printf("Encrypt text %s\n", enc_text);
                break;
            case TRITEMIUS:
                readtext(text);
                new_text = formattext(text);
                printf("%s", new_text);
                enc_text = tritemius_encrypt(new_text);
                printf("Encrypt text %s\n", enc_text);
                break;
            case VIZENER:
                readtext(text);
                new_text = formattext(text);
                printf("%s", new_text);
                readkey(key_text);
                enc_text = vizener_encrypt(new_text, key_text);
                printf("Encrypt text %s\n", enc_text);
                break;
            case MATRIX:
                readtext(text);
                new_text = formattext(text);
                printf("%s", new_text);
                enc_text = matrix_encrypt(text);
                break;
            case QUIT:
                printf("Goodbye!\n");
                fl = false;
                break;
            default:
                printf("Sorry! It's Error!\n");
                break;
            }
        } else if (mode == 2)
        {
            char * decrypt_text;
            switch (choose)
            {
            case ATBASH:
                readtext(text);
                decrypt_text = atbashDecrypt(text);
                new_text = unformattext(decrypt_text);
                printf("Decrypt text: %s\n", new_text);
                break;
            case CESAR:
                readtext(text);
                int key;
                printf("Enter your key\n");
                scanf("%d", &key);
                decrypt_text = cesarDecrypt(text, key);
                new_text = unformattext(decrypt_text);
                printf("Decrypt text %s\n", new_text);
                break;
            case POLYBIOUS:
                readtext(text);
                decrypt_text = polybyius_decrypt(text);
                new_text = unformattext(decrypt_text);
                printf("Decrypt text: %s\n", new_text);
                break;
            case TRITEMIUS:
                readtext(text);
                decrypt_text = tritemius_decrypt(text);
                new_text = unformattext(decrypt_text);
                printf("Decrypt text: %s\n", new_text);
                break;
            case VIZENER:
                readtext(text);
                readkey(key_text);
                decrypt_text = vizener_decrypt(text, key_text);
                new_text = unformattext(decrypt_text);
                printf("Decrypt text: %s\n", new_text);
                break;
            case QUIT:
                printf("Goodbye!\n");
                fl = false;
                break;
            default:
                printf("Sorry! It's Error!\n");
                break;
            }
        }
        else{
            printf("Error mode\n");
            
        }
        
    }
    return 0;
}