#!/bin/bash

echo "Start this shell"
date

sleep 10 &
wait
echo "Countue"
echo "Finished"

