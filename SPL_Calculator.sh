#!/bin/bash
make clean

#python SPL_Calculator.py

make all
./spl_calculator

gnuplot -p << EOF
    set title "Speaker SPL Transfer Function"
    set xlabel "Frequency (Hz)"
    set ylabel "SPL (dB)"
    set grid xtics ytics mxtics  # Added minor grid lines for better log visibility
    
    # Set the X-axis to logarithmic scale (base 10)
    set logscale x 10
    
    # Optional: Set the range to standard audio frequencies
    set xrange [20:20000]
    
    plot "sample_speaker_spl.txt" with lines title "SPL Response"
EOF

