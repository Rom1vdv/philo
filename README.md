# What is this project about ?

This project attempts to replicate the famous "Dining philosopher problem" 

-> https://en.wikipedia.org/wiki/Dining_philosophers_problem

# How does it work ?

Each philosopher is a thread. They each bring a fork to the table and need 2 forks in order to eat.

Each philosopher can do 3 actions : They either eat, sleep or think and in some circumstances they die.

Each philosopher brings need to pick up a fork (in this case its right fork) in order to eat.
# How does the program work ?
In order to launch the program you need to first
> Make

Then you can call the binary :
> ./philo [number_of_philo] [time_to_die] [time_to_eat] [time_to_sleep] and an option argument [number_of_time_eaten]

If a philosopher fails to eat in a window greater than [time_to_die], the programs stops and will display which philosopher has died.

While it's running, a routine will display exactly what is happening during the execution.
