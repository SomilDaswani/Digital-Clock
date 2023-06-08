#include <stdio.h>
#include <time.h>

void digitalClock();
void setAlarm();
void timer();
void stopwatch();

int main() {
    int choice;
    while (1){
    printf("\n");
    printf("          * * * * * * * * * * * * * * * * * * * *");
        printf("\n              Welcome to the Digital Clock App!\n");
        printf("          * * * * * * * * * * * * * * * * * * * *");
printf("\n1. Digital Clock\n");
        printf("2. Set Alarm\n");
        printf("3. Timer\n");
        printf("4. Stopwatch\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                digitalClock();
                break;
            case 2:
                setAlarm();
                break;
            case 3:
                timer();
                break;
            case 4:
                stopwatch();
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}

void digitalClock() {
     while (1) {
    time_t current_time;
    struct tm *time_info;
    char time_string[10];

    time(&current_time);
    time_info = localtime(&current_time);
    
    strftime(time_string, sizeof(time_string), "%I:%M:%S", time_info);
    printf("\r%s", time_string);
    fflush(stdout);

    sleep(1);
  }
}

void setAlarm() {
    int hour, minute;

    printf("Enter hour and minute for alarm: ");
    scanf("%d %d", &hour, &minute);

    printf("Alarm set for %02d:%02d\n", hour, minute);

    while (1) {
        time_t currentTime;
        struct tm *localTime;
        time(&currentTime);
        localTime = localtime(&currentTime);
        if (localTime->tm_hour == hour && localTime->tm_min == minute) {
            printf("\n\aAlarm! Wake up!\n\n");
            break;
        }
    }
}

void timer() {
    int seconds,i;

    printf("Enter seconds for timer: ");
    scanf("%d", &seconds);

    for ( i = seconds; i >= 0; i--) {
        printf("%d seconds remaining\n", i);
        sleep(1);
    }
    printf("Time's up!\n");
}

void stopwatch() {
     time_t start_time, stop_time;
  char input[10];

  while (1) {
    printf("Enter start to begin the stopwatch or q to exit: ");
    scanf("%s", input);

    if (input[0] == 'q') {
      break;
    }

    start_time = time(NULL);

    printf("Stopwatch started\n");

    while (1) {
      printf("Enter stop to end the stopwatch or q to exit: ");
      scanf("%s", input);

      if (input[4] == 's','t','o','p') {
        stop_time = time(NULL);
        break;
      } else if (input[0] == 'q') {
        return 0;
      }
    }
    printf("Elapsed time: %.2f seconds\n", difftime(stop_time, start_time));
}
}
