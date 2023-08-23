#!/bin/bash

# Function to recursively find and run make in directories containing Makefiles
run_make() {
    local dir="$1"
    local fclean="$2"

    cd "$dir"

    # Find directories containing a Makefile and run make on them
    find . -type f -name 'Makefile' | while read -r makefile; do
        subdir=$(dirname "$makefile")
        echo "Running make in $subdir..."

        if [[ "$fclean" == "true" ]]; then
            make -C "$subdir" fclean
        else
            make -C "$subdir"
        fi
    done
}

# Parse arguments
DIRECTORY=""
FCLEAN="false"

while [[ "$#" -gt 0 ]]; do
    case "$1" in
        -f|--fclean) FCLEAN="true"; shift ;;
        *) DIRECTORY="$1"; shift ;;
    esac
done

# Check if directory is specified
if [[ -z "$DIRECTORY" ]]; then
    echo "Please specify a directory."
    exit 1
fi

# Run the function
run_make "$DIRECTORY" "$FCLEAN"
