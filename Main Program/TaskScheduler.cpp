#include <cstdlib>
#include "TaskScheduler.h"

void createTask() {
    system("schtasks /create /tn \"OpenSourceActivator\" /tr \"C:\\OpenSourceActivator\\Activator.exe\" /sc onstart /RL HIGHEST");
}
