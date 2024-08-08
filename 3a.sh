#!/bin/bash
            echo "Enter the number of elements"
            read number
            numbers=()
            echo "Enter the numbers:"
            for ((i = 0; i < number; i++)); do
                read num
                numbers+=($num)
            done
            largest=${numbers[0]}
            for ((i = 1; i < number; i++)); do
                if [ "${numbers[i]}" -gt "$largest" ]; then
                    largest=${numbers[i]}
                fi
            done
            echo "The largest number is $largest"
            
        
        