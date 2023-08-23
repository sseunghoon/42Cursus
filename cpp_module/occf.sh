#!/bin/bash

name=$1

if [ -z "$name" ]; then
  echo "###############################\n\nMake OCCF (hpp + cpp) Script\n\nUsage: occf [ClassName]\n\n###############################"
  exit 1
fi

uppercase_name=$(echo "$name" | tr '[:lower:]' '[:upper:]')
hpp_filename="${name}.hpp"
cpp_filename="${name}.cpp"

# Create the file
touch "$hpp_filename"
touch "$cpp_filename"

# Write the content to the file
cat << EOF > "$hpp_filename"
#ifndef ${uppercase_name}_HPP
#define ${uppercase_name}_HPP

class $name {
    public:
    	$name();
		$name(const $name& copy);
		$name& operator=(const $name& other);
		~$name();
};

#endif
EOF

echo "File $hpp_filename created successfully."

# Write the content to the file
cat << EOF > "$cpp_filename"
#include "$hpp_filename"

$name::$name() {
}

$name::$name(const $name& copy) {
}

$name& $name::operator=(const $name& other) {
	
	return (*this);
}

$name::~$name() {
}

EOF

echo "File $cpp_filename created successfully."

