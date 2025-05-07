#!/bin/bash
# Test script for mod_syscall_counter kernel module

# Check if running as root
if [ "$EUID" -ne 0 ]; then
  echo "This script must be run as root"
  exit 1
fi

# Check if the module is already loaded
if lsmod | grep -q "mod_syscall_counter"; then
  echo "Module is already loaded. Unloading first..."
  rmmod mod_syscall_counter
fi

# Load the module
echo "Loading mod_syscall_counter module..."
insmod ./mod_syscall_counter.ko
if [ $? -ne 0 ]; then
  echo "Failed to load module. Check dmesg for errors."
  exit 1
fi

echo "Module loaded successfully. Checking kernel log..."
dmesg | tail -n 3

# Function to display current system call counts
show_counts() {
  echo -e "\nCurrent system call counts:"
  cat /proc/syscall_counter
}

# Display initial counts
show_counts

# Generate some system calls
echo -e "\nGenerating system calls..."
echo "Running 'ls -la'..."
ls -la > /dev/null

echo "Running 'ps aux'..."
ps aux > /dev/null

echo "Running 'grep test /etc/passwd'..."
grep test /etc/passwd > /dev/null 2>&1

# Show updated counts
show_counts

# Create a temporary file to test file I/O system calls
echo -e "\nTesting file I/O system calls..."
echo "test data" > /tmp/syscall_test.txt
cat /tmp/syscall_test.txt > /dev/null
rm /tmp/syscall_test.txt

# Show updated counts again
show_counts

# Prompt for unloading
echo -e "\nPress Enter to unload the module, or Ctrl+C to keep it loaded"
read

# Unload the module
echo "Unloading mod_syscall_counter module..."
rmmod mod_syscall_counter
if [ $? -eq 0 ]; then
  echo "Module unloaded successfully"
else
  echo "Failed to unload module. Check dmesg for errors."
fi

# Show final kernel log
echo -e "\nFinal kernel log:"
dmesg | tail -n 3

echo -e "\nTest completed" 