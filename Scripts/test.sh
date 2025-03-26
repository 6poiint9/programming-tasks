#!/usr/bin/env bash 

# Function to display help
show_help () {
    echo "Usage: listen_ports.sh [options]"
    echo ""
    echo "Options:"
    echo "-c, --command  print listening ports and PID, default options"
    echo "-u, --user     print listening ports and the UID"
    echo "-h, --help     display this help text and exit"
    echo ""
}

command_mode () {
    echo "Running in command mode."
}

user_mode () {
    echo "Running in user mode."
}

invalid_help () {
    echo "listen_ports.sh: unrecognized option"
    echo "Usage: listen_ports.sh [options]"
    echo "Try 'listen_ports.sh --help' for more information"
}

# Logic to handle all options in a single loop
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

# If no options provided, run command_mode by default
command_mode
