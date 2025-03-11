#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

// ألوان ANSI للطباعة الملونة
#define COLOR_GREEN  "\x1b[32m"
#define COLOR_BLUE   "\x1b[34m"
#define COLOR_PURPLE "\x1b[35m"
#define COLOR_RED    "\x1b[31m"
#define COLOR_RESET  "\x1b[0m"

// دالة لإنشاء صورة PNG بالنص
void create_png(const char *filename, const char *text) {
    int width = 300, height = 100;
    unsigned char image[width * height * 3];

    // خلفية بيضاء
    memset(image, 255, sizeof(image));

    // حفظ الصورة
    if (stbi_write_png(filename, width, height, 3, image, width * 3)) {
        printf(COLOR_PURPLE "[PNG] Saved: %s\n" COLOR_RESET, filename);
    } else {
        printf(COLOR_RED "[Error] Failed to save PNG: %s\n" COLOR_RESET, filename);
    }
}

// دالة لحفظ النص في ملف
void save_to_file(const char *filename, const char *text) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s\n", text);
        fclose(file);
        printf(COLOR_BLUE "[FILE] Saved: %s\n" COLOR_RESET, filename);
    } else {
        printf(COLOR_RED "[Error] Cannot write to file: %s\n" COLOR_RESET, filename);
    }
}

// دالة لاستخراج النص بين المعقوفات "..."
void extract_text(const char *input, char *output) {
    char *start = strchr(input, '"');
    char *end = strrchr(input, '"');
    if (start && end && start != end) {
        size_t len = end - start - 1;
        strncpy(output, start + 1, len);
        output[len] = '\0';
    } else {
        strcpy(output, "");
    }
}

int main() {
    char input[256], text[256], filename[256];

    printf(COLOR_GREEN "Simple Language Interpreter (type 'exit' to quit)\n" COLOR_RESET);

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        // إزالة السطر الجديد \n من الإدخال
        input[strcspn(input, "\n")] = '\0';

        // خروج من البرنامج
        if (strcmp(input, "exit") == 0) {
            printf(COLOR_RED "Exiting...\n" COLOR_RESET);
            break;
        }

        // تحليل الأوامر
        if (strncmp(input, "out:", 4) == 0) {
            extract_text(input, text);
            printf(COLOR_GREEN "[OUT] %s\n" COLOR_RESET, text);
        }
        else if (strncmp(input, "file:", 5) == 0) {
            sscanf(input + 5, " \"%[^\"]\" \"%[^\"]\"", filename, text);
            save_to_file(filename, text);
        }
        else if (strncmp(input, "png:", 4) == 0) {
            sscanf(input + 4, " \"%[^\"]\" \"%[^\"]\"", filename, text);
            create_png(filename, text);
        }
        else {
            printf(COLOR_RED "[Error] Unknown command!\n" COLOR_RESET);
        }
    }

    return 0;
}
