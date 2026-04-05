from tkinter import *


window = Tk() 
window.geometry("300x600")
window.title("SPL Calculator")

Label(window, text="Vas: ").pack()
entry = Entry(window)
entry.pack()
Label(window, text="fs: ").pack()
entry = Entry(window)
entry.pack()
Label(window, text="Qts: ").pack()
entry = Entry(window)
entry.pack()

window.mainloop()
