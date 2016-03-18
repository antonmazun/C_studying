#pragma once

#include "queue.h"

#define MIN_PER_HR 60.0

bool newvisitor(double x);
visitor_t visitortime(long when);

int runDemo(queue_t line);
