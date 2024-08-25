#!/bin/bash

tr -dc "A-Z a-z 0-9" < /dev/urandom | fold -w 100 | head -n 100000 > bigfile.txt