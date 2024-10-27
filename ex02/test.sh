
#!/bin/bash

# Determine whether to use jot (macOS) or shuf (Linux) based on OS
if [[ "$(uname)" == "Darwin" ]]; then
    generate_numbers() {
        jot -r 9 1 100000 | tr '\n' ' '
    }
elif [[ "$(uname)" == "Linux" ]]; then
    generate_numbers() {
        shuf -i 1-100000 -n 9 | tr '\n' ' '
    }
else
    echo "Unsupported OS"
    exit 1
fi

# Loop until the command returns 1
while true; do
    # Generate a sequence of 9 random numbers
    numbers=$(generate_numbers)
    
    # Call /PmergeMe with the generated numbers
    ./PmergeMe $numbers
    
    # Capture the exit status of the command
    status=$?
    
    # Check the exit status and respond accordingly
    if [ $status -eq 1 ]; then
        echo "Command returned 1, exiting loop."
        break
    elif [ $status -eq 0 ]; then
        echo "Command returned 0, continuing loop."
    else
        echo "Command returned an unexpected status: $status. Exiting."
        exit 1
    fi
done