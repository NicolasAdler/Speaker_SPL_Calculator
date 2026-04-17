#!/bin/bash
make clean
#You need an if else statement that checks the python version on the machine, for example, on my Mac at home I can
#run this command 'python ___' but on my windows computer I can only run 'python3 ___', in this bash script you 
#should check to see the python verison and only run the command based on the what the user has on their machine

# for now use this line to call the GUI: 
python3 SPL_Calculator.py $

make all
./spl_calculator

# Heres another example, my mac has GNU plot but I dont have it on my windows machine, It might be better
# to default back to python for the plotting, 

# **** TRANSLATE THIS CODE TO PYTHON ****


#gnuplot -p << EOF
#    set title "Speaker SPL Transfer Function"
#    set xlabel "Frequency (Hz)"
#   set ylabel "SPL (dB)"
#   set grid xtics ytics mxtics  # Added minor grid lines for better log visibility
    
    # Set the X-axis to logarithmic scale (base 10)
#    set logscale x 10
    
    # Optional: Set the range to standard audio frequencies
#    set xrange [20:20000]
    
#    plot "current_spl.txt" with lines title "SPL Response"
#EOF

