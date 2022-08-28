#pragma warning(disable:4996)

#include <stdio.h>
#include <conio.h>

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    FILE* stream;
    char list[30];
    int  i, numread, numwritten;

    //Buka file dalam mode teks:
    if (fopen_s(&stream, "fread.out", "w+t") == 0) {
        for (i = 0; i < 25; i++) {
            list[i] = (char)('z' - i);
        }
        //Mencetak 25 karakter untuk streaming
        numwritten = fwrite(list, sizeof(char), 25, stream);
        printf("Wrote %d items\n", numwritten);
        fclose(stream);
    } else {
        printf("Problem opening the file\n");
    }
        

    if (fopen_s(&stream, "fread.out", "r+t") == 0) {
        //Mencoba membaca dalam 25 karakter
        numread = fread(list, sizeof(char), 25, stream);
        printf("Number of items read = %d\n", numread);
        printf("Contents of buffer = %.25s\n", list);
        fclose(stream);
    } else {
        printf("File could not be opened\n");
    }
      
    _getch();
    return 0;
}