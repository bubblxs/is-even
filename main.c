#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_FILE_SIZE_MB 80 * (1024 * 1024)
#define BYTES_TO_MB(b) (b / (1024 * 1024))
#define HEADER_COMMENT "/* this code was generated using a real language */\n\n"
#define HEADER_JS_FILE "export default Number.prototype.isEven = function () {\n\tconst n = this.valueOf();\n\n"
#define SWITCH_JS_FILE "\tswitch (n) {\n"
#define DEFAULT_SWITCH_FILE "\t\tdefault:\n\t\t\treturn typeof (NaN);\n\t};\n"
#define DEAD_END_FILE "};"
#define EVEN_CASE "\t\tcase %zu:\n\t\t\treturn true;\n"
#define ODD_CASE "\t\tcase %zu:\n\t\t\treturn false;\n"

int main(void)
{
    FILE *file = fopen("is_even.js", "w");

    if (file == NULL)
    {
        perror("failed to open file");
        return 1;
    }

    size_t js_file_size = 0;

    js_file_size += strlen(HEADER_COMMENT);
    js_file_size += strlen(HEADER_JS_FILE);
    js_file_size += strlen(SWITCH_JS_FILE);
    js_file_size += strlen(DEFAULT_SWITCH_FILE);
    js_file_size += strlen(DEAD_END_FILE);

    fprintf(file, HEADER_COMMENT);
    fprintf(file, HEADER_JS_FILE);
    fprintf(file, SWITCH_JS_FILE);

    for (size_t i = 0; js_file_size < MAX_FILE_SIZE_MB; i++)
    {
        const char *js_case = (i % 2 == 0) ? EVEN_CASE : ODD_CASE;

        fprintf(file, js_case, i);

        js_file_size += strlen(js_case);
    }

    fprintf(file, DEFAULT_SWITCH_FILE);
    fprintf(file, DEAD_END_FILE);

    fclose(file);

    return 0;
}