#define MAX_LENGTH 1000 // максимальная длина вводимой строки

char* transformText(char *input) {
    char *transformed = (char *)malloc(MAX_LENGTH * sizeof(char)); // выделяем память для результата
    if (transformed == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }

    int i, j;
    i = 0;
    j = 0;
    while (input[i] != '\0' && j < MAX_LENGTH - 1) {
        if (isupper(input[i])) {
            transformed[j++] = tolower(input[i]);
        } else if (input[i] == ' ') {
            transformed[j++] = 'p';
            transformed[j++] = 'r';
            transformed[j++] = 'b';
        } else if (input[i] == ',') {
            transformed[j++] = 'z';
            transformed[j++] = 'p';
            transformed[j++] = 't';
        } else {
            transformed[j++] = input[i];
        }
        i++;
    }
    transformed[j] = '\0';

    return transformed;
}