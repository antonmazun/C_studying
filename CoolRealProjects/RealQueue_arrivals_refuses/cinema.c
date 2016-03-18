#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"
#include "cinema.h"

// x - average time between clients arrivals, in minutes.
// If client returned in a minute - return true value.
// So, this function just checks, if client will arrive in a minute.
bool newvisitor(double x)
{
    if(rand() * x / RAND_MAX < 1)
        return (true);
    else
        return (false);
}

// when - client arrival time.
// return a visitor with:
// a) processtime: time for a service.
// b) arrive = when - arrival time.
visitor_t visitortime(long when)
{
    visitor_t visitr;
    visitr.processtime = rand() % 3 + 1;
    visitr.arrive = when;

    return (visitr);
}

// Main demo for the queue.
int runDemo(queue_t line)
{
    visitor_t temp; // Describes current visitor.
    int hours; // Duration of the queue in hours.
    long perhour; // How much visitors will arrive per hour.
    long cycle; // A simple counter to describe CURRENT minute.
    long turnaways = 0; //How much people leaved our cinema.
    long customers = 0; // How much people connected to the queue.
    long served = 0; // How much people were served.
    long sum_line = 0; // Current length of the queue.
    int wait_time = 0; // Skolko eshe wremeni do momenta, kogda obsluzhivanie customer-a zakonchitsya
    double min_per_cust; // Average time between the arrival of visitors.
    long line_wait = 0; // How much time customers are waiting in the queue.

    queue_new(&line);
    srand((unsigned)time(0));
    puts("---CINEMA QUEUE---");
    puts("Enter duration of the demo in hours: ");
    scanf("%d", &hours);
    puts("Enter average amount of clients per hour: ");
    scanf("%ld", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    // 1 iteration == 1 minute
    for(cycle = 0; cycle < MIN_PER_HR * hours; cycle++)
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
        printf("Visitors, that came to the queue: %ld\n", customers);
        printf("Served: %ld\n", served);
        printf("Refuses: %ld\n", turnaways);
        printf("Average length of the queue %.2f\n", (double)sum_line/(MIN_PER_HR * hours));
        printf("Average time of the waiting: %.2f minutes\n", (double)line_wait / served);
    }
    else
        puts("No clients!");
    queue_delete(&line);
    puts("End of the program.");
    return (0);
}
