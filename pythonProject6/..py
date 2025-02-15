import tkinter as tk
from tkinter import messagebox
import numpy as np


def calculate_distances():
    try:
        x = np.array([float(entry_x1.get()), float(entry_x2.get()), float(entry_x3.get())])
        y = np.array([float(entry_y1.get()), float(entry_y2.get()), float(entry_y3.get())])

        euclidean_distance = np.linalg.norm(x - y)
        manhattan_distance = np.sum(np.abs(x - y))
        chebyshev_distance = np.max(np.abs(x - y))

        result_label.config(text=f"Евклідова: {euclidean_distance:.4f}\n"
                                 f"Манхеттенська: {manhattan_distance:.4f}\n"
                                 f"Чебишевська: {chebyshev_distance:.4f}")
    except ValueError:
        messagebox.showerror("Помилка", "Будь ласка, введіть числові значення!")


def clear_entries():
    entry_x1.delete(0, tk.END)
    entry_x2.delete(0, tk.END)
    entry_x3.delete(0, tk.END)
    entry_y1.delete(0, tk.END)
    entry_y2.delete(0, tk.END)
    entry_y3.delete(0, tk.END)
    result_label.config(text="")


# Створення головного вікна
root = tk.Tk()
root.title("Калькулятор відстаней між векторами розробив Федоренко Данило")
root.geometry("420x350")
root.configure(bg="#e6e6e6")

frame = tk.Frame(root, bg="#ffffff", padx=20, pady=20)
frame.pack(pady=20)

tk.Label(frame, text="Вектор X:", font=("Arial", 12, "bold"), bg="#ffffff").grid(row=0, column=0, padx=10, pady=5)
entry_x1 = tk.Entry(frame, width=7, font=("Arial", 12))
entry_x2 = tk.Entry(frame, width=7, font=("Arial", 12))
entry_x3 = tk.Entry(frame, width=7, font=("Arial", 12))
entry_x1.grid(row=0, column=1, padx=5)
entry_x2.grid(row=0, column=2, padx=5)
entry_x3.grid(row=0, column=3, padx=5)

tk.Label(frame, text="Вектор Y:", font=("Arial", 12, "bold"), bg="#ffffff").grid(row=1, column=0, padx=10, pady=5)
entry_y1 = tk.Entry(frame, width=7, font=("Arial", 12))
entry_y2 = tk.Entry(frame, width=7, font=("Arial", 12))
entry_y3 = tk.Entry(frame, width=7, font=("Arial", 12))
entry_y1.grid(row=1, column=1, padx=5)
entry_y2.grid(row=1, column=2, padx=5)
entry_y3.grid(row=1, column=3, padx=5)

calc_button = tk.Button(frame, text="Обчислити", command=calculate_distances, font=("Arial", 12, "bold"), bg="#4CAF50",
                        fg="white", width=12)
calc_button.grid(row=2, column=0, columnspan=2, pady=10, padx=5)

clear_button = tk.Button(frame, text="Очистити", command=clear_entries, font=("Arial", 12, "bold"), bg="#f44336",
                         fg="white", width=12)
clear_button.grid(row=2, column=2, columnspan=2, pady=10, padx=5)

result_label = tk.Label(frame, text="", font=("Arial", 12, "bold"), bg="#ffffff", fg="#333")
result_label.grid(row=3, column=0, columnspan=4, pady=10)

root.mainloop()
