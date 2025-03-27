#!/usr/bin/env bash 

# Read PIDs from the file and format them into a single line
pids=$(tr '\n' ' ' < pids.txt | xargs)

# Debugging: Check the PIDs variable
#echo "PIDs: $pids"  # This should show something like "1542 8762 43"

# Use the ps command to get UIDs for the PIDs
if [[ -n "$pids" ]]; then  # Check if pids is not empty
    # Loop through each PID and get the UID
    for pid in $pids; do
        uid=$(ps -o uid= -p "$pid")
        echo "$uid"
    done
else
    echo "No valid PIDs found."
fi 

# Old
pids=$(tr '\n' ' ' < pids.txt | xargs)

  # Use the ps command to get UIDs for the PIDs
  if [[ -n "$pids" ]]; then  # Check if pids is not empty
     ps -o uid= -p $pids
  else
     echo "No valid PIDs found."
  fi  


