#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]) {
    char *buffer = NULL;

    char * src = NULL;
    size_t length;
    assert(argc == 2);
    FILE * f = fopen (argv[1], "rb");
    assert(f != NULL);
    if (f)
    {
        assert(fseek (f, 0, SEEK_END) == 0);
        assert((length = ftell(f)) != -1);
        assert(fseek (f, 0, SEEK_SET) == 0);
        assert((src = malloc(length)) != NULL);
        fread (src, 1, length, f);
        fclose (f);
    }
    doc2text(src, length, &buffer);
    free(src);
    puts(buffer);
    free(buffer);
}
