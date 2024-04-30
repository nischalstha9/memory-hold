#!/bin/bash

# Define the size of the array (in MB) to allocate memory
array_size_mb=$1 # 1000 MB (1 GB)
sleep_time=${2:-infinity}

# Calculate the size of the array in bytes
array_size=$((array_size_mb * 1024 * 1024))

array_size=$((array_size / 80))

echo "Allocating $array_size_mb MB of memory..."

# Create a large array to allocate memory
declare -a memory_array

# Loop to fill the array with data (simulating memory usage)
for ((i = 0; i < array_size; i++)); do
    memory_array[$i]=0
    remainder=$(($i % 13106))
    usage=$(($i / 13106))
    if [ $remainder -eq 0 ]; then
        echo "$usage MB memory allocated."
    fi
    # echo "==> $i memory allocated..."
done

echo "Memory allocated successfully."

# Keep the script running to hold onto the allocated memory
echo "Script is now holding onto allocated $array_size_mb MB of memory. Press Ctrl+C to exit."

# Sleep indefinitely to keep the script running
while true; do
    sleep $sleep_time # Sleep for duration and then exit
    break
done
