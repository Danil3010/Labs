import tkinter as tk
from tkinter import messagebox
import math

class VectorOperations:
    def __init__(self, vector1, vector2):
        self.vector1 = vector1
        self.vector2 = vector2
        self.size = len(vector1)  # Розмір векторів

    def norm(self, vector):
        return math.sqrt(sum(x**2 for x in vector))

    def dot_product(self):
        return sum(x * y for x, y in zip(self.vector1, self.vector2))

    def distance(self):
        return self.norm([x - y for x, y in zip(self.vector1, self.vector2)])

    def angle(self):
        dot_product = self.dot_product()
        norm1 = self.norm(self.vector1)
        norm2 = self.norm(self.vector2)
        cos_theta = dot_product / (norm1 * norm2)
        return math.degrees(math.acos(cos_theta))

    def display_results(self):
        return (f"Розмір векторів: {self.size}",
                f"Вектор 1: {self.vector1}",
                f"Вектор 2: {self.vector2}",
                f"Відстань між векторами: {self.distance():.2f}",
                f"Кут між векторами: {self.angle():.2f} градусів")

# Функція для обробки введених даних і виведення результату
def calculate():
    try:
        # Отримуємо вектори з полів введення
        vector1 = [int(entry_x1.get()), int(entry_y1.get()), int(entry_z1.get())]
        vector2 = [int(entry_x2.get()), int(entry_y2.get()), int(entry_z2.get())]

        # Перевірка, чи вектори однакової довжини
        if len(vector1) != len(vector2):
            raise ValueError("Вектори повинні мати однакову довжину.")

        vector_operations = VectorOperations(vector1, vector2)
        results = vector_operations.display_results()

        # Очищаємо поле результатів та виводимо нові значення
        text_result.delete(1.0, tk.END)
        for result in results:
            text_result.insert(tk.END, result + '\n')

    except ValueError as e:
        messagebox.showerror("Помилка", str(e))

# Функція для очищення полів
def clear_fields():
    entry_x1.delete(0, tk.END)
    entry_y1.delete(0, tk.END)
    entry_z1.delete(0, tk.END)
    entry_x2.delete(0, tk.END)
    entry_y2.delete(0, tk.END)
    entry_z2.delete(0, tk.END)
    text_result.delete(1.0, tk.END)

# Графічний інтерфейс
root = tk.Tk()
root.title("Обчислення між векторами розробив Федоренко Данило")

# Віджети
label_vector1 = tk.Label(root, text="Вектор 1:")
label_vector1.grid(row=0, column=0)

label_x1 = tk.Label(root, text="x1:")
label_x1.grid(row=1, column=0)
entry_x1 = tk.Entry(root)
entry_x1.grid(row=1, column=1)

label_y1 = tk.Label(root, text="y1:")
label_y1.grid(row=2, column=0)
entry_y1 = tk.Entry(root)
entry_y1.grid(row=2, column=1)

label_z1 = tk.Label(root, text="z1:")
label_z1.grid(row=3, column=0)
entry_z1 = tk.Entry(root)
entry_z1.grid(row=3, column=1)

label_vector2 = tk.Label(root, text="Вектор 2:")
label_vector2.grid(row=4, column=0)

label_x2 = tk.Label(root, text="x2:")
label_x2.grid(row=5, column=0)
entry_x2 = tk.Entry(root)
entry_x2.grid(row=5, column=1)

label_y2 = tk.Label(root, text="y2:")
label_y2.grid(row=6, column=0)
entry_y2 = tk.Entry(root)
entry_y2.grid(row=6, column=1)

label_z2 = tk.Label(root, text="z2:")
label_z2.grid(row=7, column=0)
entry_z2 = tk.Entry(root)
entry_z2.grid(row=7, column=1)

button_calculate = tk.Button(root, text="Обчислити", command=calculate)
button_calculate.grid(row=8, column=0, columnspan=2)

button_clear = tk.Button(root, text="Очистити", command=clear_fields)
button_clear.grid(row=9, column=0, columnspan=2)

text_result = tk.Text(root, width=50, height=10)
text_result.grid(row=10, column=0, columnspan=2)

# Запуск інтерфейсу
root.mainloop()
