#!/bin/bash

input_file_32="syscall_table32.h"
input_file_64="syscall_table64.h"
output_file="printers.h"

temp_file=$(mktemp)

extract_names_h() {
    grep -oP 'printer_\w+' "$1" | sort -u
}

extract_names_h "$input_file_32" >> "$temp_file"
[ -f "$input_file_64" ] && extract_names_h "$input_file_64" >> "$temp_file"

sort -u "$temp_file" -o "$temp_file"

echo "#pragma once" > "$output_file"
echo "" >> "$output_file"

while IFS= read -r name; do
    echo "void	$name(unsigned long args[6], unsigned long ret);" >> "$output_file"
done < "$temp_file"

rm "$temp_file"

echo "File $output_file successfully generated."