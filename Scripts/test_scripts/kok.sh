#!/usr/bin/env bash 

    # 1. Print out the sorted Ports 
    # 2. Print out the UIDs next to the Ports

    # Get the output of listening TCP ports and their PIDs
    doas ss --tcp --listening -4 -p -n > output.txt

    # Extract and sort Ports
    ports=$(awk '{print $4}' output.txt | grep -v '^Local$' | cut -d':' -f2 | sort -n)
    
    # Extract PIDs
    pids=$(awk '{print $6}' output.txt | grep -v '^Peer$' | cut -d',' -f2 | sort -n | cut -d '=' -f2)

    # Convert PIDs into an array
    readarray -t pid_array <<< "$pids"

    # Print Ports and corresponding UIDs
    echo "$ports" | while read -r port; do
        # Get the UID for the first matching PID
        uid=$(ps -o uid= -p "${pid_array[0]}")
        
        # Print Port and UID with two spaces in between
        echo "$port  $uid"
        
        # Remove the first PID from the array
        pid_array=("${pid_array[@]:1}")
    done

    #-----------------------------------------------------------

    # Optionally clean up temporary files
    # rm pids.txt 
    # rm output.txt 
 # 1. Print out the sorted Ports 
  # 2. Print out the only the cut out PIDs (of the sorted Ports)
  # 3. pass the ports to -> ps -o uid= -p pid1 pid2 (separated by a space) 
  # 4. Paste the UIDs next to the Ports (should be already sorted)  
  # -
  #1 Print Ports 
  doas ss --tcp --listening -4 -p -n > output.txt && awk '{print $4}' output.txt | grep -v '^Local$' | cut -d':' -f2 | sort -n
  # 
  #1 PRINT UIDs to file  
  awk '{print $6}' output.txt | grep -v '^Peer$' | cut -d',' -f2 | sort -n | cut -d '=' -f2 > pids.txt 
#--
  # # Read PIDs from the file and format them into a single line
 # Read PIDs from the file and format them into a single line
 pids=$(tr '\n' ' ' < pids.txt | xargs)

# Use the ps command to get UIDs for the PIDs
 if [[ -n "$pids" ]]; then  # Check if pids is not empty
     # Loop through each PID and get the UID -> needed for same PID 
     for pid in $pids; do
         uid=$(ps -o uid= -p "$pid")
         echo "$uid"
     done
 else
     echo "No valid PIDs found."
 fi  
 #rm pids.txt #-> remove after script is run 
 #rm output.txt 

