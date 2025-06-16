#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 100
#define MAX_INFO_LENGTH 256

char judges_array[MAX_JUDGES][MAX_INFO_LENGTH];

void parse_and_display(char *data, int judge_num) {
    char *token;
    const char delim[] = ",";
    int item_count = 0;

    printf("[Judge %d]\n", judge_num + 1);

    token = strtok(data, delim);
    while (token != NULL) {
        switch (item_count) {
            case 0: printf("Name: %s\n", token + strspn(token, " \"")); break;
            case 1: printf("Gender: %s\n", token + strspn(token, " ")); break;
            case 2: printf("Affiliation: %s\n", token + strspn(token, " ")); break;
            case 3: printf("Title: %s\n", token + strspn(token, " ")); break;
            case 4: printf("Expertise: %s\n", token + strspn(token, " ")); break;
            case 5: printf("Email: %s\n", token + strspn(token, " ")); break;
            case 6: printf("Phone: %s\n", token + strspn(token, " ")); break;
            default: break;
        }
        item_count++;
        token = strtok(NULL, delim);
    }

    if (item_count != 7) {
        printf("Warning: Judge info incomplete (found %d fields).\n", item_count);
    }

    printf("-----------------------------------\n");
}

int main() {
    char project[50];
    int total_judges = 0;
    int entered = 0;
    int selected_members;

    printf("####################################\n");
    printf("#      Judge List Data Entry      #\n");
    printf("####################################\n");
    printf("Participating Project: ");
    fgets(project, sizeof(project), stdin);
    project[strcspn(project, "\n")] = 0;  // remove newline

    printf("Total Number of Judges: ");
    scanf("%d", &total_judges);

    printf("Number of Selected Members: ");
    scanf("%d", &selected_members);
    getchar(); // consume newline after scanf

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Starting to input information for %d judges.\n", total_judges);
    printf("++++++++++++++++++++++++++++++++++++\n\n");

    while (entered < total_judges) {
        printf("Judge %d: ", entered + 1);
        fgets(judges_array[entered], MAX_INFO_LENGTH, stdin);
        judges_array[entered][strcspn(judges_array[entered], "\n")] = 0;

        int comma_count = 0;
        for (int i = 0; judges_array[entered][i]; i++) {
            if (judges_array[entered][i] == ',') comma_count++;
        }

        if (comma_count != 6) {
            printf("The input items are incorrect. Please enter them again.\n\n");
        } else {
            entered++;
        }
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("Judge information entry is complete.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char choice;
    printf("Should we check the judge information? ");
    scanf(" %c", &choice);

    if (choice == 'Y') {
        printf("####################################\n");
        printf("#        Display Judge Data        #\n");
        printf("####################################\n");
        for (int i = 0; i < total_judges; i++) {
            char buffer[MAX_INFO_LENGTH];
            strcpy(buffer, judges_array[i]);
            parse_and_display(buffer, i);
        }
    } else {
        printf("Program terminated.\n");
    }

    return 0;
}