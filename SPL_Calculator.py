import tkinter as tk

window = tk.Tk() 
window.geometry("1000x600")
window.title("SPL Calculator")

# Parameters and their corresponding units
units = {
    "Vas": "liters", "fs": "Hz", "Qts": "", "Qes": "", "Qms": "",
    "Xmax": "mm", "Sd": "cm²", "Sensitivity": "dB", "Re": "Ohms",
    "n0": "", "Cms": "mm/N", "Mms": "g", "Rms": "kg/s", "Bl": "T*m",
    "Vb": "liters", "Power": "Watts"
}

labels = list(units.keys())
entries = {}

# Layout the grid
for i, label_text in enumerate(labels):
    # Parameter Name (Column 0)
    tk.Label(window, text=label_text).grid(row=i, column=0, padx=10, pady=5, sticky="e")
    
    # Input Box (Column 1)
    entry = tk.Entry(window)
    entry.grid(row=i, column=1, padx=10, pady=5)
    entries[label_text] = entry

    # Unit Label (Column 2)
    tk.Label(window, text=units[label_text]).grid(row=i, column=2, padx=10, pady=5, sticky="w")

def save_data():
    try:
        with open("current_speaker.txt", "w") as file:
            for label in labels:
                value = float(entries[label].get())
                file.write(f"{label} {value}\n")
        print("Saved successfully")
    except ValueError:
        print("Please enter valid numbers in all fields")

# Button spans all 3 columns
tk.Button(window, text="Generate Plot", command=save_data).grid(row=len(labels), column=0, columnspan=3, pady=20)

window.mainloop()
