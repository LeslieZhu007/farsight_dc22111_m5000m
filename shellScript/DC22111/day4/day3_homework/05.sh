#!/bin/bash 
id1=$(head -10 /etc/passwd | tail -1 | cut -d ":" -f 3)
id2=$(head -20 /etc/passwd | tail -1 | cut -d ":" -f 3)
echo $((id1+id2))
