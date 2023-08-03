#!/bin/sh

set -xe

gcc -Wall -Wextra -Werror -Wpedantic -Og -g -o nn nn.c -lm