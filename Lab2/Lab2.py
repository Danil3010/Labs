import numpy as np
import tkinter as tk
from tkinter import ttk


def calculate():
    try:
        v1 = np.array([float(entry_x1.get()), float(entry_y1.get()), float(entry_z1.get())])
        v2 = np.array([float(entry_x2.get()), float(entry_y2.get()), float(entry_z2.get())])

        euclidean_v1 = np.linalg.norm(v1)
        manhattan_v1 = np.sum(np.abs(v1))
        chebyshev_v1 = np.max(np.abs(v1))

        euclidean_v2 = np.linalg.norm(v2)
        manhattan_v2 = np.sum(np.abs(v2))
        chebyshev_v2 = np.max(np.abs(v2))

        euclidean_dist = np.linalg.norm(v1 - v2)
        manhattan_dist = np.sum(np.abs(v1 - v2))
        chebyshev_dist = np.max(np.abs(v1 - v2))

        result_text.set(
            f"Вектор 1: Евклідова {euclidean_v1:.4f}, Міська {manhattan_v1:.4f}, Чебишевська {chebyshev_v1:.4f}\n"
            f"Вектор 2: Евклідова {euclidean_v2:.4f}, Міська {manhattan_v2:.4f}, Чебишевська {chebyshev_v2:.4f}\n\n"
            f"Відстані: Евклідова {euclidean_dist:.4f}, Міська {manhattan_dist:.4f}, Чебишевська {chebyshev_dist:.4f}"
        )
    except ValueError:
        result_text.set("Помилка: введіть коректні числові значення!")


def clear_fields():
    entry_x1.delete(0, tk.END)
    entry_y1.delete(0, tk.END)
    entry_z1.delete(0, tk.END)
    entry_x2.delete(0, tk.END)
    entry_y2.delete(0, tk.END)
    entry_z2.delete(0, tk.END)
    result_text.set("")


app = tk.Tk()
app.title("Калькулятор норм векторів розробив Федоренко Данило")
app.geometry("450x350")
app.configure(bg="#eda8a8")

frame = ttk.Frame(app, padding=15)
frame.pack(fill=tk.BOTH, expand=True)

# Введення векторів
ttk.Label(frame, text="Вектор 1 (x, y, z):").grid(row=0, column=0, padx=5, pady=5, sticky='w')
entry_x1 = ttk.Entry(frame, width=7);
entry_x1.grid(row=0, column=1)
entry_y1 = ttk.Entry(frame, width=7);
entry_y1.grid(row=0, column=2)
entry_z1 = ttk.Entry(frame, width=7);
entry_z1.grid(row=0, column=3)

ttk.Label(frame, text="Вектор 2 (x, y, z):").grid(row=1, column=0, padx=5, pady=5, sticky='w')
entry_x2 = ttk.Entry(frame, width=7);
entry_x2.grid(row=1, column=1)
entry_y2 = ttk.Entry(frame, width=7);
entry_y2.grid(row=1, column=2)
entry_z2 = ttk.Entry(frame, width=7);
entry_z2.grid(row=1, column=3)

# Кнопки
actions_frame = ttk.Frame(frame)
actions_frame.grid(row=2, column=0, columnspan=4, pady=10)

calculate_button = ttk.Button(actions_frame, text="Обчислити", command=calculate)
calculate_button.pack(side=tk.LEFT, padx=5)

clear_button = ttk.Button(actions_frame, text="Очистити", command=clear_fields)
clear_button.pack(side=tk.RIGHT, padx=5)

# Поле для виведення результатів
result_text = tk.StringVar()
result_label = ttk.Label(frame, textvariable=result_text, wraplength=400, background="#e6e6e6", font=("Arial", 10))
result_label.grid(row=3, column=0, columnspan=4, pady=10)

app.mainloop()
