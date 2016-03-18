#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
#include "cinema.h"

bool newvisitor(double x)
{
    if(rand() * x / RAND_MAX < 1)
        return (true);
    else
        return (false);
}

visitor_t visitortime(long when)
{
    visitor_t visitr;
    visitr.processtime = rand() %3 + 1;
    visitr.arrive = when;

    return (visitr);
}

int runDemo(queue_t line)
{
    visitor_t temp;
    int hours; // Duration time of the queue in hours.
    long perhour; // How much visitors will arrive per hour.
    long cycle; // A simple counter
    long cyclelimit; // Duration time of the queue in minutes.
    long turnaways = 0; //How much people leaved our cinema.
    long customers = 0; // How much people connected to the queue.
    long served = 0; // How much people were served.
    long sum_line = 0; // Current length of the queue.
    int wait_time = 0;
    double min_per_cust; // Average time between the arrival of visitors.
    long line_wait = 0;

    queue_new(&line);
    srand((unsigned)time(0));
    puts("---CINEMA QUEUE---");
    puts("Enter duration of the demo in hours: ");
    scanf("%d", &hours);
    puts("Enter average amount of clients per hour: ");
    scanf("%ld", &perhour);
    cyclelimit = MIN_PER_HR * hours;
    min_per_cust = MIN_PER_HR / perhour;

    for(cycle = 0; cycle < cyclelimit; cycle++)
    {
        if(newvisitor(min_per_cust))
        {
            if(queue_isFull(&line))
                turnaways++;
            else
            {
                customers++;
                temp = visitortime(cycle);
                queue_enqueue(temp, &line);
            }
        }
        if(wait_time <= 0 && !queue_isEmpty(&line))
        {
            queue_dequeue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += cycle - temp.arrive;
            served++;
        }
        if(wait_time > 0)
            wait_time--;
        sum_line += queue_itemCount(&line);
    }
    if(customers > 0)
    {
        printf("Came: %ld\n", customers);
        printf("Served: %ld\n", served);
        printf("Refuses: %ld\n", turnaways);
        printf("Average length of the queue %.2f\n", (double)sum_line/cyclelimit);
        printf("Average time of the waiting: %.2f minutes\n", (double)line_wait / served);
    }
    else
        puts("No clients!");
    queue_delete(&line);
    puts("End of the program.");
    return (0);
}
