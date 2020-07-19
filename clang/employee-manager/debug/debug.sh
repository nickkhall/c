#!/usr/bin/env bash

tmux split -h -p 50 "gdbserver :12345 debug/debug"

tmux select -t 0

gdb -x debug/debug_conf.gdb
