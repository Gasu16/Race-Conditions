#!/bin/bash

mkdir /tmp/out/
touch /tmp/out/a
touch /tmp/out/b
echo "a" > /tmp/out/a
echo "b" > /tmp/out/b
cat /tmp/out/a
cat /tmp/out/b
sudo chown root:root /tmp/out/b
