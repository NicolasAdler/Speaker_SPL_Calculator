'''
import tkinter as tk

def update_fields(*args):
    # Clear existing widgets in the entry frame
    for widget in entry_frame.winfo_children():
        widget.destroy()

    num_systems = int(selection_var.get())
    global entries_matrix
    entries_matrix = [] # Nested list to store entries: [system_index][label]

    # Header Row
    for col in range(num_systems):
        tk.Label(entry_frame, text=f"System {col+1}", font=('Arial', 10, 'bold')).grid(row=0, column=col+1, pady=10)

    # Create Rows for each parameter
    for r, label_text in enumerate(labels):
        # Parameter Name (Left side)
        tk.Label(entry_frame, text=label_text).grid(row=r+1, column=0, padx=10, pady=2, sticky="e")
        
        # Unit (Right side)
        tk.Label(entry_frame, text=units[label_text]).grid(row=r+1, column=num_systems+1, padx=10, pady=2, sticky="w")

        # Entry boxes for each system
        for c in range(num_systems):
            if r == 0: entries_matrix.append({}) # Initialize dict for each system
            entry = tk.Entry(entry_frame, width=10)
            entry.grid(row=r+1, column=c+1, padx=5, pady=2)
            entries_matrix[c][label_text] = entry

def save_data():
    try:
        with open("current_speaker.txt", "w") as file:
            for i, system_entries in enumerate(entries_matrix):
                file.write(f"--- System {i+1} ---\n")
                for label in labels:
                    value = float(system_entries[label].get())
                    file.write(f"{label}: {value}\n")
                file.write("\n")
        print("Saved successfully")
    except ValueError:
        print("Please enter valid numbers in all fields")

window = tk.Tk()
window.geometry("1100x700")
window.title("SPL Calculator")

units = {
    "Vas": "liters", "fs": "Hz", "Qts": "", "Qes": "", "Qms": "",
    "Xmax": "mm", "Sd": "cm²", "Sensitivity": "dB", "Re": "Ohms",
    "n0": "", "Cms": "mm/N", "Mms": "g", "Rms": "kg/s",
    "Bl": "T*m", "Box Volume": "liters", "Power": "Watts"
}
labels = list(units.keys())

# Top Selection Menu
top_frame = tk.Frame(window)
top_frame.pack(pady=10)
tk.Label(top_frame, text="How many systems to compare?").pack(side="left", padx=10)

selection_var = tk.StringVar(window)
selection_var.set("1") # Default
dropdown = tk.OptionMenu(top_frame, selection_var, "1", "2", "3", "4")
dropdown.pack(side="left")
selection_var.trace("w", update_fields) # Call update_fields when selection changes

# Container for the dynamic entries
entry_frame = tk.Frame(window)
entry_frame.pack(padx=20, pady=10)

tk.Button(window, text="Generate Plot", command=save_data, bg="lightblue").pack(pady=20)

# Initialize with 1 system
update_fields()

window.mainloop()
'''
import tkinter as tk

def update_fields(*args):
    # Clear existing widgets to rebuild the interface
    for widget in entry_frame.winfo_children():
        widget.destroy()

    num_systems = int(selection_var.get())
    global entries_matrix
    entries_matrix = [] # Holds a dictionary for each system: [system_index][parameter_name]

    # Header Row
    for col in range(num_systems):
        tk.Label(entry_frame, text=f"System {col+1}", font=('Arial', 10, 'bold')).grid(row=0, column=col+1, pady=10)

    # Build entry rows for each T/S parameter
    for r, label_text in enumerate(labels):
        tk.Label(entry_frame, text=label_text).grid(row=r+1, column=0, padx=10, pady=2, sticky="e")
        tk.Label(entry_frame, text=units[label_text]).grid(row=r+1, column=num_systems+1, padx=10, pady=2, sticky="w")

        for c in range(num_systems):
            if r == 0: entries_matrix.append({}) # Initialize system dictionary on first parameter row
            entry = tk.Entry(entry_frame, width=10)
            entry.grid(row=r+1, column=c+1, padx=5, pady=2)
            entries_matrix[c][label_text] = entry

def save_data():
    try:
        num_systems = len(entries_matrix)
        for i in range(num_systems):
            # Create a separate file for each system (e.g., system_1.txt)
            filename = f"system_{i+1}.txt"
            with open(filename, "w") as file:
                system_data = entries_matrix[i]
                for label in labels:
                    value = float(system_data[label].get())
                    file.write(f"{label} {value}\n")
        print(f"Successfully saved {num_systems} file(s).")
    except ValueError:
        print("Please enter valid numbers in all fields")

# Main Window Setup
window = tk.Tk()
window.geometry("1100x700")
window.title("SPL Calculator")

units = {
    "Vas": "liters", "fs": "Hz", "Qts": "", "Qes": "", "Qms": "",
    "Xmax": "mm", "Sd": "cm²", "Sensitivity": "dB", "Re": "Ohms",
    "n0": "", "Cms": "mm/N", "Mms": "g", "Rms": "kg/s",
    "Bl": "T*m", "Box Volume": "liters", "Power": "Watts"
}
labels = list(units.keys())

# Dropdown Selection
top_frame = tk.Frame(window)
top_frame.pack(pady=10)
tk.Label(top_frame, text="How many systems to compare?").pack(side="left", padx=10)

selection_var = tk.StringVar(window)
selection_var.set("1")
dropdown = tk.OptionMenu(top_frame, selection_var, "1", "2", "3", "4")
dropdown.pack(side="left")
selection_var.trace("w", update_fields) # Triggers update_fields whenever selection changes

# Dynamic Entry Container
entry_frame = tk.Frame(window)
entry_frame.pack(padx=20, pady=10)

tk.Button(window, text="Generate Plot", command=save_data, bg="lightblue").pack(pady=20)

# Initialize fields for 1 system
update_fields()

window.mainloop()
