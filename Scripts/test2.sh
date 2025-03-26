
ss --tcp --listening -4 -p -n | awk '{print $4, $6}' | grep -v '^Local$' | while read -r line; do
    port=$(echo "$line" | cut -d':' -f2)        # Extract the port number
    pid=$(echo "$line" | cut -d',' -f1 | sed 's/pid=//') # Extract the PID, removing "pid="

    if [[ -n "$pid" ]]; then  # Check if PID is not empty
        uid=$(ps -o uid= -p "$pid")  # Get the UID of the process
        echo "Port: $port, UID: $uid"
    else
        echo "No PID found for line: $line"
    fi
done
