#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STAGE 8
#define MAX_MENU 3

const char main_menu[MAX_MENU][30] = {
    "Audition Management",
    "Training",
    "Debut"
};

const char training_menu[MAX_STAGE][40] = {
    "1. Physical Strength & Knowledge",
    "2. Self-Management & Teamwork",
    "3. Language & Pronunciation",
    "4. Vocal",
    "5. Dance",
    "6. Visual & Image",
    "7. Acting & Stage Performance",
    "8. Fan Communication"
};

char stage_status[MAX_STAGE] = { 'N','N','N','N','N','N','N','N' }; // N = Not started, P = Passed, F = Failed

void clear_input() {
    while (getchar() != '\n');
}

void display_main_menu() {
    printf("\n========= Main Menu =========\n");
    for (int i = 0; i < MAX_MENU; i++) {
        printf("%d. %s\n", i + 1, main_menu[i]);
    }
    printf("Enter menu number (or 0/Q/q to quit): ");
}

void display_training_menu() {
    printf("\n========= Training Menu =========\n");
    for (int i = 0; i < MAX_STAGE; i++) {
        printf("%s [%c]\n", training_menu[i], stage_status[i]);
    }
    printf("Select a training stage (1-8), or 0 to return: ");
}

void training_stage() {
    int choice;
    while (1) {
        display_training_menu();
        if (scanf("%d", &choice) != 1) {
            clear_input();
            continue;
        }
        clear_input();

        if (choice == 0) return;
        if (choice < 1 || choice > MAX_STAGE) continue;

        if (choice > 2) {
            if (stage_status[0] != 'P' || stage_status[1] != 'P') {
                printf("\nYou must pass stages 1 and 2 before accessing this stage.\n");
                continue;
            }
        }

        if (stage_status[choice - 1] == 'P') {
            printf("\nYou have already passed this stage.\n");
            continue;
        }

        printf("\nWould you like to enter the evaluation result? (Y/N): ");
        char confirm;
        scanf(" %c", &confirm);
        clear_input();

        if (confirm == 'Y' || confirm == 'y') {
            printf("Did you complete the training and pass the certification? (Y = Pass, N = Fail): ");
            char result;
            scanf(" %c", &result);
            clear_input();

            if (result == 'Y' || result == 'y') {
                stage_status[choice - 1] = 'P';
                printf("\nStage %d marked as Passed.\n", choice);
            } else {
                stage_status[choice - 1] = 'F';
                printf("\nStage %d marked as Failed.\n", choice);
            }
        }
    }
}

int main() {
    while (1) {
        display_main_menu();

        char input[10];
        fgets(input, sizeof(input), stdin);
        if (input[0] == '0' || input[0] == 'Q' || input[0] == 'q' || input[0] == '\n') {
            printf("\nExiting Magrathea system...\n");
            break;
        }

        int option = atoi(input);

        switch (option) {
            case 1:
                printf("\n[Audition Management] Feature coming soon...\n");
                break;
            case 2:
                training_stage();
                break;
            case 3:
                printf("\n[Debut] Feature coming soon...\n");
                break;
            default:
                printf("\nInvalid selection.\n");
        }
    }
    return 0;
}