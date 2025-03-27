#!/usr/bin/env bash 
    # Get the output of listening TCP ports and their PIDs
    doas ss --tcp --listening -4 -p -n > output.txt

    # Extract Ports and corresponding PIDs, then loop over them
    awk '{print $4, $6}' output.txt | grep -v '^Local$' | while read -r port pid; do
        # Extract the port number
        port_number=$(echo "$port" | cut -d':' -f2)
        # Extract the PID, removing the "pid=" prefix
        pid_number=$(echo "$pid" | cut -d',' -f1 | sed 's/pid=//')
        
        # Get the UID for the current PID
        uid=$(ps -o uid= -p "$pid_number")

        # Print Port and UID with two spaces in between
        echo "$port_number  $uid"
    done

