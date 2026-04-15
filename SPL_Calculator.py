from tkinter import *
import tkinter as tk


window = Tk() 
window.geometry("300x500")
window.title("SPL Calculator")

Label(window, text="Vas: ").pack()
vas_entry = Entry(window)
vas_entry.pack()
Label(window, text="fs: ").pack()
fs_entry = Entry(window)
fs_entry.pack()
Label(window, text="Qts: ").pack()
qts_entry = Entry(window)
qts_entry.pack()
Label(window, text="Qes: ").pack()
qes_entry = Entry(window)
qes_entry.pack()
Label(window, text="Qms: ").pack()
qms_entry = Entry(window)
qms_entry.pack()
Label(window, text="Xmax: ").pack()
xmax_entry = Entry(window)
xmax_entry.pack()
Label(window, text="Sd: ").pack()
sd_entry = Entry(window)
sd_entry.pack()
Label(window, text="Sensitivity: ").pack()
sensitivity_entry = Entry(window)
sensitivity_entry.pack()
Label(window, text="Re: ").pack()
re_entry = Entry(window)
re_entry.pack()

Button(window, text="ON").pack()
#turn_on.pack()

with open("sample_speaker_1.txt", "w") as file:
    file.write(vas_entry)
    file.write("\n")
    file.write(fs_entry)
    file.write("\n")


window.mainloop()
