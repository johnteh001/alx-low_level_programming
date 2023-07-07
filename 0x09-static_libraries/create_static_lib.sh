#!/bin/bash
gcc -wall -wextra -werror -pendastic -c *.c
ar rc liball.a *.o
