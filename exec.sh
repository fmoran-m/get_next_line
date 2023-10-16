#!/bin/sh
cc get_next_line.c get_next_line_utils.c -fsanitize=address -g -Wall -Wextra -Werror -BUFFER_SIZE=10 
