int is_valid_key(char *key) {
    while (*key) {
        if (!isalpha(*key)) {
            return 0; // Найден не буквенный символ в ключе
        }
        key++;
    }
    return 1; // Весь ключ состоит из букв
}

// Функция для шифрования текста методом Виженера
char* vigenere_encrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i, j;

    // Выделяем память под зашифрованную строку (больше, чем text_len, чтобы было место для завершающего нуля)
    char *encrypted_text = (char *)malloc((text_len + 1) * sizeof(char));
    if (encrypted_text == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return NULL;
    }

    // Проход по каждому символу текста
    for (i = 0, j = 0; i < text_len; ++i, ++j) {
        if (j >= key_len) {
            j = 0; // Циклический повтор ключа, если текст длиннее ключа
        }

        // Шифрование символа текста с использованием ключа
        int shift = key[j] - 'a'; // Предполагаем, что ключ всегда в нижнем регистре

        // Применяем шифр Виженера только к буквенным символам
        if (islower(text[i])) {
            encrypted_text[i] = 'a' + (text[i] - 'a' + shift + 1) % 26;
        } else {
            encrypted_text[i] = text[i]; // Оставляем символы, которые не являются буквами без изменений
        }
    }

    encrypted_text[text_len] = '\0'; // Добавляем завершающий нуль

    return encrypted_text;
}