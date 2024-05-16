import tkinter as tk
from tkinter import filedialog, scrolledtext
import subprocess
import os


class TextEditor:
    def __init__(self, master):
        self.master = master
        self.master.title("Compiler Moot")
        self.master.geometry("800x600")
        self.master.configure(background="#f0f0f0")
        self.dark_theme = False

        self.create_widgets()
        self.create_menu()
        self.create_shortcuts()

    def create_widgets(self):
        self.text = scrolledtext.ScrolledText(
            self.master,
            wrap=tk.WORD,
            bg="white",
            fg="#333",
            font=("Arial", 12),
            insertbackground="#333",
        )
        self.text.pack(expand=True, fill="both", padx=20, pady=(10, 0))

        save_button = tk.Button(
            self.master,
            text="Save File",
            command=self.save_file,
            bg="#4CAF50",
            fg="white",
            font=("Arial", 12),
            padx=10,
            pady=5,
            bd=0,
            relief=tk.FLAT,
        )
        save_button.pack(side=tk.TOP, anchor="ne", padx=10, pady=10)

        # Create a run button
        run_button = tk.Button(
            self.master,
            text="Compile & Run",
            command=self.run_code,
            bg="#2196F3",
            fg="white",
            font=("Arial", 12),
            padx=10,
            pady=5,
            bd=0,
            relief=tk.FLAT,
        )
        run_button.pack(side=tk.TOP, anchor="ne", padx=10, pady=10)

    def create_menu(self):
        menubar = tk.Menu(self.master)
        self.master.config(menu=menubar)

        file_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="File", menu=file_menu)
        file_menu.add_command(
            label="Open", accelerator="Ctrl+O", command=self.open_file
        )
        file_menu.add_command(
            label="Save", accelerator="Ctrl+S", command=self.save_file
        )
        file_menu.add_separator()
        file_menu.add_command(label="Exit", command=self.master.quit)

        edit_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="Edit", menu=edit_menu)
        edit_menu.add_command(label="Cut", accelerator="Ctrl+X", command=self.cut)
        edit_menu.add_command(label="Copy", accelerator="Ctrl+C", command=self.copy)
        edit_menu.add_command(label="Paste", accelerator="Ctrl+V", command=self.paste)

        view_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="View", menu=view_menu)
        view_menu.add_command(label="Toggle Dark Theme", command=self.toggle_theme)

    def create_shortcuts(self):
        # Add keyboard shortcut functionality to the menu items
        self.master.bind("<Control-o>", lambda event: self.open_file())
        self.master.bind("<Control-s>", lambda event: self.save_file())
        self.master.bind("<Control-x>", lambda event: self.cut())
        self.master.bind("<Control-c>", lambda event: self.copy())
        self.master.bind("<Control-v>", lambda event: self.paste())

    def open_file(self):
        file_path = filedialog.askopenfilename(
            initialdir=os.path.expanduser("~/Documents/"),
            title="Select a file",
            filetypes=(
                ("Text files", "*.txt"),
                ("Python files", "*.py"),
                ("All files", "*.*"),
            ),
        )
        if file_path:
            with open(file_path, "r") as file:
                self.text.delete("1.0", tk.END)
                self.text.insert(tk.END, file.read())

    def save_file(self):
        file_path = filedialog.asksaveasfilename(
            defaultextension=".txt",
            filetypes=(
                ("Text files", "*.txt"),
                ("Python files", "*.py"),
                ("All files", "*.*"),
            ),
        )
        if file_path:
            with open(file_path, "w") as file:
                file.write(self.text.get("1.0", tk.END).strip())

    def cut(self):
        self.text.event_generate("<<Cut>>")

    def copy(self):
        self.text.event_generate("<<Copy>>")

    def paste(self):
        self.text.event_generate("<<Paste>>")

    def run_code(self):
        try:
            # Save the content of the text editor to a temporary file
            script_path = "temp_script.py"
            with open(script_path, "w") as file:
                file.write(self.text.get("1.0", tk.END).strip())

            # Execute `make build` and `make run`
            build_process = subprocess.run(
                ["make", "build"], capture_output=True, text=True
            )
            self.text.insert(
                tk.END,
                f"\nBuild output:\n{build_process.stdout}\n{build_process.stderr}",
            )

            run_process = subprocess.run(
                ["make", "run"], capture_output=True, text=True
            )
            self.text.insert(
                tk.END, f"\nRun output:\n{run_process.stdout}\n{run_process.stderr}"
            )

            # Execute the saved script
            script_process = subprocess.run(
                ["python", script_path], capture_output=True, text=True
            )
            self.text.insert(
                tk.END,
                f"\nScript output:\n{script_process.stdout}\n{script_process.stderr}",
            )

            # Optionally, remove the temporary file after execution
            os.remove(script_path)

        except Exception as e:
            # Display any exceptions that occur
            self.text.insert(tk.END, f"\nAn error occurred: {e}\n")

    def toggle_theme(self):
        if self.dark_theme:
            self.master.configure(background="#f0f0f0")
            self.text.configure(bg="white", fg="#333", insertbackground="#333")
        else:
            self.master.configure(background="#333")
            self.text.configure(bg="#111", fg="#fff", insertbackground="#fff")
        self.dark_theme = not self.dark_theme


if __name__ == "__main__":
    root = tk.Tk()
    editor = TextEditor(root)
    root.mainloop()
