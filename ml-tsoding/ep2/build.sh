#!/bin/sh

set -xe

clang -Wall -g -Wextra -o nn nn.c -lm