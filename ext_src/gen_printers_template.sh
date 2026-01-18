#!/bin/bash

input_file="printers.h"
output_file="printers.c"

if [ ! -f "$input_file" ]; then
    exit 1
fi

grep -oP 'printer_\w+' "$input_file" | sort -u > printer_functions.txt

echo "#include \"printers.h\"" > "$output_file"
echo "" >> "$output_file"

while IFS= read -r func; do
    echo "void	$func(unsigned long args[6], unsigned long ret) {" >> "$output_file"
    echo "    (void)args;" >> "$output_file"
    echo "    (void)ret;" >> "$output_file"
    echo "}" >> "$output_file"
    echo "" >> "$output_file"
done < printer_functions.txt

rm printer_functions.txt
