import tkinter as tk
from tkinter import filedialog, scrolledtext
import subprocess
import os


class TextEditor:
    def __init__(self, master):
        self.master = master
        self.master.title("SAY COMPILER")
        self.master.geometry("1920x1080")
        self.master.configure(background="#f0f0f0")
        self.dark_theme = True
        self.first_build = True 

        self.create_widgets()
        self.create_menu()
        self.create_shortcuts()

        self.build_project()


    def create_widgets(self):
          # Add title label
        title_label = tk.Label(
            self.master,
            text="كومبايل و عالنبي صلي",
            bg="#333",
            fg="white",
            font=("Raleway", 24, "bold"),
            pady=10
        )
        title_label.pack(side=tk.TOP, anchor="n")

        self.text = scrolledtext.ScrolledText(
            self.master,
            wrap=tk.WORD,
            bg="white",
            fg="#333",
            font=("Raleway", 12, "bold"),
            insertbackground="#333",
        )
        self.text.pack(expand=True, fill="both", padx=20, pady=(10, 0))
        self.text.configure(yscrollcommand=self.scroll_both)


        save_button = tk.Button(
            self.master,
            text="Save File",
            command=self.save_file,
            bg="#4CAF50",
            fg="white",
            font=("Raleway", 12, "bold"),
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
            font=("Raleway", 12, "bold"),
            padx=10,
            pady=5,
            bd=0,
            relief=tk.FLAT,
        )
        run_button.pack(side=tk.TOP, anchor="ne", padx=10, pady=10)

        # Scrolled text widget to display compilation status and errors
        self.output_text = scrolledtext.ScrolledText(
            self.master,
            wrap=tk.WORD,
            bg="white",
            fg="#333",
            font=("Raleway", 12, "bold"),
            insertbackground="#333",
        )
        self.output_text.pack(expand=True, fill="both", padx=20, pady=(10, 0))

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
        # edit_menu.add_command(label="Paste", accelerator="Ctrl+V", command=self.paste)

        view_menu = tk.Menu(menubar, tearoff=0)
        menubar.add_cascade(label="View", menu=view_menu)
        view_menu.add_command(label="Toggle Theme", command=self.toggle_theme)

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

    # def paste(self):
    #     self.text.event_generate("<<Paste>>")

    def build_project(self):
        subprocess.run(["make", "build"])

    def run_code(self):
        self.output_text.delete("1.0", tk.END)

        script_path = "gui.txt"
        with open(script_path, "w") as file:
            file.write(self.text.get("1.0", tk.END).strip())

        build_output = subprocess.run(["make", "gui"], capture_output=True, text=True)

        syntax_error_file = "syntax_error.txt"
        if os.path.exists(syntax_error_file):
            with open(syntax_error_file, "r") as err_file:
                syntax_errors = err_file.readlines()
                for line in syntax_errors:
                    self.output_text.insert(tk.END, line, "error")

        semantic_error_file = "semantic_error.txt"
        if os.path.exists(semantic_error_file):
            with open(semantic_error_file, "r") as err_file:
                semantic_errors = err_file.readlines()
                for line in semantic_errors:
                    if line.startswith("WARNING"):
                        self.output_text.tag_config("warning")
                        self.output_text.insert(tk.END, line, "warning")
                    elif line.startswith("ERROR"):
                        self.output_text.tag_config("error", foreground="red")
                        self.output_text.insert(tk.END, line, "error")
        self.output_text.tag_config("warning", foreground="#FFC107")
        self.output_text.tag_config("error", foreground="red")

        os.remove(script_path)

    def toggle_theme(self):
        if self.dark_theme:
            self.master.configure(background="#333")
            self.text.configure(bg="#111", fg="#fff", insertbackground="#fff")
            self.output_text.configure(bg="#111", fg="#fff", insertbackground="#fff")
        else:
            self.master.configure(background="#f0f0f0")
            self.text.configure(bg="white", fg="#333", insertbackground="#333")
            self.output_text.configure(bg="white", fg="#333", insertbackground="#333")
        self.dark_theme = not self.dark_theme
        self.output_text.tag_config("warning", foreground="#FFC107")
        self.output_text.tag_config("error", foreground="red")

    # def update_line_numbers(self, event=None):
    #     self.line_numbers.config(state="normal")
    #     self.line_numbers.delete("1.0", "end")

    #     line_count = int(self.text.index("end-1c").split(".")[0])
    #     line_numbers_string = "\n".join(str(i) for i in range(1, line_count + 1))
        
    #     self.line_numbers.insert("1.0", "\n" + line_numbers_string)  # Add newline at the beginning
    #     self.line_numbers.config(state="disabled")

    def scroll_both(self, *args):
        self.text.yview(*args)
        self.line_numbers.yview(*args)
        self.update_line_numbers()

if __name__ == "__main__":
    root = tk.Tk()
    editor = TextEditor(root)
    root.mainloop()
