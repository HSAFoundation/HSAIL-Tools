#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char ch1, ch2, same;
    unsigned long l;

    if(argc!=3) {
        printf("Usage: compare <file 1> <file 2>\n");
        exit(1);
    }

    /* open first file */
    if((fp1 = fopen(argv[1], "rb"))==NULL) {
        printf("Cannot open first file.\n");
        exit(1);
    }

    /* open second file */
    if((fp2 = fopen(argv [2], "rb"))==NULL) {
        printf("Cannot open second file.\n");
        exit(1);
    }

    l = 0;
    same = 1;
    /* compare the files */
    while(!feof(fp1)) {
        ch1 = fgetc(fp1);
        if(ferror(fp1)) {
            printf("Error reading first file.\n");
            exit(1);
        }
        ch2 = fgetc(fp2);
        if(ferror(fp2)) {
            printf("Error reading second file.\n");
            exit(1);
        }
        if(ch1 != ch2) {
            printf("Files %s and %s differ at byte number %lu\n", 
                    argv[1], argv[2], l);
            same = 0;
            if(fclose( fp1 ) == EOF) {
                printf("Error closing first file.\n");
                exit(1);
            }

            if(fclose( fp2 ) == EOF) {
                printf("Error closing second file.\n");
                exit(1);
            }
            exit(2);
        }
        l++;
    }

    if(fclose( fp1 ) == EOF) {
        printf("Error closing first file.\n");
        exit(1);
    }

    if(fclose( fp2 ) == EOF) {
        printf("Error closing second file.\n");
        exit(1);
    }

    if(same==0) {
        printf("Files %s and %s aren't same.\n", argv[1], argv[2]);
        exit(2);
    }

    printf("Files %s and %s are the same.\n", argv[1], argv[2]);
    return 0;
}
