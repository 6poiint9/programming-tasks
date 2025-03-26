#!/usr/bin/env bash 

# - function to diplay help stuff | -> -h --help
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
 # get ss output to a file and awk it  
 doas ss --tcp --listening -4 -p -n > output.txt && paste <(awk '{print $4}' output.txt | grep -v '^Local$' | cut -d':' -f2) <(awk '{print $6}' output.txt | grep -v '^Peer$' | cut -d',' -f2) | sort -n 

 rm output.txt # (for security reasons)   
}


user_mode () 
{
  # get UID from pid -> ps -o uid= -p 18,406

 echo "u mode"
}

invalid_help ()
{
  echo "listen_ports.sh: unrecognized option"
  echo "Usage: listen_ports.sh [options]"
  echo "Try 'listen_ports.sh --help' for more information"

}

# handle options
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

# if no arguments provided
command_mode


# function/logic for = listening ports + process | -> -c --command or nothing 
# run -> sudo ss --tcp --listening -4 -p -n (get numerical ports) / -tlpn4
# run -> sudo lsof -iTCP -sTCP:LISTEN -n -P | grep -i ipv4
# => REAL
# sudo ss --tcp --listening -4 -p -n > output.txt && awk '{print $4}' output.txt | grep -v '^Local$' | cut -d':' -f2
#-> port number 
# awk '{print $6}' output.txt | grep -v '^Peer$' | cut -d',' -f2 => (pid=...)   OR  
# awk '{print $6}' output.txt | grep -v '^Peer$' | cut -d',' -f2 | cut -d'=' -f2 => (only pid number )
#-> Pid number
# ----- MAIN --------
# sudo ss --tcp --listening -4 -p -n > output.txt && paste <(awk '{print $4}' output.txt | grep -v '^Local$' | cut -d':' -f2) <(awk '{print $6}' output.txt | grep -v '^Peer$' | cut -d',' -f2)
# rm output.txt (for security reasons)   


# - function/logic fo = listening ports + UID | -> -u --user 

# loop + statement to choose between output/options/flags  
# => check example: template and /home/gen69/.dotfiles/.scripts/bhbcase
# 
  





