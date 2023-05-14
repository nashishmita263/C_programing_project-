#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[50], ch;
    FILE *fp;
    int choice;

    printf("Enter the filename: ");
    scanf("%s", filename);

    printf("1. Create file\n");
    printf("2. Modify file\n");
    printf("3. Delete file\n");
    printf("4. Display file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            fp = fopen(filename, "w");
            if (fp == NULL)
            {
                printf("Error creating file!\n");
                exit(1);
            }
            printf("Enter the content:\n");
            while ((ch = getchar()) != EOF)
            {
                putc(ch, fp);
            }
            printf("File created successfully!\n");
            fclose(fp);
            break;

        case 2:
            fp = fopen(filename, "r+");
            if (fp == NULL)
            {
                printf("Error modifying file!\n");
                exit(1);
            }
            printf("Enter the new content:\n");
            while ((ch = getchar()) != EOF)
            {
                putc(ch, fp);
            }
            printf("File modified successfully!\n");
            fclose(fp);
            break;

        case 3:
            if (remove(filename) == 0)
            {
                printf("File deleted successfully!\n");
            }
            else
            {
                printf("Error deleting file!\n");
            }
            break;

        case 4:
            fp = fopen(filename, "r");
            if (fp == NULL)
            {
                printf("Error opening file!\n");
                exit(1);
            }
            printf("The content of the file:\n");
            while ((ch = getc(fp)) != EOF)
            {
                putchar(ch);
            }
            fclose(fp);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
