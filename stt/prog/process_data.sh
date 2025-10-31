#!/bin/bash

LOGFILE="run.log"
ERRORLOG="error.log"
exec > >(tee -a "$LOGFILE" ) 2> >(tee -a "$ERRORLOG" >&2)
echo "$( date ) : Script started "

INPUT_DIR="./data"
OUTPUT_FILE="./summary.txt"

if [ ! -d "$INPUT_DIR" ]; then
	echo "$( date ) : ERROR - Input directory not found : $INPUT_DIR " >&2
	exit 1
fi
> "$OUTPUT_FILE"

echo "Processing files in $INPUT_DIR..."
> "$OUTPUT_FILE"

for file in "$INPUT_DIR"/*.txt; do
	if [ ! -f "$file" ]; then
		echo "$( date ) : WARNING - No file found" >&2
		continue
	fi
	echo "Processing $file"
	lines=$( cat "$file" | wc -l )
	words=$( cat "$file" | wc -w )
	chars=$( cat "$file" | wc -c )
	echo "$file : $lines lines, $words words, $chars characters" >> "$OUTPUT_FILE"
done

echo "$( date ) : Script completed successfully"
