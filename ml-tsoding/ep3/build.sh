#!/bin/sh

set -xe

gcc -Wall -Wextra -Werror -Wpedantic -Og -g -o nn nn.c -lm
gcc -Wall -Wextra -Werror -Wpedantic -Og -g -o twice twice.c -lm
gcc -Wall -Wextra -Werror -Wpedantic -Og -g -o gates gates.c -lm
gcc -Wall -Wextra -Werror -Wpedantic -Og -g -o adder adder.c -lm