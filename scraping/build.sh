#!/bin/sh
set -xe
gcc -Wall -Wextra -Werror -Wpedantic -Og -g -o scrap scrap.c -lcurl