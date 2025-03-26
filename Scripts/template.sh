#!/bin/sh

#######################################################################
# Template for any Shell Script
# Usage:
#   template.sh [--help]
# The option --help shows the help and exits
#
# Author: Your name, Your affiliation, HS-Esslingen
# Date: Date-of-the-last-edit
#######################################################################

function show_help {
    echo "Usage: template.sh [-h|--help]"
    echo ""
    echo "Some explanation about this script..."
    echo ""
    echo "  -h|--help: Show this help and quit"
    echo "           : all options are explained"
    echo ""
}

# Go through all the parameters passed and check for arguments
# Here WITHOUT getopt or getopts, since we allow long option names (--help)
# Better use getopts (safer for optional parameters...)
while test $# -gt 0 ; do
    case "$1" in
    -h|--help)
        show_help
        exit
        ;;
    esac
    shift
done

# Best practice: set variables in the option parsing, then
# act HERE accordingly... (with proper error checking, e.g. have
# mutually exlusive options been passed, are files available, etc.)
#!/bin/bash

# Function to display help
show_help() {
    echo "Usage: myscript.sh [OPTIONS]"
    echo "Options:"
    echo "  -h, --help      Display this help message"
    echo "  --fast          Run the script in fast mode"
}

# Parse command line options
while [[ $# -gt 0 ]]; do
    case $1 in
        -h|--help)
            show_help
            exit 0
            ;;
        --fast)
            FAST_MODE=true
            shift # Move to the next argument
            ;;
        *)
            echo "Unknown option: $1"
            show_help
            exit 1
            ;;
    esac
done

# Main script logic
if [[ "$FAST_MODE" == true ]]; then
    echo "Running in fast mode"
    # Add your fast mode logic here
else
    echo "Running in normal mode"
    # Add your normal mode logic here
fi
