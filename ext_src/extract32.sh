#!/bin/bash

input_file="syscall_32.tbl"
output_file="syscall_table32.h"

max_syscall=$(grep -E '^[0-9]+' "$input_file" | awk '{print $1}' | sort -n | tail -1)

echo "#pragma once" > "$output_file"
echo "" >> "$output_file"
echo "#include \"syscall.h\"" >> "$output_file"
echo "#include \"printers.h\"" >> "$output_file"
echo "" >> "$output_file"
echo "#define SYSCALL_MAX32 $max_syscall" >> "$output_file"
echo "" >> "$output_file"
echo "const t_syscall	SYSCALL_TABLE32[SYSCALL_MAX32 + 1] = {" >> "$output_file"

while IFS= read -r line; do
    if [[ "$line" =~ ^[0-9] ]]; then
        number=$(echo "$line" | awk '{print $1}')
        name=$(echo "$line" | awk '{print $3}')
        echo -e "\t[$number]\t\t= {\"$name\", &printer_$name}," >> "$output_file"
    fi
done < "$input_file"

echo "};" >> "$output_file"

echo "File $output_file successfully generated."
