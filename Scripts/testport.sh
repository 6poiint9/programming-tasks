#!/usr/bin/env bash 

#######################################################################
# MIT License
#
#File: listen_ports.sh 
#Description: Display open listening TCP/IPv4 ports wih the according PID or UID
#
#######################################################################

# function to diplay help stuff | -> -h --help
show_help ()
{
 echo "Usage: listen_ports.sh [options] "
 echo ""
 echo "Options:"
 echo "-c, --command  print listening ports and PID, default options"
 echo "-u, --user     print listening ports and the UID"
 echo "-h, --help     display this help text and exit"
 echo ""
}

command_mode () 
{
 # get ss output to a file and awk it -> cut out only the information needed -> print the ports sorted 
 doas ss --tcp --listening -4 -p -n > output.txt && paste <(awk '{print $4}' output.txt | grep -v '^Local$' | cut -d':' -f2) <(awk '{print $6}' output.txt | grep -v '^Peer$' | awk -F, '{print $1 "," $2}' | cut -d'(' -f3 )| sort -n 

 rm output.txt # get rid of the file  
}


user_mode () 
{
  # Get the data needed and put into a file 
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

  # => remove files after script ends 
  rm output.txt 
}

# function if an invalid option was used 
invalid_help ()
{
  echo "listen_ports.sh: unrecognized option"
  echo "Usage: listen_ports.sh [options]"
  echo "Try 'listen_ports.sh --help' for more information"

}

# Main Logic 
for arg in "$@"; do   
    case $arg in 
        -h|--help)
            show_help
            exit 0
            ;;
        -c|--command)
            command_mode
            exit 0
            ;;
        -u|--user)
            user_mode
            exit 0
            ;;
        *)
            invalid_help
            exit 1
            ;;
    esac
done

# if no arguments provided -> default 
command_mode

# $@ -> handle the cmd-line arguments  
