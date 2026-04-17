import tkinter as tk

window = tk.Tk() 
window.geometry("300x800")
window.title("SPL Calculator")

# Create entries
labels = ["Vas", "fs", "Qts", "Qes", "Qms", "Xmax", "Sd", "Sensitivity", "n0", "Cms", "Mms", "Rms", "Bl", "Vb", "W"]
entries = {}

for label in labels:
    tk.Label(window, text=label).pack()
    entry = tk.Entry(window)
    entry.pack()
    entries[label] = entry

def save_data():
    try:
        with open("current_speaker.txt", "w") as file:
            for label in labels:
                value = float(entries[label].get())
                file.write(f"{label} {value}\n")

        print("Saved successfully")

    except ValueError:
        print("Please enter valid numbers in all fields")

tk.Button(window, text="ON", command=save_data).pack()

window.mainloop()
